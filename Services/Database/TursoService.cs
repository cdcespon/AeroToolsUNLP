using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Net.Http.Json;
using System.Text.Json;
using System.Threading.Tasks;
using Microsoft.Extensions.Configuration;
using System.Linq;
using System.Reflection;

namespace AeroToolsUNLP.Services.Database
{
    public class TursoService : ITursoService
    {
        private readonly HttpClient _httpClient;
        private readonly string _authToken;
        private readonly string _dbUrl;

        public TursoService(IHttpClientFactory httpClientFactory, IConfiguration configuration)
        {
            _httpClient = httpClientFactory.CreateClient("TursoApi");
            _dbUrl = configuration["Turso:DatabaseUrl"] ?? "";
            _authToken = configuration["Turso:AuthToken"] ?? "";

            if (!string.IsNullOrEmpty(_dbUrl) && !_dbUrl.StartsWith("https://"))
            {
                 // Ensure valid URL format for HttpClient (remove libsql:// if present)
                 _dbUrl = _dbUrl.Replace("libsql://", "https://");
            }
             if (!string.IsNullOrEmpty(_dbUrl) && !_dbUrl.EndsWith("/v2/pipeline"))
            {
                _dbUrl = _dbUrl.TrimEnd('/') + "/v2/pipeline";
            }
        }

        public async Task<List<T>> ExecuteQuery<T>(string sql, params object[] args) where T : new()
        {
            var response = await SendRequest(sql, args);
            
            var resultList = new List<T>();
            if (response?.Results == null || !response.Results.Any()) return resultList;

            var result = response.Results.First();
            if (result.Rows == null || result.Columns == null) return resultList;

            var properties = typeof(T).GetProperties();
            var columnMap = new Dictionary<string, PropertyInfo>();

            foreach (var prop in properties)
            {
                // Simple mapping: generic property name match (case insensitive)
                columnMap[prop.Name.ToLower()] = prop;
            }

            foreach (var row in result.Rows)
            {
                var item = new T();
                for (int i = 0; i < result.Columns.Count; i++)
                {
                    var colName = result.Columns[i].ToLower();
                    if (columnMap.ContainsKey(colName))
                    {
                        var prop = columnMap[colName];
                        var value = row[i];
                        SetPropertyValue(item, prop, value);
                    }
                }
                resultList.Add(item);
            }

            return resultList;
        }

        public async Task<int> ExecuteNonQuery(string sql, params object[] args)
        {
             var response = await SendRequest(sql, args);
             // Turso doesn't always return affected rows in a standard way in v2 pipeline for all ops, 
             // but we can check for success.
             // For now return 1 if success, 0 if fail/empty.
             return response?.Results?.Count > 0 ? 1 : 0;
        }

        public async Task<T?> ExecuteScalar<T>(string sql, params object[] args)
        {
             var response = await SendRequest(sql, args);
             if (response?.Results == null || !response.Results.Any()) return default;

             var result = response.Results.First();
             if (result.Rows == null || !result.Rows.Any()) return default;

             var value = result.Rows[0][0];
             return (T?)ConvertValue(value, typeof(T));
        }

        private async Task<TursoResponse?> SendRequest(string sql, object[] args)
        {
            var statements = new List<TursoStatement>
            {
                new TursoStatement
                {
                    Query = sql,
                    Params = args.Select(a => a).ToList()
                }
            };

            var requestBody = new TursoRequestWithArgs { Statements = statements };
            
            var request = new HttpRequestMessage(HttpMethod.Post, _dbUrl);
            request.Headers.Authorization = new System.Net.Http.Headers.AuthenticationHeaderValue("Bearer", _authToken);
            request.Content = JsonContent.Create(requestBody);

            var response = await _httpClient.SendAsync(request);
            response.EnsureSuccessStatusCode();

            return await response.Content.ReadFromJsonAsync<TursoResponse>();
        }

        private void SetPropertyValue(object target, PropertyInfo prop, object value)
        {
            if (value == null) return;
            try 
            {
                var convertedValue = ConvertValue(value, prop.PropertyType);
                prop.SetValue(target, convertedValue);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error setting property {prop.Name}: {ex.Message}");
            }
        }

        private object? ConvertValue(object value, Type targetType)
        {
            if (value == null) return null;
            if (value is JsonElement element)
            {
                switch (element.ValueKind)
                {
                    case JsonValueKind.String:
                        var strVal = element.GetString();
                        if (targetType == typeof(DateTime) && DateTime.TryParse(strVal, out var dt)) return dt;
                        if (targetType == typeof(DateTime?) && DateTime.TryParse(strVal, out var dtNullable)) return dtNullable;
                        return Convert.ChangeType(strVal, targetType);
                    case JsonValueKind.Number:
                         if (targetType == typeof(int) || targetType == typeof(int?)) return element.GetInt32();
                         if (targetType == typeof(long) || targetType == typeof(long?)) return element.GetInt64();
                         if (targetType == typeof(double) || targetType == typeof(double?)) return element.GetDouble();
                         if (targetType == typeof(float) || targetType == typeof(float?)) return element.GetSingle();
                         break;
                    case JsonValueKind.True:
                    case JsonValueKind.False:
                        return element.GetBoolean();
                }
            }
             return Convert.ChangeType(value, targetType);
        }
    }
}

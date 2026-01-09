using System.Collections.Generic;
using System.Threading.Tasks;

namespace AeroToolsUNLP.Services.Database
{
    public interface ITursoService
    {
        Task<List<T>> ExecuteQuery<T>(string sql, params object[] args) where T : new();
        Task<int> ExecuteNonQuery(string sql, params object[] args);
        Task<T?> ExecuteScalar<T>(string sql, params object[] args);
    }
}

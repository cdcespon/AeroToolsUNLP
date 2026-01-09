using System.Globalization;
using CsvHelper;
using CsvHelper.Configuration;
using Microsoft.AspNetCore.Components.Forms;

namespace AeroToolsUNLP.Services.Data
{
    public class ImportService
    {
        public async Task<List<WindMeasurement>> ParseWindData(IBrowserFile file)
        {
            var measurements = new List<WindMeasurement>();
            // Max file size 5MB
            using var stream = file.OpenReadStream(5120000);
            using var reader = new StreamReader(stream);
            
            // Allow flexible configuration
            var config = new CsvConfiguration(CultureInfo.InvariantCulture)
            {
                HasHeaderRecord = true,
                MissingFieldFound = null,
                HeaderValidated = null,
            };

            using var csv = new CsvReader(reader, config);
            
            // We read dynamically or expect specific columns. 
            // Let's try to be flexible: look for "Speed", "Vel", "Direction", "Dir" case insensitive
            
            var records = csv.GetRecordsAsync<dynamic>();

            await foreach (var record in records)
            {
                var dict = (IDictionary<string, object>)record;
                double speed = -1;
                double direction = -1;

                foreach (var key in dict.Keys)
                {
                    var k = key.ToLower();
                    var valStr = dict[key]?.ToString();
                    
                    if (string.IsNullOrWhiteSpace(valStr)) continue;
                    
                    if (double.TryParse(valStr, NumberStyles.Any, CultureInfo.InvariantCulture, out var val))
                    {
                        if (k.Contains("speed") || k.Contains("vel") || k.Contains("viento"))
                            speed = val;
                        else if (k.Contains("dir") || k.Contains("rumbo") || k.Contains("deg"))
                            direction = val;
                    }
                }

                if (speed >= 0 && direction >= 0)
                {
                    measurements.Add(new WindMeasurement { Speed = speed, Direction = direction });
                }
            }

            return measurements;
        }
    }

    public class WindMeasurement
    {
        public double Speed { get; set; } // m/s preferred
        public double Direction { get; set; } // degrees (0-360)
    }
}

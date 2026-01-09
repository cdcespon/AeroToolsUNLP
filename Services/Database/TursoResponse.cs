using System.Collections.Generic;
using System.Text.Json.Serialization;

namespace AeroToolsUNLP.Services.Database
{
    public class TursoResponse
    {
        [JsonPropertyName("results")]
        public List<TursoResult> Results { get; set; } = new();
    }

    public class TursoResult
    {
        [JsonPropertyName("columns")]
        public List<string> Columns { get; set; } = new();

        [JsonPropertyName("rows")]
        public List<List<object>> Rows { get; set; } = new();

        [JsonPropertyName("response")]
        public TursoResultMetadata? Response { get; set; }
    }

    public class TursoResultMetadata
    {
        [JsonPropertyName("type")]
        public string Type { get; set; } = string.Empty;
    }
    
    public class TursoRequest
    {
        [JsonPropertyName("statements")]
        public List<string> Statements { get; set; } = new();
    }
    
     public class TursoRequestWithArgs
    {
        [JsonPropertyName("statements")]
        public List<TursoStatement> Statements { get; set; } = new();
    }

    public class TursoStatement
    {
        [JsonPropertyName("q")]
        public string Query { get; set; } = string.Empty;

        [JsonPropertyName("params")]
        public List<object?> Params { get; set; } = new();
    }
}

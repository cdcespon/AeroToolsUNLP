using System;

namespace AeroToolsUNLP.Models.Core
{
    public class Usuario
    {
        public int Id { get; set; }
        public string Legajo { get; set; } = string.Empty;
        public string? Nombre { get; set; }
        public string Tipo { get; set; } = "alumno";
        public string? Email { get; set; }
        public string? Carrera { get; set; }
        public int? AñoIngreso { get; set; }
        public DateTime PrimeraVisita { get; set; }
        public DateTime UltimaActividad { get; set; }
        public int TotalCalculos { get; set; }
    }
}

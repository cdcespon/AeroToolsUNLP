namespace AeroToolsUNLP.Utils
{
    public static class UnitConverter
    {
        // Length
        public static double MetersToFeet(double meters) => meters * 3.28084;
        public static double FeetToMeters(double feet) => feet / 3.28084;
        public static double KmToNauticalMiles(double km) => km * 0.539957;
        public static double NauticalMilesToKm(double nm) => nm / 0.539957;

        // Speed
        public static double MpsToKnots(double mps) => mps * 1.94384;
        public static double KnotsToMps(double knots) => knots / 1.94384;
        public static double KphToKnots(double kph) => kph * 0.539957;

        // Temperature
        public static double CelsiusToKelvin(double c) => c + 273.15;
        public static double KelvinToCelsius(double k) => k - 273.15;
        public static double CelsiusToFahrenheit(double c) => (c * 9.0 / 5.0) + 32;

        // Pressure
        public static double PascalToHPa(double pa) => pa / 100.0;
        public static double HPaToPascal(double hpa) => hpa * 100.0;
        public static double HPaToInHg(double hpa) => hpa * 0.02953;

        // Force
        public static double NewtonsToLbf(double n) => n * 0.224809;
        
        // Generic convert
        public static double Convert(double value, string fromUnit, string toUnit)
        {
            // Simplified logic, better to use dedicated methods
            if (fromUnit == toUnit) return value;
            
            // Example map... in real app use dictionary or smarter pattern
            if (fromUnit == "m" && toUnit == "ft") return MetersToFeet(value);
            if (fromUnit == "ft" && toUnit == "m") return FeetToMeters(value);
            
            return value; // Fallback
        }
    }
}

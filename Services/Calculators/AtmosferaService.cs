using System;

namespace AeroToolsUNLP.Services.Calculators
{
    public class AtmosferaService
    {
        // ISA Constants
        private const double g = 9.80665; // m/s^2
        private const double R = 287.05; // J/(kg*K)
        private const double P0 = 101325; // Pa
        private const double T0 = 288.15; // K
        private const double Rho0 = 1.225; // kg/m^3
        private const double L = 0.0065; // K/m (Lapse rate in Troposphere)
        private const double H_Trop = 11000; // m (Tropopause altitude)

        public AtmosphereResult Calculate(double altitudeMeters, double deltaTempC = 0)
        {
            double T_isa, P, Rho;
            
            // Troposphere Model (up to 11km)
            // Simplified for this tool, assuming mostly tropospheric flight for students
            if (altitudeMeters <= H_Trop)
            {
                T_isa = T0 - L * altitudeMeters;
                P = P0 * Math.Pow(1 - (L * altitudeMeters) / T0, (g / (R * L)));
            }
            else
            {
                // Stratosphere (isothermal up to 20km approx)
                double P_trop = P0 * Math.Pow(1 - (L * H_Trop) / T0, (g / (R * L)));
                double T_trop = T0 - L * H_Trop; // 216.65 K
                T_isa = T_trop;
                
                // P = P1 * exp(-(g/(RT))*(h-h1))
                P = P_trop * Math.Exp(-(g / (R * T_trop)) * (altitudeMeters - H_Trop));
            }

            // Apply non-standard temperature offset
            double T_final = T_isa + deltaTempC;

            // Density using ideal gas law with final T
            // Note: Pressure is largely determining by the mass of air above, which doesn't change 
            // significantly with local temp variation in this simplified model, 
            // usually P altitude relation is kept ISA for altimetry, checking density altitude is the goal.
            // But often in engineering P is assumed ISA, T is ISA+Delta, calculating Rho.
            Rho = P / (R * T_final);

            // Speed of sound a = sqrt(gamma * R * T)
            double a = Math.Sqrt(1.4 * R * T_final);

            return new AtmosphereResult
            {
                Altitude = altitudeMeters,
                TemperatureK = T_final,
                TemperatureC = T_final - 273.15,
                PressurePa = P,
                Density = Rho,
                SpeedOfSound = a,
                RelativeDensity = Rho / Rho0,
                RelativePressure = P / P0,
                DeltaISA = deltaTempC
            };
        }
    }

    public class AtmosphereResult
    {
        public double Altitude { get; set; } // m
        public double TemperatureK { get; set; }
        public double TemperatureC { get; set; }
        public double PressurePa { get; set; }
        public double Density { get; set; } // kg/m^3
        public double SpeedOfSound { get; set; } // m/s
        public double RelativeDensity { get; set; } // sigma
        public double RelativePressure { get; set; } // delta
        public double DeltaISA { get; set; }
    }
}

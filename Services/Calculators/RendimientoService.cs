using System;

namespace AeroToolsUNLP.Services.Calculators
{
    public class RendimientoService
    {
        // Breguet Range Equation (Propeller)
        // Range = (eta * E / c) * ln(W0 / W1)
        // eta: propeller efficiency
        // E: Lift/Drag ratio (L/D)
        // c: specific fuel consumption (SFC)
        // W0: Initial Weight
        // W1: Final Weight
        public double CalculateRangePropeller(double eta, double ldRatio, double sfc, double w0, double w1)
        {
            if (sfc <= 0 || w1 <= 0 || w0 <= 0) return 0;
            return (eta / sfc) * ldRatio * Math.Log(w0 / w1);
            // Units note: verify consistency. 
            // If SFC is in 1/m (e.g. N/N/m? No, usually lb/hp/hr or kg/kW/hr). 
            // Need standardized units. 
            // Let's assume standardized metric input for now or provide unit conversion in UI.
            // Simplified formula usually: R = (efficiency/SFC) * (L/D) * ln(Wi/Wf)
        }

        // Rate of Climb (RoC)
        // RoC = (PowerAvailable - PowerRequired) / Weight
        public double CalculateRateOfClimb(double powerAvailable, double powerRequired, double weight)
        {
            if (weight <= 0) return 0;
            return (powerAvailable - powerRequired) / weight;
        }

        // Gliding Distance
        // D = h * (L/D)
        public double CalculateGlidingDistance(double height, double ldRatio)
        {
            return height * ldRatio;
        }
        
        // Stall Speed (Vs)
        // Vs = sqrt( (2 * W) / (rho * S * CL_max) )
        public double CalculateStallSpeed(double weight, double density, double surfaceArea, double clMax)
        {
            if (density <= 0 || surfaceArea <= 0 || clMax <= 0) return 0;
            return Math.Sqrt((2 * weight) / (density * surfaceArea * clMax));
        }

        // Bank Angle for Turn
        // tan(phi) = v^2 / (g * R) -> R = v^2 / (g * tan(phi))
        public double CalculateTurnRadius(double velocity, double bankAngleDeg)
        {
            double g = 9.81;
            double phiRad = bankAngleDeg * Math.PI / 180.0;
            if (Math.Abs(Math.Tan(phiRad)) < 0.001) return double.PositiveInfinity;
            
            return (velocity * velocity) / (g * Math.Tan(phiRad));
        }
    }
}

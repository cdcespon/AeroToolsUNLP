using System;

namespace AeroToolsUNLP.Services.Calculators
{
    public class MotoresService
    {
        // Turbojet Ideal Thrust
        // T = m_dot * (V_exit - V_inlet) + (P_exit - P_ambient) * A_exit
        public double CalculateTurbojetThrust(double massFlow, double vExit, double vInlet, double pExit, double pAmbient, double aExit)
        {
            return massFlow * (vExit - vInlet) + (pExit - pAmbient) * aExit;
        }

        // Propulsive Efficiency (eta_p)
        // eta_p = 2 * V_flight / (V_exit + V_flight)
        public double CalculatePropulsiveEfficiency(double vFlight, double vExit)
        {
            if (vExit + vFlight == 0) return 0;
            return (2 * vFlight) / (vExit + vFlight);
        }

        // Specific Fuel Consumption (TSFC) for Turbojets
        // TSFC = FuelFlow / Thrust
        public double CalculateTSFC(double fuelFlow, double thrust)
        {
            if (thrust <= 0) return 0;
            return fuelFlow / thrust;
        }

        // Brayton Cycle Efficiency (Ideal)
        // eta = 1 - (rp)^((1-gamma)/gamma)
        // rp: pressure ratio
        // gamma: heat capacity ratio (typ 1.4)
        public double CalculateBraytonEfficiency(double pressureRatio, double gamma = 1.4)
        {
            if (pressureRatio <= 0) return 0;
            return 1 - Math.Pow(pressureRatio, (1 - gamma) / gamma);
        }
    }
}

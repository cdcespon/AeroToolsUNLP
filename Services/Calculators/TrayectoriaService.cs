using System;
using System.Collections.Generic;

namespace AeroToolsUNLP.Services.Calculators
{
    public class TrayectoriaService
    {
        private const double G = 9.81;

        public List<SimulationState> SimulateTrajectory(SimulationParameters startParams, double timeStep = 0.1, double maxTime = 600)
        {
            var trajectory = new List<SimulationState>();
            var state = new SimulationState
            {
                Time = 0,
                X = 0, // Assume start relative 0,0 for local physics, map to lat/lon later
                Y = 0,
                Z = startParams.InitialHeight,
                Vx = startParams.InitialVelocity * Math.Cos(DegToRad(startParams.InitialAngle)),
                Vy = 0, // 2D profile for simplicity
                Vz = startParams.InitialVelocity * Math.Sin(DegToRad(startParams.InitialAngle)),
                Mass = startParams.Mass
            };

            trajectory.Add(state);

            double t = 0;
            while (t < maxTime && state.Z >= 0)
            {
                // RK4 Integration for X, Y, Z, Vx, Vy, Vz
                
                // k1
                var k1 = Derivatives(state, t);
                
                // k2
                var stateK2 = state + (k1 * (timeStep / 2));
                stateK2.Time = t + timeStep / 2;
                var k2 = Derivatives(stateK2, t + timeStep / 2);

                // k3
                var stateK3 = state + (k2 * (timeStep / 2));
                stateK3.Time = t + timeStep / 2;
                var k3 = Derivatives(stateK3, t + timeStep / 2);

                // k4
                var stateK4 = state + (k3 * timeStep);
                stateK4.Time = t + timeStep;
                var k4 = Derivatives(stateK4, t + timeStep);

                // Final Update
                state = state + ((k1 + k2 * 2 + k3 * 2 + k4) * (timeStep / 6.0));
                
                t += timeStep;
                state.Time = t;
                
                trajectory.Add(state);
            }

            return trajectory;
        }

        private StateDerivatives Derivatives(SimulationState s, double t)
        {
            // Forces
            double rho = 1.225 * Math.Pow(1 - 0.0000225577 * s.Z, 4.25588); // Simple ISA Troposphere approx
            if (rho < 0) rho = 0;

            double vSq = s.Vx * s.Vx + s.Vy * s.Vy + s.Vz * s.Vz;
            double v = Math.Sqrt(vSq);
            
            // Drag = 0.5 * rho * V^2 * Cd * A
            double drag = 0.5 * rho * vSq * 0.05 * 1.0; // Dummy Cd=0.05, A=1.0 for demo
            
            // Drag components
            double fx = 0;
            double fy = 0;
            double fz = -s.Mass * G;

            if (v > 0)
            {
                fx -= drag * (s.Vx / v);
                fy -= drag * (s.Vy / v);
                fz -= drag * (s.Vz / v);
            }

            return new StateDerivatives
            {
                Dx = s.Vx,
                Dy = s.Vy,
                Dz = s.Vz,
                Dvx = fx / s.Mass,
                Dvy = fy / s.Mass,
                Dvz = fz / s.Mass
            };
        }
        
        private double DegToRad(double deg) => deg * Math.PI / 180.0;
    }

    public struct SimulationState
    {
        public double Time;
        public double X, Y, Z;
        public double Vx, Vy, Vz;
        public double Mass;

        public static SimulationState operator +(SimulationState a, StateDerivatives b)
        {
            return new SimulationState
            {
                X = a.X + b.Dx,
                Y = a.Y + b.Dy,
                Z = a.Z + b.Dz,
                Vx = a.Vx + b.Dvx,
                Vy = a.Vy + b.Dvy,
                Vz = a.Vz + b.Dvz,
                Mass = a.Mass
            };
        }
    }

    public struct StateDerivatives
    {
        public double Dx, Dy, Dz;
        public double Dvx, Dvy, Dvz;

        public static StateDerivatives operator *(StateDerivatives a, double scalar)
        {
            return new StateDerivatives
            {
                Dx = a.Dx * scalar,
                Dy = a.Dy * scalar,
                Dz = a.Dz * scalar,
                Dvx = a.Dvx * scalar,
                Dvy = a.Dvy * scalar,
                Dvz = a.Dvz * scalar
            };
        }
        
        public static StateDerivatives operator +(StateDerivatives a, StateDerivatives b)
        {
             return new StateDerivatives
            {
                Dx = a.Dx + b.Dx,
                Dy = a.Dy + b.Dy,
                Dz = a.Dz + b.Dz,
                Dvx = a.Dvx + b.Dvx,
                Dvy = a.Dvy + b.Dvy,
                Dvz = a.Dvz + b.Dvz
            };
        }
    }

    public class SimulationParameters
    {
        public double InitialVelocity { get; set; }
        public double InitialAngle { get; set; }
        public double InitialHeight { get; set; }
        public double Mass { get; set; }
    }
}

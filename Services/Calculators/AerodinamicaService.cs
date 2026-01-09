using System;
using System.Collections.Generic;

namespace AeroToolsUNLP.Services.Calculators
{
    public class AerodinamicaService
    {
        public AerodynamicProfile GenerateNaca4(string designation, int points = 100)
        {
            if (string.IsNullOrEmpty(designation) || designation.Length != 4)
                throw new ArgumentException("Invalid NACA designation. Must be 4 digits.");

            double maxCamber = double.Parse(designation.Substring(0, 1)) / 100.0; // M
            double maxCamberPos = double.Parse(designation.Substring(1, 1)) / 10.0; // P
            double thickness = double.Parse(designation.Substring(2, 2)) / 100.0; // T

            var profile = new AerodynamicProfile();
            
            for (int i = 0; i <= points; i++)
            {
                // Beta distribution of points (Cosine spacing) for better LE definiton
                double beta = (double)i / points * Math.PI;
                double x = (1 - Math.Cos(beta)) / 2.0;
                
                // Thickness distribution
                double yt = 5 * thickness * (
                    0.2969 * Math.Sqrt(x) -
                    0.1260 * x -
                    0.3516 * Math.Pow(x, 2) +
                    0.2843 * Math.Pow(x, 3) -
                    0.1015 * Math.Pow(x, 4)
                );

                // Camber line
                double yc = 0;
                double dyc_dx = 0;

                if (maxCamber > 0)
                {
                    if (x < maxCamberPos)
                    {
                        yc = (maxCamber / Math.Pow(maxCamberPos, 2)) * (2 * maxCamberPos * x - Math.Pow(x, 2));
                        dyc_dx = (2 * maxCamber / Math.Pow(maxCamberPos, 2)) * (maxCamberPos - x);
                    }
                    else
                    {
                        yc = (maxCamber / Math.Pow(1 - maxCamberPos, 2)) * ((1 - 2 * maxCamberPos) + 2 * maxCamberPos * x - Math.Pow(x, 2));
                        dyc_dx = (2 * maxCamber / Math.Pow(1 - maxCamberPos, 2)) * (maxCamberPos - x);
                    }
                }

                double theta = Math.Atan(dyc_dx);
                
                // Upper Surface
                double xu = x - yt * Math.Sin(theta);
                double yu = yc + yt * Math.Cos(theta);
                
                // Lower Surface
                double xl = x + yt * Math.Sin(theta);
                double yl = yc - yt * Math.Cos(theta);
                
                profile.UpperSurface.Add(new Point2D(xu, yu));
                profile.LowerSurface.Add(new Point2D(xl, yl));
            }

            return profile;
        }

        // Extrude profile to 3D vertices for Three.js
        public (float[] vertices, int[] indices) ExtrudeProfile(AerodynamicProfile profile, double span = 1.0)
        {
            var vertices = new List<float>();
            var indices = new List<int>();
            
            // Simplified logic: 
            // 1. Combine upper (reversed) and lower to get a loop
            // 2. Create front face vertices, back face vertices
            // 3. Triangulate
            
            // For this demo, let's just return a line loop of the profile at z=0 and z=span for visualization
            // Or simple mesh.
            // Let's implement full mesh later if needed, assume line loop for simplicity first iteration.
            
            // Actually ThreeHelpers logic implemented supports vertices loop. 
            // Let's populate vertices array for a line loop (Upper + Lower reversed)
            
             foreach(var p in profile.UpperSurface)
            {
                vertices.Add((float)(p.X - 0.5)); // Center X
                vertices.Add((float)p.Y);
                vertices.Add(0);
            }
            // Add lower surface in reverse order to close loop
             for(int i = profile.LowerSurface.Count - 1; i >= 0; i--)
            {
                var p = profile.LowerSurface[i];
                vertices.Add((float)(p.X - 0.5));
                vertices.Add((float)p.Y);
                vertices.Add(0);
            }
            
            return (vertices.ToArray(), null);
        }
    }

    public class AerodynamicProfile
    {
        public List<Point2D> UpperSurface { get; set; } = new();
        public List<Point2D> LowerSurface { get; set; } = new();
    }
    
    public record Point2D(double X, double Y);
}

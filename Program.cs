using Microsoft.AspNetCore.Components.Web;
using Microsoft.AspNetCore.Components.WebAssembly.Hosting;
using AeroToolsUNLP;
using Blazored.LocalStorage;
using Microsoft.Extensions.DependencyInjection;
using AeroToolsUNLP.Services.Database;
using AeroToolsUNLP.Services.Auth;

var builder = WebAssemblyHostBuilder.CreateDefault(args);
builder.RootComponents.Add<App>("#app");
builder.RootComponents.Add<HeadOutlet>("head::after");

builder.Services.AddBlazoredLocalStorage();

builder.Services.AddScoped(sp => new HttpClient { BaseAddress = new Uri(builder.HostEnvironment.BaseAddress) });

// Turso HttpClient configuration
builder.Services.AddHttpClient("TursoApi", client =>
{
    // Base address will be set in TursoService using configuration
});

builder.Services.AddScoped<ITursoService, TursoService>();
builder.Services.AddScoped<IAuthService, AuthService>();
builder.Services.AddScoped<AeroToolsUNLP.Services.Calculators.AtmosferaService>();
builder.Services.AddScoped<AeroToolsUNLP.Services.Calculators.GeometriaService>();
builder.Services.AddScoped<AeroToolsUNLP.Services.Data.ImportService>();
builder.Services.AddScoped<AeroToolsUNLP.Services.Calculators.RendimientoService>();
builder.Services.AddScoped<AeroToolsUNLP.Services.Calculators.AerodinamicaService>();
builder.Services.AddScoped<AeroToolsUNLP.Services.Calculators.TrayectoriaService>();
builder.Services.AddScoped<AeroToolsUNLP.Services.Calculators.MotoresService>();

await builder.Build().RunAsync();

using System;
using System.Threading.Tasks;
using Blazored.LocalStorage;
using AeroToolsUNLP.Models.Core;
using AeroToolsUNLP.Services.Database;

namespace AeroToolsUNLP.Services.Auth
{
    public class AuthService : IAuthService
    {
        private readonly ITursoService _tursoService;
        private readonly ILocalStorageService _localStorage;
        private const string USER_KEY = "aerotools_user";

        public AuthService(ITursoService tursoService, ILocalStorageService localStorage)
        {
            _tursoService = tursoService;
            _localStorage = localStorage;
        }

        public async Task<bool> RegistrarUsuario(Usuario usuario)
        {
            // Validar si existe
            var existing = await _tursoService.ExecuteScalar<int>("SELECT COUNT(*) FROM usuarios WHERE legajo = ?", usuario.Legajo);
            if (existing > 0) return false;

            // Insertar
            string sql = "INSERT INTO usuarios (legajo, nombre, tipo, email, carrera, año_ingreso) VALUES (?, ?, ?, ?, ?, ?)";
            await _tursoService.ExecuteNonQuery(sql, usuario.Legajo, usuario.Nombre, usuario.Tipo, usuario.Email, usuario.Carrera, usuario.AñoIngreso);

            // Fetch created user to get ID
            await IniciarSesion(usuario.Legajo);
            return true;
        }

        public async Task<bool> IniciarSesion(string legajo)
        {
            var userList = await _tursoService.ExecuteQuery<Usuario>("SELECT * FROM usuarios WHERE legajo = ?", legajo);
            if (userList == null || userList.Count == 0) return false;

            var user = userList[0];
            await _localStorage.SetItemAsync(USER_KEY, user);
            
            // Update activity async
            _ = ActualizarActividadInDb(user.Id);
            
            return true;
        }

        public async Task<Usuario?> ObtenerUsuarioActual()
        {
            return await _localStorage.GetItemAsync<Usuario>(USER_KEY);
        }

        public async Task CerrarSesion()
        {
            await _localStorage.RemoveItemAsync(USER_KEY);
        }

        public async Task ActualizarActividad()
        {
            var user = await ObtenerUsuarioActual();
            if (user != null)
            {
                await ActualizarActividadInDb(user.Id);
            }
        }

        private async Task ActualizarActividadInDb(int userId)
        {
            await _tursoService.ExecuteNonQuery("UPDATE usuarios SET ultima_actividad = CURRENT_TIMESTAMP WHERE id = ?", userId);
        }
    }
}

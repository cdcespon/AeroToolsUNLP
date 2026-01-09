using System.Threading.Tasks;
using AeroToolsUNLP.Models.Core;

namespace AeroToolsUNLP.Services.Auth
{
    public interface IAuthService
    {
        Task<bool> RegistrarUsuario(Usuario usuario);
        Task<bool> IniciarSesion(string legajo);
        Task<Usuario?> ObtenerUsuarioActual();
        Task CerrarSesion();
        Task ActualizarActividad();
    }
}

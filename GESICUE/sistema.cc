#include <iostream>
#include <string>
#include <vector>

#include "usuario/usuario.h"
#include "profesor/profesor.h"
#include "solicitud/solicitud.h"

// Crear usuarios predefinidos
std::vector<Usuario*> crearUsuariosFijos() {
    return {
        new Usuario("Admin", "12345678A", "admin@gmail.com", "admin123"),
        new Profesor("Profesor Uno", "87654321B", "profesor@gmail.com", "prof123", "Matemáticas"),
        new Usuario("Alumno Uno", "11223344C", "alumno@gmail.com", "alumno123")
    };
}

// Función para autenticar al usuario
Usuario* autenticar(std::vector<Usuario*>& usuarios, const std::string& email, const std::string& contraseña) {
    for (auto& usuario : usuarios) {
        if (usuario->getCorreo() == email && usuario->iniciarSesion(email, contraseña)) {
            return usuario;
        }
    }
    return nullptr;
}

// Menú para administrador
void menuAdministrador() {
    std::cout << "\n--- Menú Administrador ---\n";
    std::cout << "1. Agregar usuario\n";
    std::cout << "2. Eliminar usuario\n";
    std::cout << "3. Listar usuarios\n";
    std::cout << "4. Salir\n";
}

// Menú para profesor
void menuProfesor(Profesor* profesor) {
    int opcion;
    Solicitud solicitudprofesor("", "", "", "", "", "");  // Crear solicitud vacía al inicio

    while (true) {
        std::cout << "\n--- Menú Profesor ---\n";
        std::cout << "1. Enviar solicitud\n";
        std::cout << "2. Cancelar solicitud\n";
        std::cout << "3. Consultar estado de solicitud\n";
        std::cout << "4. Salir\n";
        std::cout << "\n";

        std::cin >> opcion;
        std::cout << "\n";
        switch (opcion) {
            case 1: {
                // Solicitar los datos de la solicitud por terminal
                std::string universidadOrigen, universidadDestino, fechaInicio, fechaFin;

                std::cout << "Ingrese la universidad de origen: ";
                std::cin >> universidadOrigen;

                std::cout << "Ingrese la universidad destino: ";
                std::cin >> universidadDestino;

                std::cout << "Ingrese la fecha de inicio del periodo (YYYY-MM-DD): ";
                std::cin >> fechaInicio;

                std::cout << "Ingrese la fecha de fin del periodo (YYYY-MM-DD): ";
                std::cin >> fechaFin;

                // Crear la solicitud sin la fecha de envío (que se asignará en enviarSolicitud)
                solicitudprofesor = Solicitud("Pendiente", "", universidadOrigen, universidadDestino, fechaInicio, fechaFin);

                // Llamar a enviarSolicitud, pasándole la solicitud creada
                profesor->enviarSolicitud(solicitudprofesor);

                std::cout << "Solicitud enviada.\n";
                break;
            }
            case 2:
                profesor->cancelarSolicitud();
                std::cout << "Solicitud cancelada.\n";
                break;
            case 3:
                // Consultar estado de la solicitud
                profesor->consultarEstadoSolicitud(solicitudprofesor);  // Consulta el estado de la solicitud
                break;
            case 4:
                std::cout << "Saliendo del menú Profesor.\n";
                return;  // Salir del menú
            default:
                std::cout << "Opción no válida.\n";
        }
    }
}

// Menú para alumno
void menuAlumno() {
    int opcion;
    std::cout << "\n--- Menú Alumno ---\n";
    std::cout << "1. Ver estado de solicitud\n";
    std::cout << "2. Salir\n";
    std::cout << "\n";

    std::cin >> opcion;
    std::cout << "\n";

    switch (opcion) {
        case 1:
            std::cout << "Consultando estado de solicitud...\n";
            // Aquí iría la lógica de consulta de estado de la solicitud
            break;
        case 2:
            std::cout << "Saliendo del menú Alumno.\n";
            break;
        default:
            std::cout << "Opción no válida.\n";
    }
}

int main() {
    // Crear usuarios fijos
    std::vector<Usuario*> usuarios = crearUsuariosFijos();

    // Autenticación
    std::string email, contraseña;
    std::cout << "Ingrese su correo: ";
    std::cin >> email;
    std::cout << "\n";
    std::cout << "Ingrese su contraseña: ";
    std::cin >> contraseña;
    std::cout << "\n";

    Usuario* usuarioAutenticado = autenticar(usuarios, email, contraseña);

    if (!usuarioAutenticado) {
        std::cerr << "Credenciales incorrectas. Acceso denegado." << std::endl;
        return 1;
    }

    // Menús según el tipo de usuario
    Profesor* profesor = dynamic_cast<Profesor*>(usuarioAutenticado);
    if (profesor) {
        menuProfesor(profesor);
    } else if (usuarioAutenticado->getCorreo() == "alumno@example.com") {
        menuAlumno();
    } else {
        menuAdministrador();
    }

    // Liberar memoria
    for (auto usuario : usuarios) {
        delete usuario;
    }

    return 0;
}

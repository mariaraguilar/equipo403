#include <iostream>
#include <string>
#include <vector>
#include "usuario/usuario.h"
#include "profesor/profesor.h"
#include "solicitud/solicitud.h"
#include "planconvalidacion/PlanConvalidacion.h"
#include "asignatura/asignatura.h"
#include "carrera/carrera.h"
#include "administrador/administrador.h"

// Crear usuarios predefinidos
std::vector<Usuario*> crearUsuariosFijos() {
    return {
        new Administrador("Admin", "12345678A", "admin@gmail.com", "admin123"),
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
void menuAdministrador(Administrador* administrador, bool& continuar) {
    int opcion;
    Carrera carrera("Matemáticas", "12345");  // Crear una instancia de Carrera

    PlanConvalidacion planconvalidacion1(
        "Pendiente", "2024-12-11", "Universidad Origen", "Universidad Destino", 
        "2024-02-01", "2024-06-30", "Matemáticas", carrera, 5 // Crear el plan con 'carrera'
    );

    while (true) {
        std::cout << "\n--- Menú Administrador ---\n";
        std::cout << "1. Crear plan de convalidación.\n";
        std::cout << "2. Anular plan de convalidación.\n";
        std::cout << "3. Acceder a las solicitudes.\n";
        std::cout << "4. Generar listado final.\n";
        std::cout << "5. Generar notificaciones.\n";
        std::cout << "6. Salir\n";
        std::cout << "\n";

        std::cin >> opcion;
        std::cout << "\n";

        switch (opcion) {
            case 1: {
                // Solicitar datos para crear un nuevo plan de convalidación
                std::string universidadOrigen, universidadDestino, nombreasignatura, nombrecarrera;
                int ncreditos;

                std::cout << "Ingrese la universidad de origen: ";
                std::cin >> universidadOrigen;

                std::cout << "Ingrese la universidad destino: ";
                std::cin >> universidadDestino;

                std::cout << "Ingrese el nombre de las asignaturas convalidadas: ";
                std::cin >> nombreasignatura;

                std::cout << "Ingrese el nombre de la carrera: ";
                std::cin >> nombrecarrera;

                std::cout << "Ingrese el numero de creditos que le corresponden: ";
                std::cin >> ncreditos;

                // Crear una instancia de Carrera con los datos proporcionados
                Carrera carrera(nombrecarrera, "codigo_placeholder");

                // Crear el plan de convalidación
                planconvalidacion1 = PlanConvalidacion("Pendiente", "2024-12-11", universidadOrigen, universidadDestino, "2024-02-01", "2024-06-30", nombreasignatura, carrera, ncreditos);

                // Guardar el plan de convalidación
                planconvalidacion1.guardarPlanConvalidacion(planconvalidacion1);
                break;
            }
            case 2:
                std::cout << "Anulando plan de convalidación ...\n";
                break;
            case 3:
                std::cout << "Accediendo a las solicitudes...\n";
                break;
            case 4:
                std::cout << "Generando listado final...\n";
                break;
            case 5:
                std::cout << "Generando notificaciones...\n";
                break;
            case 6:
                std::cout << "Cerrando sesión y saliendo del sistema...\n";
                exit(-1);
            default:
                std::cout << "Opción no válida. Por favor, intente nuevamente.\n";
        }
    }
}

// Menú para profesor
void menuProfesor(Profesor* profesor, bool& continuar) {
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
                break;
            }
            case 2:
                profesor->cancelarSolicitud();
                break;
            case 3:
                // Consultar estado de la solicitud
                profesor->consultarEstadoSolicitud(solicitudprofesor);  // Consulta el estado de la solicitud
                break;
            case 4:
                std::cout << "Cerrando sesión y saliendo del sistema...\n";
                exit(-1);
            default:
                std::cout << "Opción no válida.\n";
        }
    }
}


// Menú para alumno
void consultarPlanesConvalidacion() {
    std::cout << "\n--- Planes de Convalidación Disponibles ---\n";

    std::cout << "Universidad Origen: Córdoba \n";
    std::cout << "Universidad Destino: Sevilla \n";
    std::cout << "Nombre de las asignaturas convalidadas: Cálculo, Matemáticas, Química, Electrotecnia, Informática, Física \n";
    std::cout << "Nombre de la carrera: Ingeniería Mecánica \n";
    std::cout << "Número de créditos: 6 \n\n";

    std::cout << "Universidad Origen: Córdoba \n";
    std::cout << "Universidad Destino: Madrid \n";
    std::cout << "Nombre de las asignaturas convalidadas: Matemáticas, Química orgánica, Química inorgánica, Flujos, Biología \n";
    std::cout << "Nombre de la carrera: Química \n";
    std::cout << "Número de créditos: 6 \n\n";

    std::cout << "Universidad Origen: Córdoba \n";
    std::cout << "Universidad Destino: Zaragoza \n";
    std::cout << "Nombre de las asignaturas convalidadas: Base de datos, Ingeniería del Software, AC, Sistemas Operativos, POO \n";
    std::cout << "Nombre de la carrera: Ingeniería Informática \n";
    std::cout << "Número de créditos: 6 \n\n";
}

void menuAlumno(bool& continuar) {
    int opcion;

    while (continuar) {
        std::cout << "\n--- Menú Alumno ---\n";
        std::cout << "1. Consultar planes de convalidación\n";
        std::cout << "2. Enviar solicitud SICUE\n";
        std::cout << "3. Anular solicitud SICUE\n";
        std::cout << "4. Consultar estado de solicitud\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opción: ";
        
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                consultarPlanesConvalidacion();
                break;

            case 2:
                std::cout << "Enviando solicitud SICUE...\n";
                break;

            case 3:
                std::cout << "Anulando solicitud SICUE...\n";
                break;

            case 4:
                std::cout << "Consultando estado de la solicitud SICUE...\n";
                break;

            case 5:
                std::cout << "Cerrando sesión y saliendo del sistema...\n";
                exit(-1);

            default:
                std::cout << "Opción no válida. Por favor, intente de nuevo.\n";
        }
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

        std::cout << "¿Desea restablecer la contraseña? (s/n): ";
        char opcion;
        std::cin >> opcion;

        if (opcion == 's' || opcion == 'S') {
            std::cout << "Enviando instrucciones de restablecimiento de contraseña a su correo..." << std::endl;
        } else {
            std::cout << "Acceso denegado." << std::endl;
        }
        return 1; // Termina el programa si no hay autenticación exitosa
    }


    bool continuar = true; // Bandera para controlar si continuar o salir

    // Menús según el tipo de usuario
    Profesor* profesor = dynamic_cast<Profesor*>(usuarioAutenticado);
    if (profesor) {
        menuProfesor(profesor, continuar);
    }

    Administrador* administrador = dynamic_cast<Administrador*>(usuarioAutenticado);
    if (administrador) {
        menuAdministrador(administrador, continuar);
    }

    Usuario* alumno = dynamic_cast<Usuario*>(usuarioAutenticado);
    if (alumno) {
        menuAlumno(continuar);
    }

    // Si se desea salir del sistema, se termina el programa
    if (!continuar) {
        std::cout << "Cerrando sesión y saliendo del sistema...\n";
    }

    return 0;
}

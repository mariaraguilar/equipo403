#include "alumno.h"
#include "solicitud.h"
#include <iostream>
#include <cassert>

int main() {
    // Crear dos objetos Alumno con carrera
    Alumno alumno1("Maria del Monte", "12345678B", "m.delmonte@gmail.com", "password124", "Ingeniería Informática");
    Alumno alumno2("Isabel Pantoja", "87654321C", "pantoja@gmail.com", "password457", "Administración y Dirección de Empresas");

    // Crear dos Solicitudes
    Solicitud solicitud1("Pendiente", "2024-12-11", "Universidad A", "Universidad B", "2024-02-01", "2024-06-30");
    Solicitud solicitud2("Pendiente", "2024-12-11", "Universidad C", "Universidad D", "2024-03-01", "2024-07-31");

    // Enviar solicitudes
    std::cout << "Enviando solicitud de Maria del Monte...\n";
    alumno1.enviarSolicitud(solicitud1);
    
    std::cout << "Enviando solicitud de Isabel Pantoja...\n";
    alumno2.enviarSolicitud(solicitud2);

    // Consultar el estado de las solicitudes
    std::cout << "\nConsultando estado de la solicitud de Maria del Monte...\n";
    alumno1.consultarEstadoSolicitud(solicitud1);

    std::cout << "\nConsultando estado de la solicitud de Isabel Pantoja...\n";
    alumno2.consultarEstadoSolicitud(solicitud2);

    // Cancelar solicitudes
    std::cout << "\nCancelando solicitud de Maria del Monte...\n";
    alumno1.cancelarSolicitud();

    std::cout << "\nCancelando solicitud de Isabel Pantoja...\n";
    alumno2.cancelarSolicitud();

    return 0;
}

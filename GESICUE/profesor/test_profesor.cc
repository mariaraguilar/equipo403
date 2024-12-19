#include "profesor.h"
#include "solicitud.h"
#include <iostream>
#include <cassert>

int main() {
    // Crear dos objetos Profesor
    Profesor profesor1("Juan Perez", "12345678A", "juan.perez@gmail.com", "password123", "Informática");
    Profesor profesor2("Ana Garcia", "87654321B", "ana.garcia@gmail.com", "password456", "Física");

    // Crear dos Solicitudes
    Solicitud solicitud1("Pendiente", "2024-12-11", "Universidad A", "Universidad B", "2024-02-01", "2024-06-30");
    Solicitud solicitud2("Pendiente", "2024-12-11", "Universidad C", "Universidad D", "2024-03-01", "2024-07-31");

    // Enviar solicitudes
    std::cout << "Enviando solicitud de Juan...\n";
    profesor1.enviarSolicitud(solicitud1);
    
    std::cout << "Enviando solicitud de Ana...\n";
    profesor2.enviarSolicitud(solicitud2);

    // Consultar el estado de las solicitudes
    std::cout << "\nConsultando estado de la solicitud de Juan...\n";
    profesor1.consultarEstadoSolicitud(solicitud1);

    std::cout << "\nConsultando estado de la solicitud de Ana...\n";
    profesor2.consultarEstadoSolicitud(solicitud2);

    // Cancelar solicitudes (sin motivo)
    std::cout << "\nCancelando solicitud de Juan...\n";
    profesor1.cancelarSolicitud();

    std::cout << "\nCancelando solicitud de Ana...\n";
    profesor2.cancelarSolicitud();

    return 0;
}

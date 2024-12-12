#include <iostream>
#include "solicitud.h"

int main() {
    // Crear una solicitud con un estado inicial
    Solicitud solicitud("Pendiente", "2024-12-01", "Universidad A", "Universidad B", "2025-01-01", "2025-06-30");

    // Mostrar el estado antes de actualizar
    std::cout << "Estado inicial: " << solicitud.getEstado() << std::endl;

    // Actualizar el estado de la solicitud
    solicitud.actualizarEstado("Aceptada");

    // Mostrar el estado después de actualizar
    std::cout << "Estado actualizado: " << solicitud.getEstado() << std::endl;

    // Comprobar si el estado ha cambiado correctamente
    if (solicitud.getEstado() == "Aceptada") {
        std::cout << "La actualización del estado fue exitosa." << std::endl;
    } else {
        std::cout << "Hubo un error al actualizar el estado." << std::endl;
    }

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>  // Necesario para obtener la fecha actual
#include "profesor.h"

// Constructor
Profesor::Profesor(const std::string& nombre, const std::string& dni, 
                   const std::string& correo, const std::string& contraseña, 
                   const std::string& departamento)
    : Usuario(nombre, dni, correo, contraseña), departamento_(departamento) {}

// HU5: Enviar solicitud SICUE (profesor)
void Profesor::enviarSolicitud(const Solicitud& solicitud) {
    // Obtener la fecha de envío actual del sistema
    std::time_t t = std::time(0); 
    std::tm* now = std::localtime(&t);

    // Formatear la fecha en formato YYYY-MM-DD
    char fechaEnvio[11];
    std::strftime(fechaEnvio, sizeof(fechaEnvio), "%Y-%m-%d", now);

    // Mostrar la fecha de envío generada automáticamente
    std::cout << "Fecha de envío " << fechaEnvio << "\n";

    // Guardar la solicitud en el archivo
    std::ofstream archivo("solicitudes.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << "Solicitud enviada por el Profesor:\n";
        archivo << "Nombre: " << nombre_ << "\n";
        archivo << "DNI: " << dni_ << "\n";
        archivo << "Departamento: " << departamento_ << "\n";
        archivo << "Correo: " << correo_ << "\n";
        archivo << "Fecha de envío: " << fechaEnvio << "\n";
        archivo << "Universidad Origen: " << solicitud.getUniversidadOrigen() << "\n";
        archivo << "Universidad Destino: " << solicitud.getUniversidadDestino() << "\n";
        archivo << "Periodo: " << solicitud.getFechaInicio() << " - " << solicitud.getFechaFin() << "\n";
        archivo << "Estado: " << solicitud.getEstado() << "\n\n";
        archivo.close();
        std::cout << "Solicitud enviada y guardada correctamente.\n\n";
    } else {
        std::cerr << "Error al abrir el archivo de solicitudes.\n";
    }
}

// Cancelar solicitud SICUE
void Profesor::cancelarSolicitud() {
    std::ofstream archivo("solicitudes.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << "Solicitud CANCELADA por el Profesor:\n";
        archivo << "Nombre: " << nombre_ << "\n";
        archivo << "DNI: " << dni_ << "\n";
        archivo << "Departamento: " << departamento_ << "\n\n";
        archivo.close();
        std::cout << "Solicitud cancelada y registrada correctamente.\n";  // Aquí NO ponemos salto de línea extra
    } else {
        std::cerr << "Error al abrir el archivo para cancelar la solicitud.\n";
    }
}

// Consultar estado de una solicitud SICUE
void Profesor::consultarEstadoSolicitud(const Solicitud& solicitud) {
    std::cout << "Estado actual de la solicitud:\n";
    std::cout << "Estado: " << solicitud.getEstado() << "\n";
    std::cout << "Periodo: " << solicitud.getFechaInicio() << " - " << solicitud.getFechaFin() << "\n";
    std::cout << "Universidad Origen: " << solicitud.getUniversidadOrigen() << "\n";
    std::cout << "Universidad Destino: " << solicitud.getUniversidadDestino() << "\n";
}

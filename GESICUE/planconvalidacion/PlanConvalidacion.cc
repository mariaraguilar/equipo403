#include <iostream>
#include <fstream>
#include <string>
#include "PlanConvalidacion.h"

// Constructor
PlanConvalidacion::PlanConvalidacion(const std::string& estado,
                                     const std::string& fechaEnvio,
                                     const std::string& universidadOrigen,
                                     const std::string& universidadDestino,
                                     const std::string& fechaInicio,
                                     const std::string& fechaFin,
                                     const std::string& nombreasignatura,
                                     const Carrera& carrera,
                                     const int& ncreditos)
    : Solicitud(estado, fechaEnvio, universidadOrigen, universidadDestino, fechaInicio, fechaFin),  // Inicializa Solicitud
      Asignatura(nombreasignatura, "", carrera),  // Pasa la Carrera a Asignatura
      ncreditos_(ncreditos) {}  // Inicializa ncreditos

// Método para guardar el plan de convalidación
void PlanConvalidacion::guardarPlanConvalidacion(const Solicitud& solicitud)
{
    std::ofstream archivo("planesconvalidacion.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << "Nuevo plan de convalidacion:\n";
        archivo << "Universidad Origen: " << solicitud.getUniversidadOrigen() << "\n";
        archivo << "Universidad Destino: " << solicitud.getUniversidadDestino() << "\n";
        archivo << "Nombre de las asignaturas convalidadas: " << getNombreAsignatura() << "\n";
        
        // Llamada al método heredado de Asignatura para obtener el nombre de la carrera
        archivo << "Nombre de la carrera: " << getNombreCarrera() << "\n"; 
        
        archivo << "Numero de creditos: " << ncreditos_ << "\n\n";
        archivo.close();
        std::cout << "Plan de convalidacion guardado correctamente.\n";
    } else {
        std::cerr << "Error al abrir el archivo de planes de convalidacion.\n";
    }
}

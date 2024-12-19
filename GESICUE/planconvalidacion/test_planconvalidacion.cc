#include "PlanConvalidacion.h"
#include <iostream>
#include <cassert>
#include "carrera.h"

int main() 
{
    // Crear dos solicitudes
    Solicitud solicitud1("Pendiente", "2024-12-11", "Universidad A", "Universidad B", "2024-02-01", "2024-06-30");
    Solicitud solicitud2("Pendiente", "2024-12-11", "Universidad C", "Universidad D", "2024-03-01", "2024-07-31");

    // Crear dos objetos Carrera (necesarios para PlanConvalidacion)
    Carrera carrera1("Ingenieria Mecanica", "IM001");
    Carrera carrera2("Ingenieria Informatica", "II001");

    // Crear dos Planes de Convalidacion
    PlanConvalidacion plan1("Pendiente", "2024-12-11", "Universidad A", "Universidad B", "2024-02-01", "2024-06-30", "Cálculo, Matemáticas, Química, Electrotecnia, Informática y Física ", carrera1, 6);
    PlanConvalidacion plan2("Pendiente", "2024-12-11", "Universidad C", "Universidad D", "2024-03-01", "2024-07-31", "Base de datos, Ingeniería del Software, AC, Sistemas Operativos y POO ", carrera2, 6);

    // Crear plan de convalidacion
    std::cout << "Guardando planes de convalidación...\n";
    plan1.guardarPlanConvalidacion(solicitud1);
    plan2.guardarPlanConvalidacion(solicitud2);

    return 0;
}

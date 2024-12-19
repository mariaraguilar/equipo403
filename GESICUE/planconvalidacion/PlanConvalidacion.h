#ifndef PLANCONVALIDACION_H
#define PLANCONVALIDACION_H

#include "solicitud.h"
#include "asignatura.h"  // Incluir Asignatura, que tiene una Carrera
#include "carrera.h"     // Carrera es necesario como clase independiente
#include <string>

class PlanConvalidacion : public Solicitud, public Asignatura {
private:
    int ncreditos_;

public:
    // Declaración del constructor (sin definición aquí)
    PlanConvalidacion(const std::string& estado,
                      const std::string& fechaEnvio,
                      const std::string& universidadOrigen,
                      const std::string& universidadDestino,
                      const std::string& fechaInicio,
                      const std::string& fechaFin,
                      const std::string& nombreasignatura,
                      const Carrera& carrera,
                      const int& ncreditos);

    void guardarPlanConvalidacion(const Solicitud& solicitud);
};

#endif

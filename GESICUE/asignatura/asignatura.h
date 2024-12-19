#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include <string>
#include "carrera.h"  // Ahora Asignatura no hereda de Carrera, pero puede tener una referencia

class Asignatura {
private:
    std::string nombreasignatura_;
    std::string codigoasignatura_;
    Carrera carrera_;  // Carrera como miembro de Asignatura

public:
    Asignatura(const std::string& nombreasignatura, const std::string& codigoasignatura, const Carrera& carrera)
        : nombreasignatura_(nombreasignatura), codigoasignatura_(codigoasignatura), carrera_(carrera) {}

    // Métodos getter y setter
    std::string getNombreAsignatura() const { return nombreasignatura_; }
    void setNombreAsignatura(const std::string& nombreasignatura) { nombreasignatura_ = nombreasignatura; }

    std::string getCodigoAsignatura() const { return codigoasignatura_; }
    void setCodigoAsignatura(const std::string& codigoasignatura) { codigoasignatura_ = codigoasignatura; }

    // Obtener información de la carrera relacionada
    std::string getNombreCarrera() const { return carrera_.getNombreCarrera(); }
    std::string getCodigoCarrera() const { return carrera_.getCodigoCarrera(); }
};

#endif

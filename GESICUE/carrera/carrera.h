#ifndef CARRERA_H
#define CARRERA_H

#include <string>

class Carrera {
private:
    std::string nombrecarrera_;
    std::string codigocarrera_;

public:
    Carrera(const std::string& nombrecarrera, const std::string& codigocarrera);
    
    // Métodos getter y setter
    std::string getNombreCarrera() const { return nombrecarrera_; }
    void setNombreCarrera(const std::string& nombrecarrera) { nombrecarrera_ = nombrecarrera; }

    std::string getCodigoCarrera() const { return codigocarrera_; }
    void setCodigoCarrera(const std::string& codigocarrera) { codigocarrera_ = codigocarrera; }
};

#endif

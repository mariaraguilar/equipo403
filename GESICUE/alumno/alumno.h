#ifndef ALUMNO_H
#define ALUMNO_H

#include "usuario.h"
#include "solicitud.h"
#include <string>

class Alumno : public Usuario {
private:
    std::string carrera_;

public:
    Alumno(const std::string& nombre, const std::string& dni, 
           const std::string& correo, const std::string& contraseña, 
           const std::string& carrera);

    void enviarSolicitud(const Solicitud& solicitud);
    void cancelarSolicitud();
    void consultarEstadoSolicitud(const Solicitud& solicitud);

    std::string getCarrera() const { return carrera_; }
    void setCarrera(const std::string& carrera) { carrera_ = carrera; }
};

#endif

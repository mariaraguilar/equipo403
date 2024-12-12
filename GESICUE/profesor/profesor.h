#ifndef PROFESOR_H
#define PROFESOR_H

#include "usuario.h"
#include "solicitud.h"
#include <string>

class Profesor : public Usuario {
private:
    std::string departamento_;

public:
    Profesor(const std::string& nombre, const std::string& dni, 
             const std::string& correo, const std::string& contraseña, 
             const std::string& departamento);

    // Métodos
    void enviarSolicitud(const Solicitud& solicitud);
    void cancelarSolicitud();
    void consultarEstadoSolicitud(const Solicitud& solicitud);

    // Getter y Setter
    std::string getDepartamento() const { return departamento_; }
    void setDepartamento(const std::string& departamento) { departamento_ = departamento; }
};

#endif // PROFESOR_H

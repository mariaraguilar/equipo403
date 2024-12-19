#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.h"
#include <string>

class Administrador : public Usuario 
{
private:

public:
    Administrador(const std::string& nombre, 
             const std::string& dni, 
             const std::string& correo, 
             const std::string& contraseña);
             
    void añadirAdministrador(const Usuario& usuario);
};

#endif 
#include "usuario.h"
#include <iostream>

Usuario::Usuario(const std::string& nombre, const std::string& dni, 
                 const std::string& correo, const std::string& contraseña)
    : nombre_(nombre), dni_(dni), correo_(correo), contraseña_(contraseña) {}

bool Usuario::iniciarSesion(const std::string& correo, const std::string& contraseña) {
    if (correo == correo_ && contraseña == contraseña_) {
        std::cout << "Inicio de sesión exitoso. Bienvenido, " << nombre_ << "!\n";
        return true;
    } else {
        std::cout << "Error: Correo o contraseña incorrectos.\n";
        return false;
    }
}

void Usuario::cerrarSesion() {
    std::cout << "Sesión cerrada para el usuario " << nombre_ << ".\n";
}
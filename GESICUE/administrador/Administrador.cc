#include <iostream>
#include <fstream>
#include <string>
#include "administrador.h"

Administrador::Administrador(const std::string& nombre, 
                             const std::string& dni, 
                             const std::string& correo, 
                             const std::string& contraseña)
              :Usuario(nombre, dni, correo, contraseña) {}

void Administrador::añadirAdministrador(const Usuario& usuario)
{
    std::ofstream archivo("administrador.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << "Registrar nuevo administrador:\n";
        archivo << "Nombre: " << usuario.getNombre() << "\n";
        archivo << "DNI: " << usuario.getDni() << "\n";
        archivo << "Correo: " << usuario.getCorreo() << "\n";
        archivo << "Contraseña: " << usuario.getContraseña() << "\n\n";
        archivo.close();
        std::cout << "Administrador guardado correctamente.\n";
    } else {
        std::cerr << "Error al abrir el archivo de administrador.\n";
    }
}
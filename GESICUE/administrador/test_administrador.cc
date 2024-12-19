#include "administrador.h"
#include <iostream>
#include <cassert>

int main() 
{
    //Crear dos usuarios
    Usuario user1("Aron Piper", "12345678A", "aron.piper@gmail.com", "secreta123");
    Usuario user2("Rosa Garcia", "87654321B", "rosa.garcia@gmail.com", "secreta456");

    // Crear dos administradores
    Administrador admi1(" ", " ", " ", " ");
    Administrador admi2(" ", " ", " ", " ");

    // Guardar administradores creados
    std::cout << "Guardando administradores...\n";
    admi1.añadirAdministrador(user1);
    admi2.añadirAdministrador(user2);

    return 0;
}
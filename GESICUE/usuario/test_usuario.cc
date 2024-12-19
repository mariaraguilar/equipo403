#include "usuario.h"
#include <iostream>
#include <cassert>

int main() {
    Usuario usuario1("Carlos Gómez", "87654321B", "carlos.gomez@gmail.com", "claveSecreta321");

    // Verificar inicio de sesión con credenciales correctas
    bool loginExitoso = usuario1.iniciarSesion("carlos.gomez@gmail.com", "claveSecreta321");
    assert(loginExitoso == true); // Debería ser exitoso

    // Verificar inicio de sesión con credenciales incorrectas
    bool loginFallido = usuario1.iniciarSesion("carlos.gomez@gmail.com", "claveIncorrecta");
    assert(loginFallido == false); // Debería fallar

    // Verificar el cierre de sesión
    usuario1.cerrarSesion(); // Debería imprimir que la sesión se ha cerrado
    return 0;
}

#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string nombre_;
    std::string dni_;
    std::string correo_;
    std::string contraseña_;

public:
    Usuario(const std::string& nombre, const std::string& dni, 
            const std::string& correo, const std::string& contraseña);

    bool iniciarSesion(const std::string& correo, const std::string& contraseña);
    void cerrarSesion();

    // Getters
    std::string getNombre() const {return nombre_;}
    std::string getDni() const {return dni_;}
    std::string getCorreo() const {return correo_;}
    std::string getContraseña() const {return contraseña_;}

    // Setters
    void setNombre(const std::string& nombre) {nombre_ = nombre;}
    void setDni(const std::string& dni) {dni_ = dni;}
    void setCorreo(const std::string& correo) {correo_ = correo;}
    void setContraseña(const std::string& contraseña) {contraseña_ = contraseña;}
    virtual ~Usuario() {}
};

#endif

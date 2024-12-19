#ifndef SOLICITUD_H
#define SOLICITUD_H

#include <string>
#include <ctime> // Para manejar fechas

class Solicitud {
    private:
    std::string estado_;           // Estado de la solicitud (pendiente, aprobada, cancelada, etc.)
    std::string fechaEnvio_;       // Fecha de envío de la solicitud
    std::string universidadOrigen_; // Universidad de origen
    std::string universidadDestino_; // Universidad destino
    std::string fechaInicio_;      // Fecha de inicio del periodo SICUE
    std::string fechaFin_;         // Fecha de fin del periodo SICUE

    public:
    // Constructor
    Solicitud(std::string estado, std::string fechaEnvio, std::string universidadOrigen, 
              std::string universidadDestino, std::string fechaInicio, std::string fechaFin)
        : estado_(estado), fechaEnvio_(fechaEnvio), universidadOrigen_(universidadOrigen),
          universidadDestino_(universidadDestino), fechaInicio_(fechaInicio), fechaFin_(fechaFin) {}

    void actualizarEstado(const std::string& nuevoEstado) {estado_ = nuevoEstado;}

    // Getters
    std::string getEstado() const {return estado_;}
    std::string getFechaEnvio() const {return fechaEnvio_;}
    std::string getUniversidadOrigen() const {return universidadOrigen_;}
    std::string getUniversidadDestino() const {return universidadDestino_;}
    std::string getFechaInicio() const {return fechaInicio_;}
    std::string getFechaFin() const {return fechaFin_;}

    // Setters
    void setEstado(const std::string& nuevoEstado) {estado_ = nuevoEstado;}
    void setFechaEnvio(const std::string& nuevaFechaEnvio) {fechaEnvio_ = nuevaFechaEnvio;}
    void setUniversidadOrigen(const std::string& nuevaUniversidadOrigen) {universidadOrigen_ = nuevaUniversidadOrigen;}
    void setUniversidadDestino(const std::string& nuevaUniversidadDestino) {universidadDestino_ = nuevaUniversidadDestino;}
    void setFechaInicio(const std::string& nuevaFechaInicio) {fechaInicio_ = nuevaFechaInicio;}
    void setFechaFin(const std::string& nuevaFechaFin) {fechaFin_ = nuevaFechaFin;}
};

#endif
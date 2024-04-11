#include <QCoreApplication>
#include <iostream>
#include <string>

class Jugador {
public:
    // Constructor predeterminado
    Jugador() {
        velocidad = 0;
        fuerza = 0;
        nombre = "Sin nombre";
    }

    // Constructor con parámetros
    Jugador( int velocidad_, int fuerza_,std::string nombre_) {
        velocidad = velocidad_;
        fuerza = fuerza_;
        nombre = nombre_;
    }

    // Método para mostrar información del jugador
    void mostrarInformacion() {
        std::cout << "Nombre: " << nombre << ", Fuerza: " << fuerza << ", Velocidad: " << velocidad << std::endl;
    }

    // Métodos para modificar atributos
    void setNombre(std::string nombre_) {
        nombre = nombre_;
    }

    void setFuerza(int fuerza_) {
        fuerza = fuerza_;
    }

    void setVelocidad(int velocidad_) {
        velocidad = velocidad_;
    }

    // Método para obtener el nombre del jugador
    std::string getNombre() const {
        return nombre;
    }

    // Método para obtener la fuerza del jugador
    int getFuerza() const {
        return fuerza;
    }

    // Método para obtener la velocidad del jugador
    int getVelocidad() const {
        return velocidad;
    }

private:
    // Atributos
    int velocidad;
    int fuerza;
    std::string nombre;
};



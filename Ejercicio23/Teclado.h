#ifndef TECLADO_H
#define TECLADO_H

#include "Instrumento.h"

class Electrico {
public:
    Electrico() : voltage(220) {}
    ~Electrico() {
        std::cout << "Desenchufado" << std::endl;
    }

private:
    int voltage;

    // Declaración de la función amiga en la clase Electrico
    friend int obtenerVoltaje(const Electrico& electrico);
};

class Teclado : public Instrumento, public Electrico {
public:
    Teclado(int teclas = 61) : teclas(teclas) {}
    virtual void sonar() override {
        std::cout << "Teclado suena..." << std::endl;
    }
    virtual void verMarca() override {
        Instrumento::verMarca();
    }
    // Métodos get y set
    int getTeclas() const { return teclas; }
    void setTeclas(int teclas) { this->teclas = teclas; }

private:
    int teclas;
};

// Implementación de la función amiga
int obtenerVoltaje(const Electrico& electrico) {
    return electrico.voltage;
}

#endif // TECLADO_H

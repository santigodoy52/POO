#ifndef TECLADO_H
#define TECLADO_H
#include "Instrumento.h"

class Electrico {
public:
    Electrico() : voltaje(220) {}
    ~Electrico() {
        std::cout << "Desenchufado" << std::endl;
    }

private:
    int voltaje;
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

#endif // TECLADO_H

#ifndef GUITARRA_H
#define GUITARRA_H

#include "Instrumento.h"
#include "Teclado.h"

class Guitarra : public Instrumento {
public:
    Guitarra(int cuerdas = 6) : cuerdas(cuerdas) {}
    virtual void sonar() override {
        std::cout << "Guitarra suena..." << std::endl;
    }
    virtual void verMarca() override {
        Instrumento::verMarca();
    }
    // Métodos get y set
    int getCuerdas() const { return cuerdas; }
    void setCuerdas(int cuerdas) { this->cuerdas = cuerdas; }

    // Función inline que devuelve la suma de las cuerdas de una guitarra y el número de teclas de un teclado
    inline int sumaCuerdasTeclas(const Teclado& teclado) const { return cuerdas + teclado.getTeclas(); }

private:
    int cuerdas;
};


#endif // GUITARRA_H

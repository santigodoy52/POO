#ifndef BATERIA_H
#define BATERIA_H

#include "Instrumento.h"

class Bateria : public Instrumento {
public:
    Bateria(int tambores = 5) : tambores(tambores) {}
    virtual void sonar() override {
        std::cout << "Bateria suena..." << std::endl;
    }
    virtual void verMarca() override {
        Instrumento::verMarca();
    }
    // Métodos get y set
    int getTambores() const { return tambores; }
    void setTambores(int tambores) { this->tambores = tambores; }

private:
    int tambores;
};

#endif // BATERIA_H

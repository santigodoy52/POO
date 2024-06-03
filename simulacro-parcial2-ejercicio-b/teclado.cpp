#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"

class Teclado : public Instrumento {
public:
    void afinar() const override;
};

#endif // TECLADO_H

#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"

class Guitarra : public Instrumento {
public:
    void afinar() const override;
};

#endif // GUITARRA_H

#ifndef VIENTO_H
#define VIENTO_H

#include "instrumento.h"

class Viento : public Instrumento {
public:
    void afinar() const override;
};

#endif // VIENTO_H

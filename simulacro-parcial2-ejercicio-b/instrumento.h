#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <iostream>

class Instrumento {
public:
    virtual void afinar() const = 0;
};

#endif // INSTRUMENTO_H

#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <iostream>

class Instrumento {
public:
    virtual ~Instrumento() {}
    virtual void sonar() = 0;
    virtual void verMarca() {
        std::cout << "Marca: Yamaha" << std::endl;
    }
};

#endif // INSTRUMENTO_H

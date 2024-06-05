#include "rectangulo.h"

Rectangulo::Rectangulo(int x, int y, int ancho, int alto) : x(x), y(y), ancho(ancho), alto(alto) {}

// Getters
int Rectangulo::getX() const {
    return x;
}

int Rectangulo::getY() const {
    return y;
}

int Rectangulo::getAlto() const {
    return alto;
}

int Rectangulo::getAncho() const {
    return ancho;
}

// Setters
void Rectangulo::setX(int X) {
    x = X;
}

void Rectangulo::setY(int Y) {
    y = Y;
}

void Rectangulo::setAnchol(int Ancho) {
    ancho = Ancho;
}

void Rectangulo::setAlto(int Alto) {
    alto = Alto;
}

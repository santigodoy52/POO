#include "linea.h"

Linea::Linea(int xInicial, int yInicial, int xFinal, int yFinal)
    : m_xInicial(xInicial), m_yInicial(yInicial), m_xFinal(xFinal), m_yFinal(yFinal) {}

// Getters
int Linea::getXInicial() const {
    return m_xInicial;
}

int Linea::getYInicial() const {
    return m_yInicial;
}

int Linea::getXFinal() const {
    return m_xFinal;
}

int Linea::getYFinal() const {
    return m_yFinal;
}

// Setters
void Linea::setXInicial(int xInicial) {
    m_xInicial = xInicial;
}

void Linea::setYInicial(int yInicial) {
    m_yInicial = yInicial;
}

void Linea::setXFinal(int xFinal) {
    m_xFinal = xFinal;
}

void Linea::setYFinal(int yFinal) {
    m_yFinal = yFinal;
}

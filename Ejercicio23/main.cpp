
#include <iostream>
#include <vector>
#include "Instrumento.h"
#include "Guitarra.h"
#include "Bateria.h"
#include "Teclado.h"

int main() {
    std::vector<Instrumento*> instrumentos;

    instrumentos.push_back(new Guitarra());
    instrumentos.push_back(new Bateria());
    instrumentos.push_back(new Teclado());
    instrumentos.push_back(new Guitarra(7)); // Agregar una guitarra de 7 cuerdas
    instrumentos.push_back(new Bateria(7)); // Agregar una guitarra de 7 tambores

    for (auto instrumento : instrumentos) {
        instrumento->verMarca();
        instrumento->sonar();
    }

    for (auto instrumento : instrumentos) {
        delete instrumento;
    }

    return 0;
}

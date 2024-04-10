#include <QCoreApplication>
#include <iostream>
#include <string>
#include "animales.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Creamos objetos de la clase Animal
    Animal perro("Perro", 50, 20);
    Animal gato("Gato", 30, 10);
    Animal elefante("Elefante", 300, 100);

    // Almacenar los objetos en un vector
    std::vector<Animal> animales;
    animales.push_back(perro);
    animales.push_back(gato);
    animales.push_back(elefante);

    // Ordenar el vector alfabéticamente
    std::sort(animales.begin(), animales.end(), compareAnimales);

    // Mostrar la información de los animales ordenados
    std::cout << "Animales ordenados alfabeticamente:" << std::endl;
    for (const Animal& animal : animales) {
        std::cout << animal.getNombre() << std::endl;
    }

    return a.exec();
}



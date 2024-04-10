#include <QCoreApplication>
#include <iostream>
#include <string>
#include "animal.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Crear objetos de la clase Personaje
    Animal animal1("Perro", 50, 35);
    Animal animal2("Gato", 40, 25);

    // Mostrar información de los animales
    std::cout << "Informacion del animal 1:" << std::endl;
    animal1.mostrarInformacion();

    std::cout << "\nInformacion del animal 2:" << std::endl;
    animal2.mostrarInformacion();

    animal1.setAltura(22);
    animal1.setPeso(19);
    std::cout << "\nInformacion del animal 1 modificada:" << std::endl;
    animal1.mostrarInformacion();

    return a.exec();
}

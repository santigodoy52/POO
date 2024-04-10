#include <QCoreApplication>
#include <iostream>
#include <string>
#include "animal.h"
#include "persona.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Crear objetos de la clase Personaje
    Animal animal1("Perro", 50, 35);
    Persona persona1("Juan", "Masculino", 25);

    // Mostrar información de los animales
    std::cout << "Informacion de la clase Animal:" << std::endl;
    animal1.mostrarInformacion();

    std::cout << "\nInformacion de la clase Persona:" << std::endl;

    persona1.mostrarInformacion();

    return a.exec();
}

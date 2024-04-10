#include <QCoreApplication>
#include <iostream>
#include <string>

class Animal {
public:
    // Constructor predeterminado
    Animal() {
        nombre = "Sin nombre";
        altura = 1;
        peso = 100;
    }

    // Constructor con parámetros
    Animal(std::string nombre_, int altura_, int peso_) {
        nombre = nombre_;
        altura = altura_;
        peso = peso_;
    }

    // Método para mostrar información del animal
    void mostrarInformacion() {
        std::cout << "Nombre: " << nombre << ", Altura: " << altura << ", Peso: " << peso << std::endl;
    }

    // Métodos para modificar atributos
    void setNombre(std::string nombre_) {
        nombre = nombre_;
    }

    void setAltura(int altura_) {
        altura = altura_;
    }

    void setPeso(int peso_) {
        peso = peso_;
    }

private:
    // Atributos
    std::string nombre;
    int altura;
    int peso;
};

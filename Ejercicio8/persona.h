#include <QCoreApplication>
#include <iostream>
#include <string>

class Persona {
public:
    // Constructor predeterminado
    Persona() {
        nombre = "Sin nombre";
        sexo = "Masculino";
        peso = 100;
    }

    // Constructor con parámetros
    Persona(std::string nombre_, std::string sexo_, int peso_) {
        nombre = nombre_;
        sexo = sexo_;
        peso = peso_;
    }

    // Método para mostrar información de la persona
    void mostrarInformacion() {
        std::cout << "Nombre: " << nombre << ", Sexo: " << sexo << ", Peso: " << peso << std::endl;
    }

    // Métodos para modificar atributos
    void setNombre(std::string nombre_) {
        nombre = nombre_;
    }

    void setSexo(std::string sexo_) {
        sexo = sexo_;
    }

    void setPeso(int peso_) {
        peso = peso_;
    }

private:
    // Atributos
    std::string nombre;
    std::string sexo;
    int peso;
};

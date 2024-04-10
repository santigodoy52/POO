#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// Función para generar un número aleatorio entre min y max
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Función para calcular la moda de un vector de enteros
int calculateMode(const std::vector<int>& values) {
    std::map<int, int> frequencyMap;

    // Contar la frecuencia de cada elemento en el vector
    for (int value : values) {
        frequencyMap[value]++;
    }

    // Encontrar el valor con la mayor frecuencia
    int mode = 0;
    int maxFrequency = 0;
    for (const auto& pair : frequencyMap) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mode = pair.first;
        }
    }

    return mode;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Crear un vector para almacenar los valores aleatorios
    std::vector<int> values;

    // Generar 30 valores aleatorios entre 1 y 15 y almacenarlos en el vector
    for (int i = 0; i < 30; ++i) {
        values.push_back(generateRandomNumber(1, 15));
    }

    // Calcular la moda de los valores
    int mode = calculateMode(values);

    // Mostrar la moda
    std::cout << "La moda de los valores aleatorios es: " << mode << std::endl;

    return a.exec();
}

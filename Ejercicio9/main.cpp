#include <iostream>

template <class T>
void imprimir(T *v, int cantidad, bool mayor_a_menor) {
    // Implementación del método de ordenamiento por inserción
    for (int i = 1; i < cantidad; ++i) {
        T key = v[i];
        int j = i - 1;

        if (mayor_a_menor) {
            while (j >= 0 && v[j] < key) {
                v[j + 1] = v[j];
                j = j - 1;
            }
        } else {
            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                j = j - 1;
            }
        }
        v[j + 1] = key;
    }

    // Imprimir el array ordenado
    if (mayor_a_menor) {
        std::cout << "Orden descendente: ";
        for (int i = 0; i < cantidad; ++i) {
            std::cout << v[i] << " ";
        }
    } else {
        std::cout << "Orden ascendente: ";
        for (int i = 0; i < cantidad; ++i) {
            std::cout << v[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Ejemplo con un array de enteros
    int array_int[] = {5, 3, 8, 1, 6};
    int cantidad_int = sizeof(array_int) / sizeof(array_int[0]);

    std::cout << "Array de enteros original: ";
    for (int i = 0; i < cantidad_int; ++i) {
        std::cout << array_int[i] << " ";
    }
    std::cout << std::endl;

    imprimir(array_int, cantidad_int, true); // Orden descendente
    imprimir(array_int, cantidad_int, false); // Orden ascendente

    // Ejemplo con un array de floats
    float array_float[] = {3.5, 1.2, 7.8, 2.4, 5.6};
    int cantidad_float = sizeof(array_float) / sizeof(array_float[0]);

    std::cout << "Array de floats original: ";
    for (int i = 0; i < cantidad_float; ++i) {
        std::cout << array_float[i] << " ";
    }
    std::cout << std::endl;

    imprimir(array_float, cantidad_float, true); // Orden descendente
    imprimir(array_float, cantidad_float, false); // Orden ascendente

    return 0;
}

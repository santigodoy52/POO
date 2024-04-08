// main.cpp

#include <iostream>
#include <QLibrary>

typedef void (*HelloFunction)();

int main() {
    QLibrary library("library");

    if (library.load()) {
        HelloFunction hello = (HelloFunction)library.resolve("helloFromLibrary");
        if (hello) {
            hello();
        } else {
            std::cout << "No se pudo encontrar la función en la biblioteca." << std::endl;
        }
        library.unload();
    } else {
        std::cout << "No se pudo cargar la biblioteca." << std::endl;
    }

    return 0;
}

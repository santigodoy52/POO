#include <QCoreApplication>
#include "santinamespace.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Uso de MyClass dentro de MyNamespace
    santinamespace::MyClass myObject;
    myObject.myFunction();

    // Uso de una función fuera de una clase en MyNamespace
    santinamespace::myFunctionOutsideClass();

    return a.exec();
}

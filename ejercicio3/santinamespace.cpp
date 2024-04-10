#include "santinamespace.h"
#include <iostream>

namespace santinamespace {
    void MyClass::myFunction() {
        std::cout << "Dentro de MyNamespace::MyClass::myFunction()" << std::endl;
    }

    void myFunctionOutsideClass() {
        std::cout << "Dentro de MyNamespace::myFunctionOutsideClass()" << std::endl;
    }
}

#include "formulario.h"
#include <QApplication>

int main(int argc , char *argv[])
{
    QApplication a(argc , argv);
    Formulario form;
    form.show();

    return a.exec();
}

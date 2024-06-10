#include <QApplication>
#include "login.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    LoginWidget loginWidget;
    loginWidget.show();
    return a.exec();
}

#include <QApplication>
#include <QDebug>
#include <QDir>
#include "adminDB.h"
#include "login.h"

int main( int argc, char** argv )  {
    QApplication a( argc, argv );
    LoginWidget login;
    login.show();
    return a.exec();
}

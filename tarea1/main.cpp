#include <QCoreApplication>
#include <QDebug>
#include <QRandomGenerator>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Semilla aleatoria basada en la hora actual
    QRandomGenerator::securelySeeded();

    qDebug() << "Mostrando 10 números aleatorios en el intervalo [2, 20]:";

    for (int i = 0; i < 10; ++i) {
        // Generar un número aleatorio en el intervalo [2, 20]
        int randomNumber = QRandomGenerator::global()->bounded(2, 21); // 21 no está incluido en el rango
        qDebug() << randomNumber;
    }

    return a.exec();
}

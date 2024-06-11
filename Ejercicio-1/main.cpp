#include <QCoreApplication>
#include <QDebug>
#include <QTime>
#include <QtGlobal>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Configuración de la semilla para la generación de números aleatorios
    qsrand(QTime::currentTime().msec());

    // Almacenamiento de los números generados para asegurar su unicidad
    QVector<int> numerosGenerados;

    // Generación de 10 números aleatorios en el intervalo [2, 20]
    qDebug() << "Generando 10 números aleatorios en el intervalo [2, 20]:";
    for (int i = 0; i < 10; ++i) {
        int numero;
        do {
            // Generar un número aleatorio entre 2 y 20
            numero = qrand() % 19 + 2;
        } while (numerosGenerados.contains(numero)); // Verificar si el número ya ha sido generado
        numerosGenerados.append(numero);
        qDebug() << numero;
    }

    return a.exec();
}

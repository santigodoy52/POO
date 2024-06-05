#include <QSqlDatabase>
#include <QString>
#include <QObject>
#include <QDebug>
#include <QSqlQuery>
#include <QtSql>
#include "rectangulo.h"

class AdminDB : public QObject  {
    Q_OBJECT

public:
    static AdminDB& getInstance(); // Método para obtener la instancia única
    bool conectar( QString archivoSqlite );
    void insertar();
    void leerLineas();
     QVector<Rectangulo> leerRectangulos();
    void modificarLinea(int id,int x1 , int x2 , int y1 , int y2);

    QSqlDatabase getDB();

private:
    AdminDB(); // Constructor privado
    QSqlDatabase db;
};

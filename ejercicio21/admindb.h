#include <QSqlDatabase>
#include <QString>
#include <QObject>
#include <QDebug>
#include <QSqlQuery>
#include <QtSql>


class AdminDB : public QObject  {
    Q_OBJECT

public:
    AdminDB();
    bool conectar( QString archivoSqlite );
    bool validarUsuario(const QString &nombre, const QString &password);
    void mostrarUsuarios();
    QSqlDatabase getDB();

private:
    QSqlDatabase db;
};

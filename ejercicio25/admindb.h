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
    bool validarCredenciales(const QString &username, const QString &password); // Declaración de la nueva función
    void mostrarUsuarios();
    QSqlDatabase getDB();
    void mostrarEstructuraTabla(const QString &nombreTabla);
    bool crearUsuario(const QString &nombre, const QString &password, const QString &nombreCompleto);
    bool crearTablaUsuarios();
    QStringList obtenerUsuarios();
private:
    QSqlDatabase db;
};

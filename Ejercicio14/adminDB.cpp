#include "adminDB.h"

AdminDB::AdminDB()  {
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}

bool AdminDB::conectar( QString archivoSqlite )  {
    db.setDatabaseName( archivoSqlite );

    if( db.open() )
        return true;

    return false;
}

bool AdminDB::validarUsuario(const QString &nombre, const QString &password) {
    // Abre la conexión a la base de datos
    if (!db.open()) {
        qDebug() << "No se pudo abrir la conexión a la base de datos.";
        return false;
    }

    // Ejecuta la consulta para validar el usuario
    QSqlQuery query;
    query.prepare("SELECT * FROM usuarios WHERE usuario = :nombre AND clave = :password");
    query.bindValue(":nombre", nombre);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        db.close(); // Cierra la conexión
        return false;
    }

    // Verifica si se encontró un usuario válido
    bool usuarioValido = query.next();

    // Cierra la conexión a la base de datos
    db.close();

    return usuarioValido;
}

void AdminDB::mostrarUsuarios() {
    // Abre la conexión a la base de datos
    if (!db.open()) {
        qDebug() << "No se pudo abrir la conexión a la base de datos.";
        return;
    }

    // Ejecuta la consulta para obtener todos los usuarios
    QSqlQuery query("SELECT id, usuario, clave, nombre, apellido FROM usuarios");
    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        db.close(); // Cierra la conexión
        return;
    }

    // Muestra los usuarios recuperados
    qDebug() << "Usuarios:";
    while (query.next()) {
        int id = query.value(0).toInt(); // Columna 0: id
        QString usuario = query.value(1).toString(); // Columna 1: usuario
        QString clave = query.value(2).toString(); // Columna 2: clave
        QString nombre = query.value(3).toString(); // Columna 3: nombre
        QString apellido = query.value(4).toString(); // Columna 4: apellido
        qDebug() << "ID:" << id << ", Usuario:" << usuario << ", Clave:" << clave << ", Nombre:" << nombre << ", Apellido:" << apellido;
    }

    db.close();
}




QSqlDatabase AdminDB::getDB()  {
    return db;
}

#include "admindb.h"

AdminDB::AdminDB()  {
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}

bool AdminDB::conectar( QString archivoSqlite )  {
    db.setDatabaseName( archivoSqlite );

    if( db.open() )
        return true;

    return false;
}

bool AdminDB::validarCredenciales(const QString &username, const QString &password) {
    // Abre la conexión a la base de datos
    if (!db.open()) {
        qDebug() << "No se pudo abrir la conexión a la base de datos.";
        return false;
    }

    // Ejecuta la consulta para validar las credenciales
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM usuarios WHERE usuario = :username AND clave = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        db.close(); // Cierra la conexión
        return false;
    }

    // Obtiene el resultado de la consulta
    query.next();
    int count = query.value(0).toInt();

    // Cierra la conexión a la base de datos
    db.close();

    // Retorna verdadero si se encontró un usuario con las credenciales proporcionadas
    return count > 0;
}



void AdminDB::mostrarUsuarios() {
    // Abre la conexión a la base de datos
    if (!db.open()) {
        qDebug() << "No se pudo abrir la conexión a la base de datos.";
        return;
    }

    // Ejecuta la consulta para obtener todos los usuarios
    QSqlQuery query("SELECT id, usuario, clave, nombre_completo FROM usuarios");
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
        QString nombreCompleto = query.value(3).toString(); // Columna 3: nombre_completo
        qDebug() << "ID:" << id << ", Usuario:" << usuario << ", Clave:" << clave << ", Nombre Completo:" << nombreCompleto;
    }
    db.close();
}

void AdminDB::mostrarEstructuraTabla(const QString &nombreTabla) {
    // Abre la conexión a la base de datos
    if (!db.open()) {
        qDebug() << "No se pudo abrir la conexión a la base de datos.";
        return;
    }

    // Ejecuta la consulta para obtener la estructura de la tabla
    QSqlQuery query(db);
    query.prepare("SELECT sql FROM sqlite_master WHERE type='table' AND name=:nombreTabla");
    query.bindValue(":nombreTabla", nombreTabla);
    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        db.close(); // Cierra la conexión
        return;
    }

    // Recorre los resultados y muestra la estructura de la tabla
    while (query.next()) {
        QSqlRecord record = query.record();
        QString sql = record.value("sql").toString();
        qDebug() << "Estructura de la tabla" << nombreTabla << ":" << sql;
    }

    // Cierra la conexión a la base de datos
    db.close();
}

// Agrega esta función a la clase AdminDB
bool AdminDB::crearUsuario(const QString &nombre, const QString &password, const QString &nombreCompleto) {
    // Abre la conexión a la base de datos
    if (!db.open()) {
        qDebug() << "No se pudo abrir la conexión a la base de datos.";
        return false;
    }

    // Ejecuta la consulta para insertar el nuevo usuario
    QSqlQuery query;
    query.prepare("INSERT INTO usuarios (usuario, clave, nombre_completo) VALUES (:nombre, :password, :nombreCompleto)");
    query.bindValue(":nombre", nombre);
    query.bindValue(":password", password);
    query.bindValue(":nombreCompleto", nombreCompleto);
    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta para insertar usuario:" << query.lastError().text();
        db.close(); // Cierra la conexión
        return false;
    }

    // Cierra la conexión a la base de datos
    db.close();

    return true;
}


QSqlDatabase AdminDB::getDB()  {
    return db;
}

bool AdminDB::crearTablaUsuarios() {
    // Abre la conexión a la base de datos
    if (!db.open()) {
        qDebug() << "No se pudo abrir la conexión a la base de datos.";
        return false;
    }

    // Ejecuta la consulta para crear la tabla de usuarios
    QSqlQuery query(db);
    QString createTableQuery = "CREATE TABLE IF NOT EXISTS usuarios ("
                                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                "usuario TEXT NOT NULL,"
                                "clave TEXT NOT NULL,"
                                "nombre_completo TEXT"
                                ")";
    if (!query.exec(createTableQuery)) {
        qDebug() << "Error al crear la tabla de usuarios:" << query.lastError().text();
        db.close(); // Cierra la conexión
        return false;
    }

    // Cierra la conexión a la base de datos
    db.close();

    qDebug() << "Tabla de usuarios creada exitosamente.";
    return true;
}

QStringList AdminDB::obtenerUsuarios() {
    QStringList usuarios;

    // Abre la conexión a la base de datos
    if (!db.open()) {
        qDebug() << "No se pudo abrir la conexión a la base de datos.";
        return usuarios;
    }

    // Ejecuta la consulta para obtener todos los usuarios
    QSqlQuery query("SELECT usuario, nombre_completo, clave FROM usuarios");
    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        db.close(); // Cierra la conexión
        return usuarios;
    }

    // Agrega los usuarios a la lista
    while (query.next()) {
        QString usuario = query.value("usuario").toString();
        QString nombreCompleto = query.value("nombre_completo").toString();
        QString clave = query.value("clave").toString();
        QString datosUsuario = usuario + "||" + nombreCompleto + "||" + clave; // Usamos un separador distinto
        usuarios << datosUsuario;
    }

    // Cierra la conexión a la base de datos
    db.close();

    return usuarios;
}


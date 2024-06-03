#include "admindb.h"

AdminDB::AdminDB()  {
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}

AdminDB& AdminDB::getInstance() {
    static AdminDB instance; // Instancia única
    return instance;
}

bool AdminDB::conectar( QString archivoSqlite )  {
    db.setDatabaseName( archivoSqlite );

    if( db.open() )
        return true;

    return false;
}

void AdminDB::insertar() {
    // Abre la conexión a la base de datos
    if (!db.open()) {
        qDebug() << "No se pudo abrir la conexión a la base de datos.";
        return;
    }

    // Crear tabla lineas si no existe
    QSqlQuery createTableQuery("CREATE TABLE IF NOT EXISTS lineas (id INTEGER PRIMARY KEY AUTOINCREMENT, x_inicial INTEGER, y_inicial INTEGER, x_final INTEGER, y_final INTEGER)");
    if (!createTableQuery.exec()) {
        qDebug() << "Error al crear la tabla:" << createTableQuery.lastError().text();
        db.close(); // Cierra la conexión
        return;
    }

    // Verificar si ya hay registros en la tabla lineas
    QSqlQuery countQuery("SELECT COUNT(*) FROM lineas");
    if (!countQuery.exec()) {
        qDebug() << "Error al contar registros en la tabla:" << countQuery.lastError().text();
        db.close(); // Cierra la conexión
        return;
    }

    countQuery.next();
    int rowCount = countQuery.value(0).toInt();

    if (rowCount > 0) {
        qDebug() << "Ya existe al menos un registro en la tabla lineas. No se agregará otro.";
        db.close(); // Cierra la conexión
        return;
    }

    // Insertar una única línea en la tabla
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO lineas (x_inicial, y_inicial, x_final, y_final) VALUES (?, ?, ?, ?)");
    insertQuery.bindValue(0, 1);
    insertQuery.bindValue(1, 5);
    insertQuery.bindValue(2, 20);
    insertQuery.bindValue(3, 25);

    if (!insertQuery.exec()) {
        qDebug() << "Error al insertar en la tabla:" << insertQuery.lastError().text();
        db.close(); // Cierra la conexión
        return;
    }

    qDebug() << "Registro insertado correctamente.";

    db.close(); // Cierra la conexión
}

void AdminDB::leerLineas() {
    // Abre la conexión a la base de datos
    if (!db.open()) {
        qDebug() << "No se pudo abrir la conexión a la base de datos.";
        return;
    }

    // Ejecuta la consulta para obtener los datos de la tabla lineas
    QSqlQuery query("SELECT id, x_inicial, y_inicial, x_final, y_final FROM lineas");
    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        db.close(); // Cierra la conexión
        return;
    }

    // Muestra los datos de las líneas recuperadas
    qDebug() << "Líneas:";
    while (query.next()) {
        int id = query.value(0).toInt(); // Columna 0: id
        int x_inicial = query.value(1).toInt(); // Columna 1: x_inicial
        int y_inicial = query.value(2).toInt(); // Columna 2: y_inicial
        int x_final = query.value(3).toInt(); // Columna 3: x_final
        int y_final = query.value(4).toInt(); // Columna 4: y_final
        qDebug() << "ID:" << id << ", X Inicial:" << x_inicial << ", Y Inicial:" << y_inicial << ", X Final:" << x_final << ", Y Final:" << y_final;
    }

    db.close(); // Cierra la conexión
}

#include "linea.h"

Linea AdminDB::leerLinea() {
    Linea linea(0, 0, 0, 0); // Crea un objeto Linea con valores predeterminados

    // Abre la conexión a la base de datos
    if (!db.open()) {
        qDebug() << "No se pudo abrir la conexión a la base de datos.";
        return linea;
    }

    // Ejecuta la consulta para obtener los datos de la tabla lineas
    QSqlQuery query("SELECT id, x_inicial, y_inicial, x_final, y_final FROM lineas");
    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        db.close(); // Cierra la conexión
        return linea;
    }

    // Muestra los datos de la línea recuperada
    if (query.next()) {
        int id = query.value(0).toInt(); // Columna 0: id
        int x_inicial = query.value(1).toInt(); // Columna 1: x_inicial
        int y_inicial = query.value(2).toInt(); // Columna 2: y_inicial
        int x_final = query.value(3).toInt(); // Columna 3: x_final
        int y_final = query.value(4).toInt(); // Columna 4: y_final

        // Crea un objeto Linea con los datos recuperados
        linea = Linea(x_inicial, y_inicial, x_final, y_final);
    }

    db.close(); // Cierra la conexión
    return linea;
}

void AdminDB::modificarLinea(int id, int nuevoXInicial, int nuevoYInicial, int nuevoXFinal, int nuevoYFinal) {
    // Abre la conexión a la base de datos
    if (!db.open()) {
        qDebug() << "No se pudo abrir la conexión a la base de datos.";
        return;
    }

    // Prepara la consulta SQL de actualización
    QSqlQuery query;
    query.prepare("UPDATE lineas SET x_inicial = :xInicial, y_inicial = :yInicial, x_final = :xFinal, y_final = :yFinal WHERE id = :id");
    query.bindValue(":xInicial", nuevoXInicial);
    query.bindValue(":yInicial", nuevoYInicial);
    query.bindValue(":xFinal", nuevoXFinal);
    query.bindValue(":yFinal", nuevoYFinal);
    query.bindValue(":id", id);

    // Ejecuta la consulta
    if (!query.exec()) {
        qDebug() << "Error al modificar la línea:" << query.lastError().text();
    } else {
        qDebug() << "Línea modificada correctamente.";
    }

    db.close(); // Cierra la conexión
}



QSqlDatabase AdminDB::getDB()  {
    return db;
}

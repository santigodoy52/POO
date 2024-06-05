#include "admindb.h"
#include "rectangulo.h"

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
    /*QSqlQuery createTableQuery("CREATE TABLE IF NOT EXISTS rectangulos (id INTEGER PRIMARY KEY AUTOINCREMENT, x INTEGER, y INTEGER, ancho INTEGER, alto INTEGER)");
    if (!createTableQuery.exec()) {
        qDebug() << "Error al crear la tabla:" << createTableQuery.lastError().text();
        db.close(); // Cierra la conexión
        return;
    }

    // Verificar si ya hay registros en la tabla rectangulos
    QSqlQuery countQuery("SELECT COUNT(*) FROM rectangulos");
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
    }*/

    // Insertar una única línea en la tabla
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO rectangulos (x, y, ancho, alto) VALUES (?, ?, ?, ?)");
    insertQuery.bindValue(0, 100);
    insertQuery.bindValue(1, 100);
    insertQuery.bindValue(2, 150);
    insertQuery.bindValue(3, 250);

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
    QSqlQuery query("SELECT id, x, y, ancho, alto FROM rectangulos");
    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        db.close(); // Cierra la conexión
        return;
    }

    // Muestra los datos de las líneas recuperadas
    qDebug() << "Rectangulos:";
    while (query.next()) {
        int id = query.value(0).toInt(); // Columna 0: id
        int x = query.value(1).toInt(); // Columna 1: x_inicial
        int y = query.value(2).toInt(); // Columna 2: y_inicial
        int ancho = query.value(3).toInt(); // Columna 3: x_final
        int alto = query.value(4).toInt(); // Columna 4: y_final
        qDebug() << "ID:" << id << ", X :" << x << ", Y :" << y << ", ancho :" << ancho << ", Alto :" << alto;
    }

    db.close(); // Cierra la conexión
}


QVector<Rectangulo> AdminDB::leerRectangulos() {
    QVector<Rectangulo> rectangulos; // QVector para almacenar los rectángulos recuperados

    // Abre la conexión a la base de datos
    if (!db.open()) {
        qDebug() << "No se pudo abrir la conexión a la base de datos.";
        return rectangulos;
    }

    // Ejecuta la consulta para obtener los datos de la tabla rectangulos
    QSqlQuery query("SELECT id, x, y, ancho, alto FROM rectangulos");
    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        db.close(); // Cierra la conexión
        return rectangulos;
    }

    // Recorre los resultados de la consulta y agrega los rectángulos al QVector
    while (query.next()) {
        int id = query.value(0).toInt();     // Columna 0: id
        int x = query.value(1).toInt();      // Columna 1: x
        int y = query.value(2).toInt();      // Columna 2: y
        int ancho = query.value(3).toInt();  // Columna 3: ancho
        int alto = query.value(4).toInt();   // Columna 4: alto

        // Crea un objeto Rectangulo con los datos recuperados y agrégalo al QVector
        rectangulos.append(Rectangulo(x, y, ancho, alto));
    }

    db.close(); // Cierra la conexión
    return rectangulos;
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

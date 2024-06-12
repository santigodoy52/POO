#include "formulario.h"
#include "admindb.h"
#include <QDebug>

formulario::formulario(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    m_treeWidget = new QTreeWidget(this);
    setupTreeWidget();

    // Llenar la tabla con los usuarios al inicializar el formulario
    llenarUsuarios();

    layout->addWidget(m_treeWidget);
}

void formulario::setupTreeWidget()
{
    m_treeWidget->setColumnCount(3);
    QStringList headers;
    headers << "Usuario" << "Nombre Completo" << "Clave";
    m_treeWidget->setHeaderLabels(headers);
}

void formulario::llenarUsuarios()
{
    AdminDB admin;
    if (admin.conectar("D:/Usuario Lab/Documentos/ejercicio25/db.sqlite")) {
        QStringList usuarios = admin.obtenerUsuarios(); // Obtener la lista de usuarios desde la base de datos
        foreach(const QString &usuario, usuarios) {
            qDebug() << "Usuario obtenido:" << usuario; // Agrega un mensaje de depuración
            QStringList datosUsuario = usuario.split(" - Clave: "); // Separar el nombre de usuario y la clave
            agregarFila(datosUsuario); // Agregar la fila a la tabla
        }
    } else {
        qDebug() << "Error al conectar a la base de datos.";
    }
    admin.getDB().close(); // Cierra la conexión después de usarla
}


void formulario::agregarFila(const QStringList &datosUsuario)
{
    if (datosUsuario.size() != 1) {
        qDebug() << "Error: la lista de datos del usuario no tiene el formato esperado.";
        return;
    }

    QString usuario = datosUsuario.at(0);
    QStringList partes = usuario.split("||");
    if (partes.size() != 3) {
        qDebug() << "Error: los datos del usuario no tienen el formato esperado.";
        return;
    }

    QTreeWidgetItem *item = new QTreeWidgetItem(m_treeWidget);

    // Asigna cada parte a las columnas correspondientes
    item->setText(0, partes.at(0)); // Usuario
    item->setText(1, partes.at(1)); // Nombre Completo
    item->setText(2, partes.at(2)); // Clave

    m_treeWidget->addTopLevelItem(item);
}






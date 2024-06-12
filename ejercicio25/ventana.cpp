#include "ventana.h"
#include "admindb.h"
#include <QVBoxLayout>
#include <QDebug>

VentanaWidget::VentanaWidget(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Ventana");

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *nombreLabel = new QLabel("Nombre:", this);
    nombreEdit = new QLineEdit(this);
    layout->addWidget(nombreLabel);
    layout->addWidget(nombreEdit);

    QLabel *apellidoLabel = new QLabel("Apellido:", this);
    apellidoEdit = new QLineEdit(this);
    layout->addWidget(apellidoLabel);
    layout->addWidget(apellidoEdit);

    QLabel *passwordLabel = new QLabel("Password:", this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordEdit);

    agregarButton = new QPushButton("Agregar", this);
    layout->addWidget(agregarButton);

    connect(agregarButton, SIGNAL(clicked()), this, SLOT(agregarUsuario()));
}

QString VentanaWidget::getNombre() const {
    return nombreEdit->text();
}

QString VentanaWidget::getApellido() const {
    return apellidoEdit->text();
}

QString VentanaWidget::getPassword() const {
    return passwordEdit->text();
}

void VentanaWidget::agregarUsuario() {
    // Obtener los datos ingresados por el usuario
    QString username = nombreEdit->text();
    QString apellido = apellidoEdit->text();
    QString password = passwordEdit->text();

    // Crear una instancia de AdminDB
    AdminDB adminDB;

    // Conectar a la base de datos
    if (adminDB.conectar("D:/Usuario Lab/Documentos/Ejercicio25/db.sqlite")) {
        qDebug() << "Conexion exitosa";
        // Crear el nuevo usuario
        if (adminDB.crearUsuario(username, password, username + " " + apellido)) {
            qDebug() << "Usuario creado exitosamente";
            adminDB.mostrarUsuarios();
            close();
             adminDB.getDB().close();
        } else {
            qDebug() << "Error al crear el usuario";
        }

    } else {
        qDebug() << "Conexion NO exitosa";
    }
}

#include "login.h"
#include "admindb.h"
#include "ventana.h"

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Login");

    // Crear los widgets necesarios
    QLabel *userLabel = new QLabel("Usuario:", this);
    QLabel *passLabel = new QLabel("Clave:", this);
    userLineEdit = new QLineEdit(this);
    passLineEdit = new QLineEdit(this);
    passLineEdit->setEchoMode(QLineEdit::Password); // Para ocultar la contraseña

    QPushButton *loginButton = new QPushButton("Ingresar", this);

    // Crear el layout y añadir los widgets
    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(userLabel, 0, 0);
    layout->addWidget(passLabel, 1, 0);
    layout->addWidget(userLineEdit, 0, 1);
    layout->addWidget(passLineEdit, 1, 1);
    layout->addWidget(loginButton, 2, 1, 1, 1, Qt::AlignRight);

    // Conectar el botón de login a la función onLoginButtonClicked
    connect(loginButton, SIGNAL(clicked()), this, SLOT( slot_validarUsuario() ));
}

void LoginWidget::slot_validarUsuario() {
    // Obtener el nombre de usuario y la contraseña
    QString username = userLineEdit->text();
    QString password = passLineEdit->text();

    qDebug() << QDir::currentPath();

    AdminDB adminDB;
    if (adminDB.conectar( "D:/Usuario Lab/Documentos/ejercicio21/db.sqlite" ) )
    {
        qDebug() << "Conexion exitosa";
        adminDB.mostrarUsuarios();

        QString nombre = username;
        QString pass = password;

        if (adminDB.validarUsuario(nombre, pass)) {
            qDebug() << "Usuario válido.";
            this->close();
            emit signal_ingresar();
        } else {
            qDebug() << "Usuario inválido.";
        }
    }
    else
        qDebug() << "Conexion NO exitosa";
}

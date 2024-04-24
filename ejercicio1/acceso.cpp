#include "acceso.h"
#include "ventana.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QApplication>

Acceso::Acceso(QWidget *parent) : QWidget(parent), loginAttempts(0) {
    setFixedSize(400, 200);

    backgroundLabel = new QLabel(this);
    backgroundLabel->setScaledContents(true);
    userLabel = new QLabel("Usuario:", this);
    passLabel = new QLabel("Clave:", this);
    userLineEdit = new QLineEdit(this);
    passLineEdit = new QLineEdit(this);
    passLineEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Ingresar", this);

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(backgroundLabel, 0, 0, 1, 2, Qt::AlignCenter);
    layout->addWidget(userLabel, 1, 0, Qt::AlignCenter);
    layout->addWidget(userLineEdit, 1, 1);
    layout->addWidget(passLabel, 2, 0, Qt::AlignCenter);
    layout->addWidget(passLineEdit, 2, 1);
    layout->addWidget(loginButton, 3, 1, 1, 3, Qt::AlignLeft);

    setLayout(layout);

    connect(loginButton, SIGNAL(clicked()), this, SLOT(onLoginButtonClicked()));
}

void Acceso::setBackgroundImage(const QPixmap &image) {
    originalImage = image;
    backgroundLabel->setPixmap(originalImage.scaled(size()));
}

void Acceso::onLoginButtonClicked() {
    QString username = userLineEdit->text();
    QString password = passLineEdit->text();

    // Verificar credenciales
    if ((username == "admin" && password == "1234") ||
        (username == "user" && password == "4321")) {
        // Acceso exitoso
        QMessageBox::information(this, "Inicio de sesión", "Inicio de sesión exitoso.");
        hide(); // Ocultar la ventana de acceso
        emit loginSuccess(); // Emitir la señal de inicio de sesión exitoso

        // Mostrar la ventana Ventana con el saludo correspondiente
        Ventana *ventana = new Ventana;
        ventana->setSaludo(username);
        ventana->show();
    } else {
        // Credenciales incorrectas
        QMessageBox::warning(this, "Inicio de sesión", "Usuario o contraseña incorrectos.");
        passLineEdit->clear();
        ++loginAttempts;
        if (loginAttempts >= 3) {
            QMessageBox::critical(this, "Inicio de sesión", "Se han excedido los intentos de inicio de sesión.");
            qApp->quit(); // Cerrar la aplicación
        }
    }
}

// loginwindow.cpp
#include "login.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("Login");

    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Username");
    usernameEdit->setGeometry(50, 50, 200, 30);
    setMinimumSize(300, 230);

    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Password");
    passwordEdit->setGeometry(50, 100, 200, 30);
    passwordEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login", this);
    loginButton->setGeometry(50, 150, 200, 30);
    lbOpen = new QLabel("Crear usuario", this);
    lbOpen->setGeometry(50, 180, 200, 30);
    lbOpen->setStyleSheet("color: blue; text-decoration: underline;");

    connect(lbOpen, SIGNAL(clicked()), this, SLOT(openExtraWindow()));
    connect(loginButton, SIGNAL(clicked()), this, SLOT(attemptLogin()));
}

void LoginWindow::attemptLogin() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    // Verificar las credenciales (aquí deberías comparar con "admin" y "1234")
    if (username == "admin" && password == "1234") {
        VentanaWidget *ventana = new VentanaWidget;
        ventana->show();
        close();
    } else {
        // Mostrar mensaje de error o algo similar
    }
}

void LoginWindow::openForm() {
    form *formulario = new form;
    formulario->show();
}

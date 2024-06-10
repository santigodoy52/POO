// loginwindow.cpp
#include "login.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("Login");

    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Username");
    usernameEdit->setGeometry(50, 50, 200, 30);
    setMinimumSize(300, 200);

    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Password");
    passwordEdit->setGeometry(50, 100, 200, 30);
    passwordEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login", this);
    loginButton->setGeometry(50, 150, 200, 30);

    connect(loginButton, SIGNAL(clicked()), this, SLOT(attemptLogin()));
}

void LoginWindow::attemptLogin() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    // Verificar las credenciales (aquí deberías comparar con "admin" y "1234")
    if (username == "admin" && password == "1234") {
        HtmlWindow *htmlWindow = new HtmlWindow;
        htmlWindow->show();
        close();
    } else {
        // Mostrar mensaje de error o algo similar
    }
}

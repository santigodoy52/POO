// loginwindow.cpp
#include "login.h"
#include "admindb.h"
#include <QMouseEvent>

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
    lbOpen->setCursor(Qt::PointingHandCursor);

    connect(lbOpen, SIGNAL(clicked()), this, SLOT(openExtraWindow()));
    connect(loginButton, SIGNAL(clicked()), this, SLOT(attemptLogin()));
}

void LoginWindow::attemptLogin() {
    AdminDB adminDB;
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    if (adminDB.conectar("D:/Usuario Lab/Documentos/Ejercicio25/db.sqlite")) {
        if (adminDB.validarCredenciales(username, password)) {
            adminDB.mostrarUsuarios();
            qDebug() << "Usuario valido";
            VentanaWidget *ventana = new VentanaWidget;
            ventana->show();
            close();
        } else {
             qDebug() << "Usuario invalido";
        }
    }

}

void LoginWindow::openForm() {
    VentanaWidget *ventana = new VentanaWidget;
    ventana->show();
}

void LoginWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        if (event->pos().x() >= lbOpen->x() && event->pos().x() <= lbOpen->x() + lbOpen->width() &&
            event->pos().y() >= lbOpen->y() && event->pos().y() <= lbOpen->y() + lbOpen->height()) {
            openForm(); // Si se hizo clic dentro de los límites del QLabel, llama a openForm()
        }
    }
}

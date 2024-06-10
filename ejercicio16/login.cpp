#include "login.h"
#include "ventana.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>
#include <QPainter>

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Login");

    QLabel *backgroundLabel = new QLabel(this);

    // Descargar la imagen desde la URL
    QNetworkAccessManager *imageManager = new QNetworkAccessManager(this);
    imageManager->get(QNetworkRequest(QUrl("https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR3Nk4b7IND5VWE5Uma5FBucbCU8wt2Y-HJ3g&s")));
    connect(imageManager, SIGNAL(finished(QNetworkReply*)), this , SLOT(slot_imagen_descargada(QNetworkReply*)));


    QLabel *userLabel = new QLabel("Usuario:", this);
    QLabel *passLabel = new QLabel("Clave:", this);
    userLineEdit = new QLineEdit(this);
    passLineEdit = new QLineEdit(this);
    passLineEdit->setEchoMode(QLineEdit::Password);
    QPushButton *loginButton = new QPushButton("Ingresar", this);

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(backgroundLabel, 0, 0, 4, 2);
    layout->addWidget(userLabel, 0, 0);
    layout->addWidget(passLabel, 1, 0);
    layout->addWidget(userLineEdit, 0, 1);
    layout->addWidget(passLineEdit, 1, 1);
    layout->addWidget(loginButton, 2, 1, 1, 1, Qt::AlignRight);

    manager = new QNetworkAccessManager(this);
    connect(loginButton, SIGNAL(clicked()), this, SLOT(onLoginButtonClicked()));
}

void LoginWidget::onLoginButtonClicked() {
    // Simplemente se asume que la validación del usuario es correcta
    // Obtener el nombre de usuario y la contraseña
       QString username = userLineEdit->text();
       QString password = passLineEdit->text();

       QString nombre = username;
       QString pass = password;

           if (nombre == "admin" && password == "1111") {
               qDebug() << "Usuario válido.";
               // Crear una instancia del widget de ventana
               VentanaWidget *ventana = new VentanaWidget();
               ventana->show();
           } else {
               qDebug() << "Usuario inválido.";
           }
}


void LoginWidget::slot_imagen_descargada(QNetworkReply* response)
{
    fondo = QImage::fromData(response->readAll());
    this->repaint();
}

void LoginWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(!this->fondo.isNull()){
        painter.drawImage(0,0,fondo.scaled(this->width() , this->height() , Qt::KeepAspectRatioByExpanding));
    }
}

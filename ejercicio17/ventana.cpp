#include "ventana.h"
#include <QVBoxLayout>
#include <QPainter>
#include <QNetworkRequest>
#include <QNetworkReply>

VentanaWidget::VentanaWidget(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Ventana");

    backgroundLabel = new QLabel(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(backgroundLabel);
    this->setWindowState(Qt::WindowMaximized);

    // Descargar la imagen desde la URL
    QNetworkAccessManager *imageManager = new QNetworkAccessManager(this);
    imageManager->get(QNetworkRequest(QUrl("https://media.es.wired.com/photos/65845b5ea4076464da362974/16:9/w_2560%2Cc_limit/Science-Life-Extension-Drug-for-Big-Dogs-Is-Getting-Closer-1330545769.jpg")));
    connect(imageManager, SIGNAL(finished(QNetworkReply*)), this , SLOT(slot_imagen_descargada(QNetworkReply*)));
}

void VentanaWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(!this->fondo.isNull()){
        painter.drawImage(0,0,fondo.scaled(this->width() , this->height() , Qt::KeepAspectRatioByExpanding));
    }
}

void VentanaWidget::slot_imagen_descargada(QNetworkReply* response)
{
    fondo = QImage::fromData(response->readAll());
    this->repaint();
}

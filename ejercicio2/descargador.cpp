#include "descargador.h"
#include <QUrl>
#include <QDebug>
#include <QVBoxLayout>

Descargador::Descargador(QWidget *parent) : QWidget(parent) {
    urlLineEdit = new QLineEdit("http://cesarosimani.com.ar/cosillas/1.bmp", this);
    urlLineEdit->setReadOnly(true);

    descargarButton = new QPushButton("Descargar", this);
    connect(descargarButton, SIGNAL(clicked()), this, SLOT(onDownloadButtonClicked()));

    progressBar = new QProgressBar(this);
    progressBar->setRange(0, 100);
    progressBar->setValue(0);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *urlLayout = new QHBoxLayout();
    urlLayout->addWidget(urlLineEdit);
    urlLayout->addWidget(descargarButton);
    mainLayout->addLayout(urlLayout);
    mainLayout->addWidget(progressBar);

    setLayout(mainLayout);

    manager = new QNetworkAccessManager(this);

    setMinimumSize(600, 300);
}

void Descargador::onDownloadButtonClicked() {
    QString urlString = urlLineEdit->text();
    QUrl url(urlString);
    reply = manager->get(QNetworkRequest(url));

    connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));
    connect(reply, SIGNAL(finished()), this, SLOT(onDownloadFinished()));

    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onDownloadError(QNetworkReply::NetworkError)));
}

void Descargador::onDownloadProgress(qint64 bytesRecibidos, qint64 bytesTotales) {
    if (bytesTotales > 0) {
        int porcentaje = static_cast<int>((bytesRecibidos * 100) / bytesTotales);
        int valorActual = progressBar->value();
        int valorIntermedio = (valorActual + porcentaje) / 2;
        progressBar->setValue(valorIntermedio);
    }
}

void Descargador::onDownloadFinished() {
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error durante la descarga:" << reply->errorString();
        return;
    }

    progressBar->setValue(100);
    QByteArray imageData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(imageData);

    pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Background, pixmap);
    this->setAutoFillBackground(true);
    this->setPalette(palette);
}




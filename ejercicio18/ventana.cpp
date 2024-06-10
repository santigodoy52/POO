// htmlwindow.cpp
#include "ventana.h"

HtmlWindow::HtmlWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("HTML Viewer");
    setMinimumSize(500, 400); // Establecer un tamaño mínimo para la ventana

    htmlTextEdit = new QTextEdit(this);
    htmlTextEdit->setGeometry(10, 10, 480, 300); // Ajustar las geometrías del QTextEdit

    urlLineEdit = new QLineEdit(this);
    urlLineEdit->setPlaceholderText("Enter URL");
    urlLineEdit->setGeometry(10, 320, 480, 30); // Ajustar las geometrías del QLineEdit

    connect(urlLineEdit, SIGNAL(returnPressed()), this, SLOT(fetchHtml()));

    networkManager = new QNetworkAccessManager(this);
}

void HtmlWindow::fetchHtml() {
    QUrl url(urlLineEdit->text());
    QNetworkRequest request(url);
    QNetworkReply *reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray htmlData = reply->readAll();
            htmlTextEdit->setPlainText(htmlData);
        } else {
            // Manejar error al obtener el HTML
        }

        reply->deleteLater();
    });
}

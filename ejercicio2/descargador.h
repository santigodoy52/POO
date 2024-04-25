#ifndef DESCARGADOR_H
#define DESCARGADOR_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>
#include <QGridLayout>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Descargador : public QWidget {
    Q_OBJECT

public:
    explicit Descargador(QWidget *parent = nullptr);

    private slots:
        void onDownloadButtonClicked();
        void onDownloadProgress(qint64 bytesRecibidos, qint64 bytesTotales);
        void onDownloadFinished();


private:
    QLineEdit *urlLineEdit;
    QPushButton *descargarButton;
    QProgressBar *progressBar;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
};

#endif

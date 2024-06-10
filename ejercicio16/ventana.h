#ifndef VENTANAWIDGET_H
#define VENTANAWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QNetworkAccessManager>

class VentanaWidget : public QWidget {
    Q_OBJECT

public:
    VentanaWidget(QWidget *parent = nullptr);

public slots:
    void slot_imagen_descargada(QNetworkReply*);
protected:
    virtual void paintEvent(QPaintEvent *event) override;
private:
    QNetworkAccessManager *manager;
    QLabel *backgroundLabel;
    QImage fondo;
};

#endif // VENTANAWIDGET_H

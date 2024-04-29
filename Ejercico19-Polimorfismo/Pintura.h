// pintura.h
#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QPoint>
#include <QVector>
#include <QColor>

class Pintura : public QWidget
{
    Q_OBJECT

public:
    Pintura(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    QVector<QPoint> puntos;
    QColor colorPincel;
    int grosorPincel;

    void limpiarPantalla();
};

#endif // PINTURA_H

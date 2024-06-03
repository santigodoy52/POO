#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QPainter>
#include "linea.h"

namespace Ui {
class Principal;
}

class Principal : public QWidget
{
    Q_OBJECT

public:
    void setDatosLinea(int xInicial, int yInicial, int xFinal, int yFinal);
    explicit Principal(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~Principal();

private:
    Ui::Principal *ui;
    int m_xInicial;
        int m_yInicial;
        int m_xFinal;
        int m_yFinal;
};

#endif // PRINCIPAL_H

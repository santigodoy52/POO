#ifndef BOTON_H
#define BOTON_H

#include <QWidget>

class Boton : public QWidget {
    Q_OBJECT
public:
    enum Color { Azul, Verde, Magenta };

    explicit Boton(QWidget *parent = nullptr);

    void colorear(Color nuevoColor);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Color color;
};

#endif // BOTON_H

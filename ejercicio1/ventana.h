#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QLabel>

class Ventana : public QWidget {
    Q_OBJECT
public:
    Ventana(QWidget *parent = nullptr);
    void setSaludo(const QString &user);

private:
    QLabel *saludoLabel;
};

#endif // VENTANA_H

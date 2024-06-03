#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QDebug>
#include "instrumento.h"
#include "guitarra.h"

namespace Ui {
class Formulario;
}

class Formulario : public QWidget
{
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = nullptr);
    ~Formulario();

private slots:
    void on_boton_clicked();

private:
    Ui::Formulario *ui;
    QVector<Instrumento*> listaInstrumentos;
};

#endif // FORMULARIO_H

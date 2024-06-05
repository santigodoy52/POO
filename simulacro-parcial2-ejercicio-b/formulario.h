#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QDebug>
#include <QComboBox>
#include "instrumento.h"
#include "guitarra.h"
#include "viento.h"
#include "teclado.h"

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
      void on_boton_ver_stock_clicked();
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Formulario *ui;
    QVector<Instrumento*> listaInstrumentos;
};

#endif // FORMULARIO_H

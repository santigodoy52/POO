#include "ventana.h"
#include <QLabel>
#include <QVBoxLayout>

Ventana::Ventana(QWidget *parent) : QWidget(parent) {
    setFixedSize(400, 200);

    saludoLabel = new QLabel(this);
    saludoLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(saludoLabel);
    setLayout(layout);
}

void Ventana::setSaludo(const QString &user) {
    saludoLabel->setText("Hola " + user);
}

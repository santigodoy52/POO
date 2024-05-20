#include "ventana.h"
#include "login.h"

VentanaWidget::VentanaWidget(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Ventana");

    QPushButton *backButton = new QPushButton("Volver", this);

    // Crear el layout y añadir los widgets
    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(backButton, 2, 1, 1, 1, Qt::AlignRight);

    // Incrementar el tamaño de la fila y columna de la ventana
    layout->setColumnStretch(0, 1);
    layout->setRowStretch(0, 1);

    // Conectar el botón de login a la función onLoginButtonClicked
    connect(backButton, SIGNAL(clicked()), this, SLOT( backClicked() ));
}

void VentanaWidget::backClicked() {
   this->close();
   emit signal_volver();
}

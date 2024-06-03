#include "formulario.h"
#include "ui_formulario.h"

Formulario::Formulario(QWidget *parent) : QWidget(parent), ui(new Ui::Formulario)
{
    ui->setupUi(this);
    // Conectar el botón de login a la función on_boton_clicked
    connect(ui->pbAgregar, SIGNAL(clicked()), this, SLOT( on_boton_clicked() ));
}

void Formulario::on_boton_clicked() {
    // Crea un puntero a un objeto Instrumento
    Instrumento* instrumento = new Guitarra();
    // Agrega el puntero a la lista
    listaInstrumentos.append(instrumento);

    // Muestra la lista completa por consola
    qDebug() << "Lista de instrumentos:";
    for (Instrumento* inst : listaInstrumentos) {
        inst->afinar(); // Llama a la función afinar() del instrumento
    }
}

Formulario::~Formulario()
{
    delete ui;
}

#include "formulario.h"
#include "ui_formulario.h"

Formulario::Formulario(QWidget *parent) : QWidget(parent), ui(new Ui::Formulario)
{
    ui->setupUi(this);
    ui->cbLista->addItem("Guitarra");
    ui->cbLista->addItem("Viento");
    ui->cbLista->addItem("Teclado");
    // Conectar el botón de login a la función on_boton_clicked
    connect(ui->pbAgregar, SIGNAL(pressed()), this, SLOT(on_boton_clicked()));
    connect(ui->pbVerStock, SIGNAL(pressed()), this, SLOT(on_boton_ver_stock_clicked()));
    connect(ui->cbLista, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboBox_currentIndexChanged(int)));
}

void Formulario::on_boton_clicked() {
    // Determina el elemento seleccionado en el QComboBox
    QString elementoSeleccionado = ui->cbLista->currentText();

    // Crea y agrega los instrumentos según el elemento seleccionado
    if (elementoSeleccionado == "Guitarra") {
            Instrumento* guitarra = new Guitarra();
            listaInstrumentos.append(guitarra);
    }
    if (elementoSeleccionado == "Viento") {
            Instrumento* viento = new Viento();
            listaInstrumentos.append(viento);
    }
    if (elementoSeleccionado == "Teclado") {
        Instrumento* teclado = new Teclado();
        listaInstrumentos.append(teclado);
    }

}


void Formulario::on_comboBox_currentIndexChanged(int index) {
    QString elementoSeleccionado = ui->cbLista->itemText(index);
    qDebug() << "Elemento seleccionado:" << elementoSeleccionado;
    // Puedes agregar aquí el código para manejar la selección del elemento del ComboBox
}

void Formulario::on_boton_ver_stock_clicked() {
    // Muestra la lista completa por consola
    qDebug() << "Listado de stock de instrumentos :";
    for (Instrumento* inst : listaInstrumentos) {
        inst->afinar(); // Llama a la función afinar() del instrumento
    }
}

Formulario::~Formulario()
{
    delete ui;
}

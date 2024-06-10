#include "ventana.h"
#include <QRandomGenerator>
#include <QMessageBox>

VentanaWidget::VentanaWidget(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Ventana");

    // Crear los widgets necesarios
    legajoLabel = new QLabel("Legajo:", this);
    nombreLabel = new QLabel("Nombre:", this);
    apellidoLabel = new QLabel("Apellido:", this);
    captchaLabel = new QLabel(this);
    legajoLineEdit = new QLineEdit(this);
    nombreLineEdit = new QLineEdit(this);
    apellidoLineEdit = new QLineEdit(this);
    captchaLineEdit = new QLineEdit(this);
    ingresarButton = new QPushButton("Ingresar", this);

    // Generar un número aleatorio para el captcha
    int captchaNumber = QRandomGenerator::global()->bounded(1, 1001);
    captchaLabel->setText("Captcha: " + QString::number(captchaNumber));

    // Crear el layout y añadir los widgets
    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(legajoLabel, 0, 0);
    layout->addWidget(nombreLabel, 1, 0);
    layout->addWidget(apellidoLabel, 2, 0);
    layout->addWidget(captchaLabel, 3, 0);
    layout->addWidget(legajoLineEdit, 0, 1);
    layout->addWidget(nombreLineEdit, 1, 1);
    layout->addWidget(apellidoLineEdit, 2, 1);
    layout->addWidget(captchaLineEdit, 3, 1);
    layout->addWidget(ingresarButton, 4, 1, 1, 1, Qt::AlignRight);

    // Conectar el botón de ingresar a la función onIngresarButtonClicked
    connect(ingresarButton, SIGNAL(clicked()), this, SLOT(onIngresarButtonClicked()));

    // Guardar el número del captcha para comparar luego
    captchaNumber_ = captchaNumber;
}
void VentanaWidget::onIngresarButtonClicked() {
    // Obtener los valores de los campos de entrada
    QString legajo = legajoLineEdit->text();
    QString nombre = nombreLineEdit->text();
    QString apellido = apellidoLineEdit->text();
    QString captcha = captchaLineEdit->text();

    // Validar que ningún campo esté vacío
    if (legajo.isEmpty() || nombre.isEmpty() || apellido.isEmpty() || captcha.isEmpty()) {
        qDebug() << "Por favor, complete todos los campos.";
        return;
    }

    // Validar el captcha
    int captchaInput = captcha.toInt();
    if (captchaInput != captchaNumber_) {
        qDebug() << "Captcha incorrecto.";
        return;
    }

    // Si todos los campos están completos y el captcha es correcto, cerrar la aplicación
    qDebug() << "Ingreso exitoso. Cerrando la aplicación...";
    QCoreApplication::quit();
}


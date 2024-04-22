#ifndef BUSCADOR_H
#define BUSCADOR_H

#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

class Buscador : public QWidget {
public:
    Buscador(QWidget *parent = nullptr) : QWidget(parent) {
        // Configurar la ventana
        setWindowTitle("Buscador de Ocurrencias");
        setGeometry(100, 100, 400, 200);

        // Crear widgets
        text_edit = new QTextEdit(this);
        line_edit = new QLineEdit(this);
        result_label = new QLabel(this);
        search_button = new QPushButton("Buscar", this);
        file_name_edit = new QLineEdit(this);
        save_button = new QPushButton("Guardar", this);

        // Configurar diseño
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(text_edit);
        layout->addWidget(line_edit);
        layout->addWidget(search_button);
        layout->addWidget(result_label);
        layout->addWidget(file_name_edit);
        layout->addWidget(save_button);

        // Conectar señales y slots
        connect(search_button, &QPushButton::clicked, this, &Buscador::buscarOcurrencias);
        connect(save_button, &QPushButton::clicked, this, &Buscador::guardarTexto);
    }

private slots:
    void buscarOcurrencias() {
        QString textoBusqueda = line_edit->text();
        QString textoCompleto = text_edit->toPlainText();
        if (!textoBusqueda.isEmpty()) {
            int ocurrencias = textoCompleto.count(textoBusqueda);
            result_label->setText(QString("%1 ocurrencias.").arg(ocurrencias));
        } else {
            result_label->setText("Por favor, ingresa un texto de búsqueda.");
        }
    }

    void guardarTexto() {
            QString fileName = file_name_edit->text();
            if (fileName.isEmpty()) {
                QMessageBox::warning(this, "Advertencia", "Por favor, ingresa un nombre de archivo.");
                return;
            }

            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QMessageBox::critical(this, "Error", "No se puede abrir el archivo para escribir.");
                return;
            }

            QTextStream out(&file);
            out << text_edit->toPlainText();

            file.close();
            QMessageBox::information(this, "Guardado", "El texto se ha guardado correctamente en el archivo.");
        }

private:
    QTextEdit *text_edit;
    QLineEdit *line_edit;
    QLabel *result_label;
    QPushButton *search_button;
    QLineEdit *file_name_edit;
    QPushButton *save_button;
};

#endif // BUSCADOR_H

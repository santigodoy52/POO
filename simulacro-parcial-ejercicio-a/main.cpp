#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>

class CustomWidget : public QWidget {
public:
    CustomWidget(QWidget *parent = nullptr) : QWidget(parent) {
        setFixedSize(400, 400); // Tamaño fijo del widget
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        // Llamar al método base para que se realice el pintado predeterminado
        QWidget::paintEvent(event);

        QPainter painter(this);

        // Dibujar el cuadrado centrado
        int squareSize = 200; // Tamaño del cuadrado
        int squareX = (width() - squareSize) / 2; // Posición x del cuadrado
        int squareY = (height() - squareSize) / 2; // Posición y del cuadrado
        QRect squareRect(squareX, squareY, squareSize, squareSize);
        painter.drawRect(squareRect);

        // Cargar y dibujar la imagen dentro del cuadrado
        QPixmap image("C:/Users/LAB400-PCXX/Desktop/fondo.jpg"); // Ruta a tu imagen
        QRect imageRect(squareX + 10, squareY + 10, squareSize - 20, squareSize - 20); // Ajuste de posición y tamaño de la imagen
        painter.drawPixmap(imageRect, image);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear el cuadro de diálogo para el login
    QDialog loginDialog;
    loginDialog.setWindowTitle("Login");

    // Crear los widgets necesarios
    QLabel userLabel("Usuario:");
    QLabel passLabel("Clave:");
    QLineEdit userLineEdit;
    QLineEdit passLineEdit;
    passLineEdit.setEchoMode(QLineEdit::Password); // Para ocultar la contraseña

    QPushButton loginButton("Ingresar");

    // Crear el layout y añadir los widgets
    QGridLayout layout;
    layout.addWidget(&userLabel, 0, 0);
    layout.addWidget(&passLabel, 1, 0);
    layout.addWidget(&userLineEdit, 0, 1);
    layout.addWidget(&passLineEdit, 1, 1);
    layout.addWidget(&loginButton, 2, 1, 1, 14, Qt::AlignRight);
    loginDialog.setLayout(&layout);

    int loginAttempts = 1; // Contador de intentos de inicio de sesión

    // Crear CustomWidget fuera del ámbito de la función connect
    CustomWidget customWidget;

    // Conectar el botón de inicio de sesión
    QObject::connect(&loginButton, &QPushButton::clicked, [&]() {
        if(loginAttempts >= 3){
            QMessageBox::critical(&loginDialog, "Login", "Has excedido el número máximo de intentos.");
            loginDialog.reject(); // Cerrar la aplicación
        }else{
            // Verificar las credenciales
            if (userLineEdit.text() == "44347473" && passLineEdit.text() != "473") {
                ++loginAttempts; // Incrementar el contador de intentos de inicio de sesión
                 QMessageBox::warning(&loginDialog, "Login", "Contraseña incorrecta. Por favor, inténtalo de nuevo.");
                 passLineEdit.clear();
            }else{
                if (userLineEdit.text() == "44347473" && passLineEdit.text() == "473") {
                    QMessageBox::information(&loginDialog, "Login", "Inicio de sesión exitoso.");
                    loginDialog.accept(); // Cerrar el diálogo si las credenciales son correctas
                    customWidget.show(); // Mostrar el CustomWidget

                } else {
                    ++loginAttempts; // Incrementar el contador de intentos de inicio de sesión
                    QMessageBox::warning(&loginDialog, "Login", "Credenciales incorrectas. Por favor, inténtalo de nuevo.");
                    // Limpiar los campos de texto
                    userLineEdit.clear();
                    passLineEdit.clear();
                }
            }
        }
    });

    // Mostrar el diálogo de inicio de sesión
    loginDialog.show();

    return app.exec();
}

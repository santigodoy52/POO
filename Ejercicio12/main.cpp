#include <QApplication>
#include <QLabel>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear QLabel
    QLabel label;

    // Cargar imagen desde archivo
    QPixmap imagen("C:/Usuarios/Lab/Escritorio/500_333.jpeg");

    // Escalar imagen para ajustar al tamaño de la QLabel
    label.setPixmap(imagen.scaled(label.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Mostrar QLabel maximizada
    label.showMaximized();

    // Cerrar la aplicación después de 3 segundos
    QTimer::singleShot(3000, [&app]() {
        app.quit();
    });

    return app.exec();
}

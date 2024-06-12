#ifndef VENTANAWIDGET_H
#define VENTANAWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class VentanaWidget : public QWidget {
    Q_OBJECT

public:
    VentanaWidget(QWidget *parent = nullptr);
    QString getNombre() const;
    QString getApellido() const;
    QString getPassword() const;

private slots:
    void agregarUsuario();
signals:
    void usuarioAgregado(const QString& nombre, const QString& apellido, const QString& password);
private:
    QLineEdit *nombreEdit;
    QLineEdit *apellidoEdit;
    QLineEdit *passwordEdit;
    QPushButton *agregarButton;
};

#endif // VENTANAWIDGET_H

#ifndef VENTANAWIDGET_H
#define VENTANAWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>
#include <QCoreApplication>

class VentanaWidget : public QWidget {
    Q_OBJECT

public:
    explicit VentanaWidget(QWidget *parent = nullptr);

signals:
    void signal_volver();

private slots:
    void onIngresarButtonClicked();

private:
    QLabel *legajoLabel;
    QLabel *nombreLabel;
    QLabel *apellidoLabel;
    QLabel *captchaLabel;
    QLineEdit *legajoLineEdit;
    QLineEdit *nombreLineEdit;
    QLineEdit *apellidoLineEdit;
    QLineEdit *captchaLineEdit;
    QPushButton *ingresarButton;
    int captchaNumber_;
};

#endif // VENTANAWIDGET_H

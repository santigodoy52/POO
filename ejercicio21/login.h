#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

class LoginWidget : public QWidget {
    Q_OBJECT
public:
    explicit LoginWidget(QWidget *parent = nullptr);

signals:
    void signal_ingresar();

private slots:
    void slot_validarUsuario();

private:
    QLineEdit *userLineEdit;
    QLineEdit *passLineEdit;
};

#endif // LOGINWIDGET_H

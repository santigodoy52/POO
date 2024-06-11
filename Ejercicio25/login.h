// loginwindow.h
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include "ventana.h"
#include "form.h"
#include <QLabel>

class LoginWindow : public QMainWindow {
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);

private slots:
    void attemptLogin();
    void openForm();
private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QLabel *lbOpen;
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // LOGINWINDOW_H

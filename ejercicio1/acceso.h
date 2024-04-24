#ifndef ACCESO_H
#define ACCESO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QPixmap>

class Acceso : public QWidget {
    Q_OBJECT
public:
    Acceso(QWidget *parent = nullptr);

signals:
    void loginSuccess();

public slots:
    void setBackgroundImage(const QPixmap &image); // Declaración de la función

private slots:
    void onLoginButtonClicked();

private:
    QLabel *backgroundLabel;
    QLabel *userLabel;
    QLabel *passLabel;
    QLineEdit *userLineEdit;
    QLineEdit *passLineEdit;
    QPushButton *loginButton;
    QPixmap originalImage;
    int loginAttempts;
};

#endif // ACCESO_H

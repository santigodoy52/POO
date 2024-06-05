#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

class Login : public QWidget {
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);

signals:
    void loginClicked(const QString &username, const QString &password);
    void signal_ingresar();

private slots:
    void onLoginButtonClicked();

private:
    QLineEdit *userLineEdit;
    QLineEdit *passLineEdit;
};

#endif // LOGINWIDGET_H

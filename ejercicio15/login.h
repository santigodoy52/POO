#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QCoreApplication>
#include <QDebug>


class LoginWidget : public QWidget {
    Q_OBJECT
public:
    explicit LoginWidget(QWidget *parent = nullptr);

signals:
    void loginClicked(const QString &username, const QString &password);

private slots:
    void onLoginButtonClicked();

private:
    QLineEdit *userLineEdit;
    QLineEdit *passLineEdit;
};

#endif // LOGINWIDGET_H

#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QLineEdit>
#include <QNetworkReply>
#include <QImage>

QT_BEGIN_NAMESPACE
class QNetworkAccessManager;
class QNetworkReply;
QT_END_NAMESPACE

class LoginWidget : public QWidget {
    Q_OBJECT

public:
    LoginWidget(QWidget *parent = nullptr);

private slots:
    void onLoginButtonClicked();
    void slot_imagen_descargada(QNetworkReply*);

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    QNetworkAccessManager *manager;
    QImage fondo;
    QLineEdit *userLineEdit;
    QLineEdit *passLineEdit;
};

#endif // LOGINWIDGET_H

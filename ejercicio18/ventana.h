// htmlwindow.h
#ifndef HTMLWINDOW_H
#define HTMLWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPushButton>

class HtmlWindow : public QMainWindow {
    Q_OBJECT

public:
    HtmlWindow(QWidget *parent = nullptr);

private slots:
    void fetchHtml();

private:
    QTextEdit *htmlTextEdit;
    QLineEdit *urlLineEdit;
    QNetworkAccessManager *networkManager;
};

#endif // HTMLWINDOW_H

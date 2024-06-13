#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include "parser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Ventana; }
QT_END_NAMESPACE

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

private:
    Ui::Ventana *ui;
    Parser* parser;
    QString directorioRecursos;
    bool createDir(QString path);
    class Downloader* downloader;
private slots:
    void slot_obtenerRecursos();
    void slot_publicarRecursos(QHash<QString, Parser::Tipo>*);
};
#endif // VENTANA_H

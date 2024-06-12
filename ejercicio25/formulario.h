#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QTreeWidget>
#include <QVBoxLayout>

class formulario : public QWidget
{
    Q_OBJECT
public:
    formulario(QWidget *parent = nullptr);

private:
    QTreeWidget *m_treeWidget;

    void setupTreeWidget();
    void llenarUsuarios();
    void agregarFila(const QStringList &datosUsuario);
};

#endif // FORM_H

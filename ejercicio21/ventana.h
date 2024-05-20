#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

class VentanaWidget : public QWidget {
    Q_OBJECT
public:
    explicit VentanaWidget(QWidget *parent = nullptr);

signals:
    void signal_volver();
private slots:
    void backClicked();

private:
};


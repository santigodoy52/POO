#ifndef LINEA_H
#define LINEA_H

class Linea {
public:
    Linea(int xInicial, int yInicial, int xFinal, int yFinal);

    // Getters
    int getXInicial() const;
    int getYInicial() const;
    int getXFinal() const;
    int getYFinal() const;

    // Setters
    void setXInicial(int xInicial);
    void setYInicial(int yInicial);
    void setXFinal(int xFinal);
    void setYFinal(int yFinal);

private:
    int m_xInicial;
    int m_yInicial;
    int m_xFinal;
    int m_yFinal;
};

#endif // LINEA_H

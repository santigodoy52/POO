#ifndef RECTANGULO_H
#define RECTANGULO_H


class Rectangulo
{
public:
    Rectangulo(int x, int y, int ancho, int alto);

    // Getters
    int getX() const;
    int getY() const;
    int getAncho() const;
    int getAlto() const;

    // Setters
    void setX(int x);
    void setY(int y);
    void setAnchol(int ancho);
    void setAlto(int alto);

private:
    int x;
    int y;
    int ancho;
    int alto;
};

#endif // RECTANGULO_H

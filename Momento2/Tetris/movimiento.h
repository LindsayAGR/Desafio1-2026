#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

class Movimiento
{

private:
    int x;
    int y;
public:
    Movimiento();

    int getX();
    int getY();

    void izquierda();
    void derecha();
    void abajo();
};
#endif // MOVIMIENTO_H

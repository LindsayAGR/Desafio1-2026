#ifndef TABLERO_H
#define TABLERO_H
#include "figuras.h"

class Tablero
{
private:
    int ancho;
    int alto;
    int **matriz; //dinamica

public:


    Tablero(int a, int h);
    ~Tablero();

    void imprimir();
    void inicializar();

    void guardarFigura(Figuras &f, int x, int y);

    int getValor(int i, int j);
};

#endif // TABLERO_H

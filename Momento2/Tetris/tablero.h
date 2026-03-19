#ifndef TABLERO_H
#define TABLERO_H

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


};

#endif // TABLERO_H

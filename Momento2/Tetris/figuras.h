#ifndef FIGURAS_H
#define FIGURAS_H

class Figuras
{
private:
    int forma[4][4];

public:
    Figuras();

    void limpiar();

    void crearl();//(1x4)
    void crearO();//(2x2)
    void crearT();//(3X2)
    void crearS();//(3x2)
    void crearZ();//(3x2)
    void crearJ();//(2x3)
    void crearL();//(2x3)

    void imprimir();

    int getValor(int i, int j);
};

#endif // FIGURAS_H

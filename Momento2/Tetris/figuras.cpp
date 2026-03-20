#include "figuras.h"
#include <iostream>
using namespace std;

Figuras::Figuras() {

    limpiar();
}

void Figuras::limpiar()
{
    for(int i=0; i<4; i++)
        for (int j = 0; j < 4; j++)
            forma[i][j] = 0;
}

void Figuras::crearl()
{
    limpiar();
    forma[1][0]=1;
    forma[1][1]=1;
    forma[1][2]=1;
    forma[1][3]=1;
}

void Figuras::crearO()
{
    limpiar();
    forma[1][1]=1;
    forma[1][2]=1;
    forma[2][1]=1;
    forma[2][2]=1;
}

void Figuras::crearT()
{
    limpiar();
    forma[1][1]=1;
    forma[1][2]=1;
    forma[1][3]=1;
    forma[2][2]=1;

}

void Figuras::crearS()
{
    limpiar();
    forma[1][1]=1;
    forma[1][2]=1;
    forma[2][0]=1;
    forma[2][1]=1;
}

void Figuras::crearZ()
{
    limpiar();
    forma[1][0]=1;
    forma[1][1]=1;
    forma[2][1]=1;
    forma[2][2]=1;
}

void Figuras::crearJ()
{
    limpiar();
    forma[0][1]=1;
    forma[1][1]=1;
    forma[2][1]=1;
    forma[2][0]=1;
}

void Figuras::crearL()
{
    limpiar();
    forma[0][1]=1;
    forma[1][1]=1;
    forma[2][1]=1;
    forma[2][2]=1;
}

int Figuras::getValor(int i, int j)
{
    return forma[i][j];
}

void Figuras::rotar()
{

    int temp[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp[j][3-i] = forma[i][j];

        }

    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            forma[i][j]= temp[i][j];
        }
    }

}

void Figuras::crearAleatorio()
{
    limpiar();

    int r = rand() % 7;

    if(r == 0) crearl();
    else if(r == 1)crearO();
    else if(r == 2)crearT();
    else if(r == 3)crearS();
    else if(r == 4)crearZ();
    else if(r == 5)crearJ();
    else if(r == 6)crearL();

}








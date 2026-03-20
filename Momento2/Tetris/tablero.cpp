#include "tablero.h"
#include <iostream>
using namespace std;

Tablero::Tablero(int a, int h ) {

    ancho= a;
    alto= h;

    matriz = new int*[alto];
    for (int i = 0; i < alto; i++) {
        matriz[i] = new int[ancho];
    }
    inicializar();
}

Tablero::~Tablero()
{
    for (int i = 0; i < alto; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void Tablero::inicializar()
{

    cout <<"imprimiendo tablero..."<<endl;
    for(int i=0;i<alto;i++)
    {

        for(int j=0;j<ancho;j++){
            matriz[i][j]=0;

        }
    }

}

void Tablero::guardarFigura(Figuras &f, int x, int y)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if(f.getValor(i,j)==1)
            {
                matriz[y+i][x+j] = 1;
            }
        }

    }
}

int Tablero::getValor(int i, int j)
{
    return matriz[i][j];
}



void Tablero::imprimir()
{
    for (int i = 0; i < alto; i++) {
        cout<<"| ";
        for (int j = 0; j < ancho; j++) {

            if(matriz[i][j] == 0)
                cout<<". ";
            else
                cout<<"[]";

        }
        cout<<"|"<<endl;
    }

}

bool Tablero::hayColision(Figuras &f, int x, int y)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(f.getValor(i,j)==1)
            {
                int nuevaY = y + i + 1;
                int nuevaX = x + j;

                // TOCA EL FONDO
                if(nuevaY >= alto)
                    return true;

                // TOCA OTRA FIGURA
                if(matriz[nuevaY][nuevaX] == 1)
                    return true;
            }
        }
    }
    return false;
}

bool Tablero::hayColisionLateral(Figuras &f, int x, int y)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(f.getValor(i,j)==1)
            {
                int nx = x + j;

                if(nx < 0 || nx >= ancho)
                    return true;

                if(matriz[y+i][nx] == 1)
                    return true;
            }
        }
    }
    return false;
}

void Tablero::eliminarFilas()
{
    for(int i=alto-1; i>=0; i--)
    {
        bool llena = true;

        for(int j=0;j<ancho;j++)
        {
            if(matriz[i][j] == 0)
            {
                llena = false;
                break;
            }
        }

        if(llena)
        {
            // bajar todo
            for(int k=i; k>0; k--)
            {
                for(int j=0;j<ancho;j++)
                {
                    matriz[k][j] = matriz[k-1][j];
                }
            }

            // limpiar fila superior
            for(int j=0;j<ancho;j++)
                matriz[0][j] = 0;

            i++;//revisa otra vex
        }
    }
}

bool Tablero::gameOver(Figuras &f, int x, int y)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(f.getValor(i,j)==1)
            {
                if(matriz[y+i][x+j] == 1)
                    return true;
            }
        }
    }
    return false;
}


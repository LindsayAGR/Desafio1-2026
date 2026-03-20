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





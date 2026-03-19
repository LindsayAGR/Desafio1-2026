#include "tablero.h"
#include <iostream>
using namespace std;

Tablero::Tablero(int a, int h ) {

    ancho= a;
    alto= h;

    matriz = new int*[alto];
    for (int i = 0; i < alto; ++i) {
        matriz[i] = new int[ancho];
    }
    inicializar();
}

Tablero::~Tablero()
{
    for (int i = 0; i < alto; ++i) {
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



void Tablero::imprimir()
{
    for (int i = 0; i < alto; ++i) {
        cout<<"| ";
        for (int j = 0; j < ancho; ++j) {

            if(matriz[i][j] == 0)
                cout<<". ";
            else
                cout<<"[]";

        }
        cout<<"|"<<endl;
    }

}





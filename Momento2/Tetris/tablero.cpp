#include "tablero.h"
#include <iostream>
using namespace std;

Tablero::Tablero(int a, int h ) {

    ancho= a;
    alto= h;

}

void Tablero::imprimir(){

    cout <<"imprimiendo tablero..."<<endl;
    for(int i=0;i<alto;i++)
    {
        cout<<"| ";

        for(int j=0;j<ancho;j++){

            cout<<". ";

        }

        cout<<" |"<<endl;
    }

}

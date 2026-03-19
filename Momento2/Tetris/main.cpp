#include <iostream>
#include "figuras.h"
#include "Tablero.h"

using namespace std;

int main()
{
    int ancho = 8;
    int alto = 10;

    Tablero t(ancho, alto);
    Figuras f;

    f.crearT(); // prueba con cualquier figura

    int posX = 2; // posición fija
    int posY = 1;

    cout << "TABLERO CON FIGURA:\n" << endl;

    for(int i=0;i<alto;i++)
    {
        cout<<"| ";

        for(int j=0;j<ancho;j++)
        {
            bool hayFigura = false;

            // recorrer la figura (4x4)
            for(int fi=0;fi<4;fi++)
            {
                for(int fj=0;fj<4;fj++)
                {
                    if(f.getValor(fi,fj) == 1)
                    {
                        if(i == posY + fi && j == posX + fj)
                        {
                            hayFigura = true;
                        }
                    }
                }
            }

            if(hayFigura)
                cout<<"[]";
            else
                cout<<". ";
        }

        cout<<"|"<<endl;
    }

    cin.get();
    return 0;
}

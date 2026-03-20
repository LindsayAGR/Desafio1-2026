#include <iostream>
#include "Figuras.h"
#include "Tablero.h"
#include "Movimiento.h"

#include<cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int ancho, alto;

    cout << "Ingrese el ANCHO (multiplo de 8): ";
    cin >> ancho;

    while(ancho % 8 != 0)
    {
        cout << "Debe ser multiplo de 8: ";
        cin >> ancho;
    }

    cout << "Ingrese el ALTO: ";
    cin >> alto;

    Tablero t(ancho, alto);
    Figuras f;
    Movimiento m;

    f.crearAleatorio();

    char tecla;

    while(true)
    {
        cout << "\n\n";

        // DIBUJAR TABLERO + FIGURA
        for(int i=0;i<alto;i++)
        {
            cout<<"| ";

            for(int j=0;j<ancho;j++)
            {
                bool hayFigura = false;

                for(int fi=0;fi<4;fi++)
                {
                    for(int fj=0;fj<4;fj++)
                    {
                        if(f.getValor(fi,fj) == 1)
                        {
                            if(i == m.getY() + fi && j == m.getX() + fj)
                                hayFigura = true;
                        }
                    }
                }

                if(hayFigura)
                    cout<<"[]";
                else
                {
                    if(t.getValor(i,j)== 1)
                        cout<<"[]";
                    else
                        cout<<".";

                }
            }

            cout<<"|"<<endl;
        }

        cout << "\nX: " << m.getX() << " Y: " << m.getY() << endl;

        cout << "\nA: Izq | D: Der | S: Abajo | W: Rotar | Q: Salir\n";
        cin >> tecla;

        // MOVIMIENTO
        if(tecla == 'a' || tecla == 'A')
            m.izquierda();

        if(tecla == 'd' || tecla == 'D')
            m.derecha();

        if(tecla == 's' || tecla == 'S')
        {
            //  LÍMITE INFERIOR
            if(m.getY() < alto - 4)
            {
                m.abajo();
            }
            else
            {
                // TOCÓ FONDO  nueva figura

                t.guardarFigura(f, m.getX(), m.getY());
                m = Movimiento(); //nueva pos
                f.crearT(); // nueva fig
            }
        }

        // ROTACIÓN
        if(tecla == 'w' || tecla == 'W')
            f.rotar();

        if(tecla == 'q' || tecla == 'Q')
            break;
    }

    return 0;
}

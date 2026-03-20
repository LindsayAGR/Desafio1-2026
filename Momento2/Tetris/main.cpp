#include <iostream>
#include "Figuras.h"
#include "Tablero.h"
#include "Movimiento.h"

#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    char jugar = 's';

    while(jugar == 's' || jugar == 'S')
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

            // DIBUJAR TABLERO Y FIGURA
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
                            cout<<". ";
                    }
                }

                cout<<"|"<<endl;
            }

            cout << "\n X: " << m.getX() << " Y: " << m.getY() << endl;

            cout << "\n A: Izq | D: Der | S: Abajo | W: Rotar | Q: Salir\n";
            cin >> tecla;

            // MOVIMIENTO
            if(tecla == 'a' || tecla == 'A')
            {
                if(!t.hayColisionLateral(f, m.getX()-1, m.getY()))
                    m.izquierda();
            }

            if(tecla == 'd' || tecla == 'D')
            {
                if(!t.hayColisionLateral(f, m.getX()+1, m.getY()))
                    m.derecha();
            }

            if(tecla == 's' || tecla == 'S')
            {
                if(!t.hayColision(f, m.getX(), m.getY()))
                {
                    m.abajo();
                }
                else
                {
                    t.guardarFigura(f, m.getX(), m.getY());
                    t.eliminarFilas();

                    m = Movimiento();
                    f.crearAleatorio();

                    if(t.gameOver(f,m.getX(), m.getY()))
                    {
                        cout<<"GAME OVER"<<endl;
                        break;
                    }
                }
            }

            // ROTACIÓN
            if(tecla == 'w' || tecla == 'W')
                f.rotar();

            if(tecla == 'q' || tecla == 'Q')
                break;
        }

        cout << "\n¿Quieres jugar otra vez? (s/n): ";h
        cin >> jugar;
    }

    return 0;
}

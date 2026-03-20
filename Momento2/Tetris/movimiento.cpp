#include "movimiento.h"
#include <iostream>

using namespace std;

Movimiento::Movimiento() {
    x= 2;
    y= 0;
}

int Movimiento::getX()
{
    return x;
}

int Movimiento::getY()
{
    return y;
}

void Movimiento::izquierda()
{
    x--;
}

void Movimiento::derecha()
{
    x++;
}

void Movimiento::abajo()
{
    y++;
}


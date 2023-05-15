#pragma once
#include "Pieza.h"
#include "Tablero.h"

class Movimiento {
public:
    Movimiento();
    ~Movimiento();

    void setPieza(Pieza* pieza);
    bool validarMovimiento(float x, float y);
    bool mover(float x, float y);
    void moverIzquierda();
    void moverDerecha();
    void moverArriba();
    void moverAbajo();
    void setTablero(Tablero* tablero);

private:
    Pieza* pieza;
    Tablero* tablero;
};
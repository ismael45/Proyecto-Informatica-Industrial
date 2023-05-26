#pragma once
#include "Listapiezas.h"
#include "Tablero.h"

class Movimiento {
public:
    Movimiento();
    ~Movimiento();

    void setPieza(Pieza* pieza);
    bool validarMovimiento(Vector2D v);
    static Vector2D moverIzquierda(Vector2D);
    static Vector2D moverDerecha(Vector2D);
    static Vector2D moverArriba(Vector2D);
    static Vector2D moverAbajo(Vector2D);
    static Vector2D moverDiagDrcha(Vector2D);
    static Vector2D moverDiagIzq(Vector2D);
    //void setTablero(Tablero* tablero);
    

private:
    Tablero* tablero;
};
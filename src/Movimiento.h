#pragma once
#include "Listapiezas.h"
#include "Tablero.h"

class Movimiento {
public:
    Movimiento();
    ~Movimiento();

    void setPieza(Pieza* pieza);
    static bool validarMovimiento(Vector2D v);
    static void moverIzquierda(Pieza*);
    static void moverDerecha(Pieza*);
    static void moverArriba(Pieza*);
    static void moverAbajo(Pieza*);
    static void moverDiagDrcha(Pieza*);
    static void moverDiagIzq(Pieza*);
    //void setTablero(Tablero* tablero);
    

private:
    ListaPiezas piezas;
    Tablero* tablero;
};
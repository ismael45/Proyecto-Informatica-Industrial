#pragma once
#include "Pieza.h"

class Peon : public Pieza
{
  public:
    Peon() : Pieza() {}
    //void dibuja1();
    void dibuja_peonBlanco();
    void dibuja_peonNegro();
    //void dibuja_peon(); //La función para que se pase el color segun sea true o false (no esta implementada hayque esperar par aver como van los movimiento)

    //fichas para el otro tablero
    void dibuja_peonFlor();
    void dibuja_peonBosque();
    void mover_arriba() {
        float x = getPos().x;
        float y = getPos().y + 4;
        setPos(x, y);
        Peon::dibuja_peonFlor();
    }
};
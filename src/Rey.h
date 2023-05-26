#pragma once
#include "Pieza.h"

class Rey : public Pieza
{
public:
    Rey() : Pieza() {}
    void dibuja_reyBlanco();
    void dibuja_reyNegro();

    //fichas para el otro tablero
    void dibuja_reyFlor();
    void dibuja_reyBosque();

    void mover();
};
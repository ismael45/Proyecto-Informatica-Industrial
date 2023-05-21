#pragma once
#include "Pieza.h"

class Alfil : public Pieza
{
public:
    Alfil() : Pieza() {}
    void dibuja_alfilBlanco();
    void dibuja_alfilNegro();

    //fichas para el otro tablero
    void dibuja_alfilFlor();
    void dibuja_alfilBosque();

};
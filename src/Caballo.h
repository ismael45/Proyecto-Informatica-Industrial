#pragma once
#include "Pieza.h"

class Caballo : public Pieza
{
public:
    Caballo() : Pieza() {}
    void dibuja_caballoBlanco();
    void dibuja_caballoNegro();

};
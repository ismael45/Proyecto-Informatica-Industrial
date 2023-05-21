#pragma once
#include "Pieza.h"

class Rey : public Pieza
{
public:
    Rey() : Pieza() {}
    void dibuja_reyBlanco();
    void dibuja_reyNegro();

};
#pragma once
#include "Pieza.h"

class Torre : public Pieza
{
public:
    Torre() : Pieza() {}
    void dibuja_torreBlanca();
    void dibuja_torreNegra();

};
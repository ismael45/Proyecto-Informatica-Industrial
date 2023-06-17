#pragma once
#include "Pieza.h"

class Torre : public Pieza
{
public:
    Torre() : Pieza() { setValor(5.0f); }
    void dibuja();
};
#pragma once
#include "Pieza.h"

class Alfil : public Pieza
{
public:
    Alfil() : Pieza() { setValor(3.3f); }
    void dibuja();
};

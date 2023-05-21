#pragma once
#include "Pieza.h"

class Alfil : public Pieza
{
public:
    Alfil() : Pieza() {}
    void dibuja_alfilBlanco();
    void dibuja_alfilNegro();

};
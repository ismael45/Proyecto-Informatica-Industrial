#pragma once
#include "Pieza.h"

class Caballo : public Pieza
{
public:
    Caballo() : Pieza() { setValor(3.0f); }
    void dibuja();

    friend class ListaPiezas;
};
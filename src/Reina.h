#pragma once
#include "Pieza.h"

class Reina : public Pieza
{
public:
    Reina() : Pieza() { setValor(9.0f); }
    void dibuja();

    friend class ListaPiezas;
};
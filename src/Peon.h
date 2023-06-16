#pragma once
#include "Pieza.h"

class Peon : public Pieza
{
  public:
    Peon() : Pieza() {}
    void dibuja();
    bool movimiento( Vector2D destino);

};
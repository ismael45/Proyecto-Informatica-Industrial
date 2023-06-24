#pragma once
#include "Pieza.h"

class Peon : public Pieza
{
  public:
    Peon() : Pieza() { setValor(1.0f); }
    void dibuja();
   

};
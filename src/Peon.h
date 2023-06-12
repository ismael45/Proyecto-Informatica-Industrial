#pragma once
#include "Pieza.h"

class Peon : public Pieza
{
  public:
    Peon() : Pieza() {}

    void dibuja_peonBlanco();
    void dibuja_peonNegro();
   

    //fichas para el otro tablero
    void dibuja_peonFlor();
    void dibuja_peonBosque();

};
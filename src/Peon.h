#pragma once
#include "Pieza.h"

class Peon : public Pieza
{
  public:
    Peon() : Pieza() { setValor(1.0f); }
    void dibuja();
   
    //Para evaluar las capturas "En Passant"
    bool SalidaDobleReciente = false; //se activará cuando el peón haga un salto doble al salir, solo debe durar el primer turno del oponente.
    void setDoble();
    void resetDoble();
    bool getDoble();
};
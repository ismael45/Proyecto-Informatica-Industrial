#pragma once
#include "Pieza.h"

class Torre : public Pieza
{
    bool movido = false;
public:
    Torre() : Pieza() { setValor(5.0f); }
    void dibuja();

    void setMovido(); //cuando se mueva por primera vez, activarlo
    bool checkMovido(); //consultar estado, para evaluar si es posible el enroque

};
#pragma once
#include "Pieza.h"

class Rey : public Pieza
{
    bool enJaque;
    bool movido;

public:
    Rey() : Pieza() {}
    void dibuja();

    bool checkJaque(); //si tras un movimiento de tus piezas, esto devuelve true, el movimiento no es válido
    void setMovido(); //cuando se mueva por primera vez, activarlo
    bool checkMovido(); //consultar estado, para evaluar si es posible el enroque

};
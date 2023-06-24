#pragma once
#include "Pieza.h"

class Rey : public Pieza
{
   /* bool enJaque=false;
    bool movido=false;*/

public:
    Rey() : Pieza() {
    }
    void dibuja();

    //void setJaque();
    //void resetJaque();
    //bool checkJaque(); //si tras un movimiento de tus piezas, esto devuelve true, el movimiento no es válido
    //void setMovido(); //cuando se mueva por primera vez, activarlo
    //bool checkMovido(); //consultar estado, para evaluar si es posible el enroque

};
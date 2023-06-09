#pragma once
#include "Pieza.h"

class Reina : public Pieza
{
public:
    Reina() : Pieza() {}
    void dibuja_reinaBlanca();
    void dibuja_reinaNegra();

    //fichas para el otro tablero
    void dibuja_reinaFlor();
    void dibuja_reinaBosque();

};
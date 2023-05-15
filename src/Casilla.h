#pragma once
#include "ColorRGB.h"
#include "Vector2D.h"

typedef unsigned char Byte;

class Casilla {
public:
    Casilla();
    virtual ~Casilla();

    void setColor(Byte r, Byte g, Byte b);
    void setPos(float x, float y);
    void dibuja();

private:
    ColorRGB color_tab;
    Vector2D posicion;
    float tamaño;
   
};



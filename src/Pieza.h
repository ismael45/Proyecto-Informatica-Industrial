#pragma once
#include "ColorRGB.h"
#include "Vector2D.h"

typedef unsigned char Byte;

class Pieza {
public:
    Pieza();
    virtual ~Pieza();

    void setColor(Byte r, Byte g, Byte b);
    void setPos(float x, float y);
    void dibuja();
    Vector2D getPos() const;


protected:
    ColorRGB color;
    Vector2D posicion;
    float tamaño;
};
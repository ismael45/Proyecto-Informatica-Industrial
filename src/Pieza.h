#pragma once
#include "ColorRGB.h"
#include "Vector2D.h"
#include "ETSIDI.h"
#include "freeglut.h"

typedef unsigned char Byte;

class Pieza {
public:

    Pieza();
    virtual ~Pieza();



    void setColor(Byte r, Byte g, Byte b);
    void setPos(float x, float y);
    void dibuja();
    Vector2D getPos() const;



    void mover_arriba();
    void mover_abajo();
    void mover_izquierda();
    void mover_derecha();


protected:
    ColorRGB color;
    Vector2D posicion;
    float tamaño;
    ETSIDI::Sprite sprite{ "bin/imagenes/fondo.png", 0.0, 0.0, 3, 3.5 };
};
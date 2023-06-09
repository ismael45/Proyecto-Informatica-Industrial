#pragma once
#include "ColorRGB.h"
#include "Vector2D.h"
#include "ETSIDI.h"


typedef unsigned char Byte;

class Pieza {
public:

    //Pieza(bool _color) : colour(_color) {  }
    Pieza();
    virtual ~Pieza();

    //virtual void inicializa(Vector2D _pos, bool _color) { posicion = _pos, color = _color; }
    void dibuja1() {}

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
    bool colour;

    ETSIDI::Sprite sprite{ "bin/imagenes/fondo.png", 0.0, 0.0, 3, 3.5 };
};
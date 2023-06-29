#pragma once
#include "ColorRGB.h"
#include "Vector2D.h"
#include <string>


typedef unsigned char Byte;

using namespace std;
class Casilla {
public:
    Casilla();
    virtual ~Casilla();

    void setColor(Byte r, Byte g, Byte b);
    void setPos(float x, float y);
    void setCodigo(char i);
    Vector2D getPos();
    void dibuja();
    string getCodigo();
    bool operator==(Casilla& rhs);


private:
    ColorRGB color;
    Vector2D posicion;
    float tamaño;
    string codigo; //Para la codificación de cada casilla
};



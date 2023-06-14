#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"


typedef unsigned char Byte;

typedef enum Color {NOCOLOR=0,BLANCAS,NEGRAS};
typedef enum Tipo{NOTIPO=0,FLORES,CLASICAS};

class Pieza {
public:

    Pieza();
    virtual ~Pieza();

    void setColor(Color c);
    void setTipo(Tipo t);

    void setPos(float x, float y);
    Vector2D getPos() const;

    virtual void dibuja()=0;
    
 
    void mover_arriba();
    void mover_abajo();
    void mover_izquierda();
    void mover_derecha();


protected:
    Color color;
    Tipo tipo;

    float tama�o;
    Vector2D posicion;



    ETSIDI::Sprite sprite{ "bin/imagenes/fondo.png", 0.0, 0.0, 3, 3.5 };
};
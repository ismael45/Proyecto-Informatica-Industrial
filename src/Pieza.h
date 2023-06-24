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

    void setValor(float v);

    Color getColor();

    Vector2D getPos() const;

    float getValor();
    bool checkViviente();
    void resetViviente();
    void setViviente();

    
    //virtual void dibuja()=0;
    
 
    void mover_arriba();
    void mover_abajo();
    void mover_izquierda();
    void mover_derecha();

    //Para evaluar las capturas "En Passant"
    
    void setDoble();
    void resetDoble();
    bool getDoble();

    //Para evaluar jaques o enroques

    void setJaque();
    void resetJaque();
    bool checkJaque(); //si tras un movimiento de tus piezas, esto devuelve true, el movimiento no es v�lido
    void setMovido(); //cuando se mueva por primera vez, activarlo
    bool checkMovido(); //consultar estado, para evaluar si es posible el enroque

protected:

    bool SalidaDobleReciente = false; //se activar� cuando el pe�n haga un salto doble al salir, solo debe durar el primer turno del oponente.

    bool enJaque = false;
    bool movido = false;

    Color color;
    Tipo tipo;

    float tama�o;
    Vector2D posicion;

    float valor;
    bool viviente= true; //para desactivar todas sus funciones cuando est� en el "cementerio".
    //por defecto, todas las piezas se crean vivas, excepto las damas en potencia

    ETSIDI::Sprite sprite{ "bin/imagenes/fondo.png", 0.0, 0.0, 3, 3.5 };
};
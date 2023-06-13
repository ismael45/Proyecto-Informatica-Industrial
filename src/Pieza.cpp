#include "Pieza.h"


Pieza::Pieza() {

    tamaño = 2.0f;
    posicion = { 0.0f, 0.0f };
    tipo = NOTIPO;
    color = NOCOLOR;
}


Pieza::~Pieza() {}

void Pieza::setColor(Color c) {
    color = c;
}

void Pieza::setTipo(Tipo t) {
    tipo = t;
}

void Pieza::setPos(float x, float y) {
    posicion.x = x;
    posicion.y = y;
}

Vector2D Pieza::getPos() const {
    return posicion;
}


void Pieza::mover_arriba() {
    float x = getPos().x;
    float y = getPos().y + 4;
    setPos(x, y);
}

void Pieza::mover_abajo() {
    float x = getPos().x;
    float y = getPos().y - 4;
    setPos(x, y);

}

void Pieza::mover_izquierda() {
    float x = getPos().x - 4;
    float y = getPos().y;
    setPos(x, y);

}

void Pieza::mover_derecha() {
    float x = getPos().x + 4;
    float y = getPos().y;
    setPos(x, y);

}
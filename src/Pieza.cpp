#include "Pieza.h"


Pieza::Pieza() {
    color.r = 255;
    color.g = 255;
    color.b = 255;
    tama�o = 2.0f;
    posicion = { 0.0f, 0.0f };
}


Pieza::~Pieza() {}

void Pieza::setColor(Byte r, Byte g, Byte b) {
    color.r = r;
    color.g = g;
    color.b = b;
}

void Pieza::setPos(float x, float y) {
    posicion.x = x;
    posicion.y = y;
}

Vector2D Pieza::getPos() const {
    return posicion;
}

void Pieza::dibuja() {
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0.5);
    glColor3f(color.r, color.g, color.b);
    glutSolidSphere(tama�o, 20, 20);
    glPopMatrix();
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
    float x = getPos().x-4;
    float y = getPos().y;
    setPos(x, y);

}

void Pieza::mover_derecha() {
    float x = getPos().x+4;
    float y = getPos().y;
    setPos(x, y);

}

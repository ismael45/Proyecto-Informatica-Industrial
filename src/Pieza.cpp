#include "Pieza.h"
#include "freeglut.h"

Pieza::Pieza() {
    color.r = 255;
    color.g = 255;
    color.b = 255;
    tamaño = 2.0f;
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
    glutSolidSphere(tamaño, 20, 20);
    glPopMatrix();
}

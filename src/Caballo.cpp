#include "Caballo.h"

void Caballo::dibuja_caballo() {
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0.5);
    glColor3f(color.r, color.g, color.b);
    glutSolidTeapot(tamaño);
    glPopMatrix();
}

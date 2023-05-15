#include "Torre.h"

void Torre::dibuja_torre() {
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 2);
    glColor3f(color.r, color.g, color.b);
    glutSolidCube(tamaño);
    glPopMatrix();
}


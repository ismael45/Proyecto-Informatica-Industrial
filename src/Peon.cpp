#include "Peon.h"

void Peon::dibuja_peon() {
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0.5);
    glColor3f(color.r, color.g, color.b);
    glutSolidSphere(tamaño, 20, 20);
    glPopMatrix();
}


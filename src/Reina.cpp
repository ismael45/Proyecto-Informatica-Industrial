#include "Reina.h"

void Reina::dibuja_reina() {
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 3);
    glColor3f(color.r, color.g, color.b);
    glutSolidOctahedron();
    glPopMatrix();
}


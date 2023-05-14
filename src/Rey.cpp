#include "Rey.h"

void Rey::dibuja_rey() {
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 3);
    glColor3f(color.r, color.g, color.b);
    glutSolidTetrahedron();
    glPopMatrix();
}


#include "Alfil.h"

void Alfil::dibuja_alfil() {
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 2);
    glColor3f(color.r, color.g, color.b);
    glutSolidDodecahedron();
    glPopMatrix();
}

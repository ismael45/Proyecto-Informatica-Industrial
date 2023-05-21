#include "Alfil.h"


void Alfil::dibuja_alfilBlanco()
{
    sprite = { "bin/imagenes/Alfil_blanco.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };

    glPushMatrix();
    glTranslatef(0, 0, 2);
    sprite.draw();
    glPopMatrix();
}

void Alfil::dibuja_alfilNegro()
{
    sprite = { "bin/imagenes/Alfil_negro.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };

    glPushMatrix();
    glTranslatef(0, 0, 2);
    sprite.draw();
    glPopMatrix();
}

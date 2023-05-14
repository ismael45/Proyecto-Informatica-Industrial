#include "Peon.h"

void Peon::dibuja()
{
    if (color)
        sprite = { "bin/imagenes/peon_negras.png", pos.x + 0.05f, pos.y + 0.075f , 11, 3.5 };
    else
        sprite = { "bin/imagenes/peon_blancas.png", pos.x + 0.05f, pos.y + 0.12f , 11, 3.5 };

    glPushMatrix();
    glTranslatef(0, 0, 0.002);
    sprite.draw();
    glPopMatrix();
}

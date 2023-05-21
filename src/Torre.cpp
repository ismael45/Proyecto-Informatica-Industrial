#include "Torre.h"


void Torre::dibuja_torreBlanca()
{
    sprite = { "bin/imagenes/Torre_blanca.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };

    glPushMatrix();
    glTranslatef(0, 0, 2);
    sprite.draw();
    glPopMatrix();
}

void Torre::dibuja_torreNegra()
{
    sprite = { "bin/imagenes/Torre_negra.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };

    glPushMatrix();
    glTranslatef(0, 0, 2);
    sprite.draw();
    glPopMatrix();
}

void Torre::dibuja_torreFlor()
{
    sprite = { "bin/imagenes/Torre_flor.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };

    glPushMatrix();
    glTranslatef(0, 0, 2);
    sprite.draw();
    glPopMatrix();
}

void Torre::dibuja_torreBosque()
{
    sprite = { "bin/imagenes/Torre_bosque.png", posicion.x + 0.07f, posicion.y - 0.03f, 4, 4.5 };

    glPushMatrix();
    glTranslatef(0, 0, 2);
    sprite.draw();
    glPopMatrix();
}

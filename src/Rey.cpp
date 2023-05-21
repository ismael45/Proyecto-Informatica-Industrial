#include "Rey.h"

void Rey::dibuja_reyBlanco()
{
	sprite = { "bin/imagenes/Rey_blanco.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();
}

void Rey::dibuja_reyNegro()
{
	sprite = { "bin/imagenes/Rey_negro.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();
}

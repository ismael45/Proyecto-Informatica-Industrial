#include "Reina.h"


void Reina::dibuja_reinaBlanca()
{
	sprite = { "bin/imagenes/Reina_blanca.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();
}

void Reina::dibuja_reinaNegra()
{
	sprite = { "bin/imagenes/Reina_negra.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();
}

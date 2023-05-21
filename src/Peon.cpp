#include "Peon.h"

void Peon::dibuja_peonBlanco() {

		sprite = { "bin/imagenes/Peon_blanco.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };
	
	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();
	

}
void Peon::dibuja_peonNegro() {

		sprite = { "bin/imagenes/Peon_negro.png", posicion.x + 0.07f, posicion.y - 0.1f, 3, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();

}

//función que se hace con el constructor que pasa true o false segun sea negro o blanco
void Peon::dibuja_peon()
{
	if (colour)
		sprite = { "bin/imagenes/Peon_negro.png", posicion.x + 0.57f, posicion.y - 0.1f, 11, 3.5 };
	else
		sprite = { "bin/imagenes/Peon_blanco.png", posicion.x + 0.07f, posicion.y - 0.03f, 5, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();

}

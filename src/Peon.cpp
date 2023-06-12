#include "Peon.h"

void Peon::dibuja_peonBlanco(){

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

void Peon::dibuja_peonFlor()
{
	sprite = { "bin/imagenes/Peon1_flor.png", posicion.x + 0.07f, posicion.y - 0.1f, 2.5, 2 };

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();

}

void Peon::dibuja_peonBosque()
{

	sprite = { "bin/imagenes/Peon_bosque.png", posicion.x + 0.07f, posicion.y - 0.1f, 4, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();

}


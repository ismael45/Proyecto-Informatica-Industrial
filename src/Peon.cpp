#include "Peon.h"

void Peon::dibuja() {
	if (color == BLANCAS) {
		if (tipo == FLORES)
			sprite = { "bin/imagenes/Peon1_flor.png", posicion.x + 0.07f, posicion.y - 0.1f, 2.5, 2 };
	}
	if (color == NEGRAS) {
		if (tipo == FLORES)
			sprite = { "bin/imagenes/Peon_bosque.png", posicion.x + 0.07f, posicion.y - 0.1f, 4, 3.5 };
	}
	if (color == BLANCAS) {
		if (tipo == CLASICAS)
			sprite = { "bin/imagenes/Peon_blanco.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };
	}
	if (color == NEGRAS) {
		if (tipo == CLASICAS)
			sprite = { "bin/imagenes/Peon_negro.png", posicion.x + 0.07f, posicion.y - 0.1f, 3, 3.5 };
	}

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();
}






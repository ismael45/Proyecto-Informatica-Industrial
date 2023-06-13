#include "Alfil.h"

void Alfil::dibuja() {
	if (color == BLANCAS) {
		if (tipo == FLORES)
			sprite = { "bin/imagenes/Alfil_flor.png", posicion.x + 0.07f, posicion.y - 0.03f, 2, 3 };
	}
	else if (color == NEGRAS) {
		if (tipo == FLORES)
			sprite = { "bin/imagenes/Alfil_bosque.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };
	}
	if (color == BLANCAS) {
		if (tipo == CLASICAS)
			sprite = { "bin/imagenes/Alfil_blanco.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };
	}
	if (color == NEGRAS) {
		if (tipo == CLASICAS)
			sprite = { "bin/imagenes/Alfil_negro.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };
	}

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();
}





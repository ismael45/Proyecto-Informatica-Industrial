#include "Caballo.h"

void Caballo::dibuja() {
	if (color == BLANCAS) {
		if (tipo == FLORES)
			sprite = { "bin/imagenes/Caballo_flor.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3 };
	}
	if (color == NEGRAS) {
		if (tipo == FLORES)
			sprite = { "bin/imagenes/Caballo_bosque.png", posicion.x + 0.07f, posicion.y - 0.03f, 3.5, 4 };
	}
	if (color == BLANCAS) {
		if (tipo == CLASICAS)
			sprite = { "bin/imagenes/Caballo_blanco.png", posicion.x + 0.07f, posicion.y - 0.03f, 3.5, 4 };
	}
	if (color == NEGRAS) {
		if (tipo == CLASICAS)
			sprite = { "bin/imagenes/Caballo_negro.png", posicion.x + 0.07f, posicion.y - 0.03f, 3.5, 4 };
	}

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();
}

#include "Reina.h"

void Reina::dibuja() {
	if (color == BLANCAS) {
		if (tipo == FLORES)
			sprite = { "bin/imagenes/Reina_flor.png", posicion.x + 0.07f, posicion.y - 0.03f, 2.5, 3 };
	}
	if (color == NEGRAS) {
		if (tipo == FLORES)
			sprite = { "bin/imagenes/Reina_bosque.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };
	}
	if (color == BLANCAS) {
		if (tipo == CLASICAS)
			sprite = { "bin/imagenes/Reina_blanca.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };
	}
	if (color == NEGRAS) {
		if (tipo == CLASICAS)
			sprite = { "bin/imagenes/Reina_negra.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };
	}

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();
}

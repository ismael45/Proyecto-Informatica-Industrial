#include "Rey.h"

void Rey::dibuja() {
	if (color == BLANCAS) {
		if (tipo == FLORES)
			sprite = { "bin/imagenes/Rey_flor.png", posicion.x + 0.07f, posicion.y - 0.03f, 2, 3 };
	}
	if (color == NEGRAS) {
		if (tipo == FLORES)
			sprite = { "bin/imagenes/Rey_bosque.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };
	}
	if (color == BLANCAS) {
		if (tipo == CLASICAS)
			sprite = { "bin/imagenes/Rey_blanco.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };
	}
	if (color == NEGRAS) {
		if (tipo == CLASICAS)
			sprite = { "bin/imagenes/Rey_negro.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };
	}

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();
}


bool Rey::checkJaque() {
	if (enJaque) return true;
}
void Rey::setJaque() {
	enJaque = true;
}
void Rey::resetJaque() {
	enJaque = false;
}


bool Rey::checkMovido() {
	if (movido) return true;
}

void Rey::setMovido() {
	movido = true;
}

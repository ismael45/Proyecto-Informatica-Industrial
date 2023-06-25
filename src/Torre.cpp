#include "Torre.h"

void Torre::dibuja() {
	if (color == BLANCAS) {
		if (tipo == FLORES)
			sprite = { "bin/imagenes/Torre_flor.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };
	}
	if (color == NEGRAS) {
		if (tipo == FLORES)
			sprite = { "bin/imagenes/Torre_bosque.png", posicion.x + 0.07f, posicion.y - 0.03f, 4, 4.5 };
	}
	if (color == BLANCAS) {
		if (tipo == CLASICAS)
			sprite = { "bin/imagenes/Torre_blanca.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };
	}
	if (color == NEGRAS) {
		if (tipo == CLASICAS)
			sprite = { "bin/imagenes/Torre_negra.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3.5 };
	}

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();
}

//bool Torre::checkMovido() {
//	if (movido) return true;
//}
//
//void Torre::setMovido() {
//	movido = true;
//}
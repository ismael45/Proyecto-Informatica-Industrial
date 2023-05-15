#include "Movimiento.h"
#include <cmath>

Movimiento::Movimiento() {}

Movimiento::~Movimiento() {}

void Movimiento::setPieza(Pieza* p) {
	p->dibuja();
}

bool Movimiento::validarMovimiento(float x, float y) {
	if (mover(x, y) == true)
		return true;
	else
		return false;
}


bool Movimiento::mover(float x, float y) {
	if (tablero->estaDentroTablero(x, y) == true)
	{
		pieza->setPos(x, y);
		return true;
	}
	else
		return false;
}

void Movimiento::setTablero(Tablero* tablero) {
	tablero->dibujaTab();
}

void Movimiento::moverIzquierda() {
	pieza->setPos(pieza->getPos().x - 4, pieza->getPos().y);
}

void Movimiento::moverDerecha() {
	pieza->setPos(pieza->getPos().x + 4,pieza->getPos().y);
}

void Movimiento::moverArriba() {
	pieza->setPos(pieza->getPos().x, pieza->getPos().y + 4);
}

void Movimiento::moverAbajo() {
	pieza->setPos(pieza->getPos().x, pieza->getPos().y - 4);
	
}
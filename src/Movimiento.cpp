#include "Movimiento.h"
#include <cmath>

Movimiento::Movimiento() {}

Movimiento::~Movimiento() {}

void Movimiento::setPieza(Pieza* p) {
	p->dibuja();
}

bool Movimiento::validarMovimiento(Vector2D v) {
	if (tablero->estaDentroTablero(v.x, v.y) == true)
		return true;
	else
		return false;
}


//void Movimiento::setTablero(Tablero* tablero) {
//	tablero->dibujaTab_clasico();
//}

void Movimiento::moverIzquierda(Pieza* pieza) {
	Vector2D aux;
	aux.x = pieza->getPos().x - 4;
	aux.y = pieza->getPos().y;
	if (validarMovimiento(aux) == true)
	{
		pieza->setPos(aux.x, aux.y);
	}
	else pieza->setPos(pieza->getPos().x, pieza->getPos().y);
}

void Movimiento::moverDerecha(Vector2D vec) {
	Vector2D aux;
	aux.x = pieza->getPos().x + 4;
	aux.y = pieza->getPos().y;
	if (validarMovimiento(aux) == true)
	{
		pieza->setPos(aux.x, aux.y);
	}
	else pieza->setPos(pieza->getPos().x, pieza->getPos().y);
}

void Movimiento::moverArriba(Pieza* pieza) {
	Vector2D aux;
	aux.x = pieza->getPos().x;
	aux.y = pieza->getPos().y + 4;
	if (validarMovimiento(aux) == true)
	{
		pieza->setPos(aux.x, aux.y);
	}
	else pieza->setPos(pieza->getPos().x, pieza->getPos().y);
}

void Movimiento::moverAbajo(Pieza* pieza) {
	Vector2D aux;
	aux.x = pieza->getPos().x;
	aux.y = pieza->getPos().y - 4;
	if (validarMovimiento(aux) == true)
	{
		pieza->setPos(aux.x, aux.y);
	}
	else pieza->setPos(pieza->getPos().x, pieza->getPos().y);
}

void Movimiento::moverDiagDrcha(Pieza* pieza) {
	moverDerecha(pieza);
	if(pieza->getPos().x<0)//probando
		moverArriba(pieza);
}
void Movimiento::moverDiagIzq(Pieza* pieza) {
	moverIzquierda(pieza);
	if (pieza->getPos().x < 0)//probando
		moverArriba(pieza);
}
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

Vector2D Movimiento::moverIzquierda(Vector2D pos) {
	Vector2D aux;
	aux.x = pos.x - 4;
	aux.y = pos.y;
	if (validarMovimiento(aux) == true)
	{
		return aux;
	}
	else return pos;
}

Vector2D Movimiento::moverDerecha(Vector2D pos) {
	Vector2D aux;
	aux.x = pos.x + 4;
	aux.y = pos.y;
	if (validarMovimiento(aux) == true)
	{
		return aux;
	}
	else return pos;
}

Vector2D Movimiento::moverArriba(Vector2D pos) {
	Vector2D aux;
	aux.x = pos.x;
	aux.y = pos.y + 4;
	if (validarMovimiento(aux) == true)
	{
		return aux;
	}
	else return pos;
}

Vector2D Movimiento::moverAbajo(Vector2D pos) {
	Vector2D aux;
	aux.x = pos.x;
	aux.y = pos.y - 4;
	if (validarMovimiento(aux) == true)
	{
		return aux;
	}
	else return pos;
}

 Vector2D Movimiento::moverDiagDrcha(Vector2D pos) {
	Vector2D aux;
	aux=moverDerecha(pos);
	if(aux.y<0)//probando
		moverArriba(aux);
	return aux;
}
Vector2D Movimiento::moverDiagIzq(Vector2D pos) {
	Vector2D aux;
	aux = moverIzquierda(pos);
	if (aux.y < 0)//probando
		moverArriba(aux);
	return aux;
}
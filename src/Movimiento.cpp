#include "Movimiento.h"
#include <cmath>

bool Movimiento::Dentro_del_tablero(Pieza p) {
	if (p.getPos().x < -14 || p.getPos().x > 14 || p.getPos().y < -14 || p.getPos().y >14) {
		return false;
	}
	else
		return true;
}


void Movimiento::salida_peon_blanco(int n) {
	listapiezas.peones_blancos[n].mover_arriba();
	listapiezas.peones_blancos[n].mover_arriba();
}

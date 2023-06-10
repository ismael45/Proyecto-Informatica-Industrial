#include "Movimiento.h"
#include <cmath>

bool Movimiento::Dentro_del_tablero(Pieza p) {
	if (p.getPos().x < -14 || p.getPos().x > 14 || p.getPos().y < -14 || p.getPos().y >14) {
		return false;
	}
	else
		return true;
}



#pragma once
#include "Pieza.h"
#include "Tablero.h"
#include "ListaPiezas.h"

class Movimiento {
public:
	bool Dentro_del_tablero(Pieza p);
	
	void salida_peon_blanco(int n);
	
private:
	ListaPiezas listapiezas;

};
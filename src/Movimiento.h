#pragma once
#include "Pieza.h"
#include "Tablero.h"
#include "ListaPiezas.h"

class Movimiento {
public:
	bool Dentro_del_tablero(Pieza p);
	
	
	
private:
	ListaPiezas listapiezas;

};
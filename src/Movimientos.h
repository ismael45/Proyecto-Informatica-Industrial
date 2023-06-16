#pragma once

#include <iostream>
#include "Tablero.h"
#include "Raton.h"
#include "ListaPiezas.h"
#include <Windows.h> //libreria para usar el ratón

using namespace std;

class Movimientos {
private:
	ListaPiezas listapiezas;
	Raton raton;
	Tablero tablero;
public:


	bool opcion[2];	//Bool de opciones de juego
	void MouseButton(int x, int y, int button, bool down);
	void dibuja();
	

	bool movimiento_peon();
	bool movimiento_torre();
	bool movimiento_alfil();
	bool movimiento_rey();
	bool movimiento_caballo();
};
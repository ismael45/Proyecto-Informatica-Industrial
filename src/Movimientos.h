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
	Vector2D pos_reyNegro,	pos_reyBlanco;
	Vector2D pos_peonN,		pos_peonB;
	Vector2D pos_torreN,	pos_torreB;
	Vector2D pos_caballoN,	pos_caballoB;
	Vector2D pos_alfilN,	pos_alfilB;

	bool t;
public:


	bool opcion[2];	//Bool de opciones de juego
	void MouseButton(int x, int y, int button, bool down);
	void dibuja();
	

	//bool movimiento_peon();
	bool movimiento_peon_blanco();
	bool movimiento_peon_negro();
	bool movimiento_torre();
	bool movimiento_alfil();
	bool movimiento_rey();
	bool movimiento_caballo();

	bool turnos(); //True= turno blancas false= turno negras

	void jaque();
};
#pragma once
#include "Vector2D.h"

struct Raton {
	double o_x, o_y;
	double d_x, d_y;
	Vector2D origen;
	Vector2D destino;
	bool click_dos;
	int casilla_seleccionada = -1;

	int peon_blanco_seleccionado = -1;
	int peon_negro_seleccionado = -1;
	int alfil_blanco_seleccionado = -1;
	int alfil_negro_seleccionado = -1;
	int caballo_blanco_seleccionado = -1;
	int caballo_negro_seleccionado = -1;
	int torre_blanca_seleccionada = -1;
	int torre_negra_seleccionada = -1;
	int rey_blanco_seleccionado = -1;
	int rey_negro_seleccionado = -1;
	int reina_blanca_seleccionada = -1;
	int reina_negra_seleccionada = -1;
};
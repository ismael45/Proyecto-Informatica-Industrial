#pragma once
#include "Vector2D.h"

struct Raton {
	Vector2D origen = { 0,0 };
	Vector2D destino = { 0,0 };
	
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
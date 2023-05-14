#pragma once
#include "Pieza.h"
#define NumMax 32  //Conjunto de piezas totales de todo el tablero

class Vector2D;

class ConjuntoPiezas
{
	Pieza* conjuntoPiezas[NumMax]{ };
	int numero = 0;
public:
	void agregar(Pieza* _pieza);
	void inicializa();
	void dibuja();
	int getnumero() { return numero; }


};


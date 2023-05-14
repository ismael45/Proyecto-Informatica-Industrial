#pragma once
#include "Casilla.h"
#include "Pieza.h"
#include "ConjuntoPiezas.h"
#include "Peon.h"

class Tablero
{
public:
	Tablero();
	virtual ~Tablero();
private:
	Casilla casilla[8][8];
	ColorRGB color;
	ConjuntoPiezas conjuntoPiezas;
public:
	void dibujaTab();
	void dibujaMarco();
	void dibujaPiezas();
	void inicializar();


};


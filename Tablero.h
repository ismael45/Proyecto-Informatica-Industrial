#pragma once
#include "Casilla.h"

class Tablero
{
public:
	Tablero();
	virtual ~Tablero();
private:
	Casilla casilla[8][8];
	ColorRGB color;
public:
	void dibujaTab();
	void dibujaMarco();

};
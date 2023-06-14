#pragma once
#include "Casilla.h"
#include "freeglut.h"


class Tablero
{
public:
	Tablero();
	virtual ~Tablero();
private:
	Casilla casilla[64];
	ColorRGB color;


public:

	//Tablero clasico blanco y negro
	void dibujaTab_clasico();
	void dibujaMarco_clasico();

	//Tablero tem�tico de flores
	void dibujaTab_flores();
	void dibujaMarco_flores();

	void Seleccionar_Casilla(int num) {
		casilla[num].setColor(255, 0, 0);
		casilla[num].dibuja();

	}

	Vector2D getPos_Casilla(int num) {
		return casilla[num].getPos();
	}

	bool estaDentroTablero(float x, float y);
};
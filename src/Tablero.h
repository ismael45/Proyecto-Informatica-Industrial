#pragma once
#include "Casilla.h"
#include "freeglut.h"


class Tablero
{
public:
	Tablero();
	virtual ~Tablero();
private:
	Casilla casilla[8][8];
	ColorRGB color;


public:

	//Tablero clasico blanco y negro
	void dibujaTab_clasico();
	void dibujaMarco_clasico();

	//Tablero tem�tico de flores
	void dibujaTab_flores();
	void dibujaMarco_flores();

	void Seleccionar_Casilla(int x, int y) {
		casilla[x][y].dibuja();
		casilla[x][y].setPos(-14 + 4 * x, -14 + 4 * y);
		casilla[x][y].setColor(255, 0, 0);

	}

	Vector2D getPos_Casilla(int x, int y) {
		return casilla[x][y].getPos();
	}

	bool estaDentroTablero(float x, float y);
};
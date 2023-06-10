#pragma once
#include "Casilla.h"
#include "Peon.h"
#include"Torre.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Reina.h"
#include "Rey.h"
#include "freeglut.h"
#include "ListaPiezas.h"

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

	//Tablero temático de flores
	void dibujaTab_flores();
	void dibujaMarco_flores();

	bool estaDentroTablero(float x, float y);

	void Seleccionar_Casilla(int x, int y) {
		casilla[x][y].dibuja();
		casilla[x][y].setPos(-14 + 4 * x, -14 + 4 * y);
		casilla[x][y].setColor(255, 0, 0);

	}

	Vector2D getPos_Casilla( int x, int y) {
		return casilla[x][y].getPos();
	}
	

};
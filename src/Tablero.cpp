#include "Tablero.h"


Tablero::Tablero() {};
Tablero::~Tablero() {};

void Tablero::dibujaTab_clasico() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			casilla[i][j].dibuja();
			casilla[i][j].setPos(-14 + 4 * i, -14 + 4 * j);
			if ((i + j) % 2 == 0) casilla[i][j].setColor(0, 0, 0);//si es par negro
			else casilla[i][j].setColor(255, 255, 255);//si es impar es blanco



		}
	}

	// Establecer el color de fondo
	glClearColor(0, 0, 0, 1.0);

	

}



void Tablero::dibujaMarco_clasico() {
	glDisable(GL_LIGHTING);
	glColor3ub(120, 70, 42);
	glBegin(GL_POLYGON);
	glVertex3d(18.0, 18.0, -0.0);
	glVertex3d(18.0, -18.0, -0.0);
	glVertex3d(-18.0, -18.0, -0.0);
	glVertex3d(-18.0, 18.0, -0.0);
	glEnd();
	glEnable(GL_LIGHTING);
	
}


void Tablero::dibujaTab_flores()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			casilla[i][j].dibuja();
			casilla[i][j].setPos(-14 + 4 * i, -14 + 4 * j);
			if ((i + j) % 2 == 0) casilla[i][j].setColor(132, 192, 140);//si es par negro
			else casilla[i][j].setColor(228, 135, 188);//si es impar es blanco

		}
	}


	

}

void Tablero::dibujaMarco_flores()
{
	glDisable(GL_LIGHTING);
	glColor3ub(255, 100, 100);
	glBegin(GL_POLYGON);
	glVertex3d(18.0, 18.0, -0.0);
	glVertex3d(18.0, -18.0, -0.0);
	glVertex3d(-18.0, -18.0, -0.0);
	glVertex3d(-18.0, 18.0, -0.0);
	glEnd();
	glEnable(GL_LIGHTING);
}

bool Tablero::estaDentroTablero(float x, float y) {
	if (x > -15.0f && x < 15.0f && y > -15.0f && y < 15.0f) {
		return true;
	}
	return false;
}
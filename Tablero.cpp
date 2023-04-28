#include "Tablero.h"
#include "freeglut.h"

Tablero::Tablero() {};
Tablero::~Tablero() {};

void Tablero::dibujaTab() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			casilla[i][j].dibuja();
			casilla[i][j].setPos(-14 + 4 * i, -14 + 4 * j);
			if ((i + j) % 2 == 0) casilla[i][j].setColor(255, 180, 180);
			else casilla[i][j].setColor(255, 100, 100);
		}
	}
}


void Tablero::dibujaMarco() {
	glDisable(GL_LIGHTING);
	glColor3ub(240, 240, 240);
	glBegin(GL_POLYGON);
	glVertex3d(18.0, 18.0, -0.5);
	glVertex3d(18.0, -18.0, -0.5);
	glVertex3d(-18.0, -18.0, -0.5);
	glVertex3d(-18.0, 18.0, -0.5);
	glEnd();
	glEnable(GL_LIGHTING);
}
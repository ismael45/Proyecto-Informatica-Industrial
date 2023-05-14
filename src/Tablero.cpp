#include "Tablero.h"
#include "freeglut.h"

Tablero::Tablero() {};
Tablero::~Tablero() {};

void Tablero::dibujaTab() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			casilla[i][j].dibuja();
			casilla[i][j].setPos(-14 + 4 * i, -14 + 4 * j);
			if ((i + j) % 2 == 0) casilla[i][j].setColor(0, 0, 0);
			else casilla[i][j].setColor(255, 255, 255);
		}
	}
}


void Tablero::dibujaMarco() {
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

void Tablero::dibujaPiezas()
{
	conjuntoPiezas.dibuja();
}

void Tablero::inicializar()
{
	for (int i = 0; i < 16; i++)
	{
		Peon* auxp = new Peon{};
		conjuntoPiezas.agregar(auxp);
	}

}

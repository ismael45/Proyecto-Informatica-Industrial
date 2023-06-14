#include "Tablero.h"


Tablero::Tablero() {};
Tablero::~Tablero() {};

void Tablero::dibujaTab_clasico() {
	for (int i = 0; i < 64; i++) {
		int fila = i / 8; // Divide el índice por 8 para obtener la fila
		int columna = i % 8; // Obtiene el resto de la división para obtener la columna
		casilla[i].setPos(-14 + 4 * columna, -14 + 4 * fila);
		casilla[i].setColor((i + fila) % 2 == 0 ? 0 : 255, (i + fila) % 2 == 0 ? 0 : 255,
			(i + fila) % 2 == 0 ? 0 : 255);
		casilla[i].dibuja();
	}

	// Establecer el color de fondo
	glClearColor(0, 0, 0, 1.0);
}




void Tablero::dibujaTab_flores()
{
	for (int i = 0; i < 64; i++) {
		int fila = i / 8; // Divide el índice por 8 para obtener la fila
		int columna = i % 8; // Obtiene el resto de la división para obtener la columna
		casilla[i].setPos(-14 + 4 * columna, -14 + 4 * fila); // Corrige el orden de las coordenadas x e y
		if ((fila + columna) % 2 == 0)
			casilla[i].setColor(132, 192, 140); // si la suma de fila y columna es par, pinta el color negro
		else
			casilla[i].setColor(228, 135, 188); // si la suma de fila y columna es impar, pinta el color blanco
		casilla[i].dibuja();
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

bool Tablero::estaDentroTablero(float x, float y) {
	if (x > -15.0f && x < 15.0f && y > -15.0f && y < 15.0f) {
		return true;
	}
	return false;
}
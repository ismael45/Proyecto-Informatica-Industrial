#include "Tablero.h"


Tablero::Tablero() {
	//Atribución del nombre(Código) de celda según índice
	for (int i = 0; i < 64; i++) {
		int fil = i / 8; 
		int col = i % 8; 
		int numToChar = 65 + col;
		char c1 = (char)numToChar;
		char c2 = (char)(49 + fil);
		casilla[i].setCodigo(c1);
		casilla[i].setCodigo(c2);	
	}
};
Tablero::~Tablero() {};

void Tablero::dibujaTab_clasico() {
	for (int i = 0; i < 64; i++) {
		int fila = i / 8; // Divide el índice por 8 para obtener la fila. Rango :0 - 7
		int columna = i % 8; // Obtiene el resto de la división para obtener la columna. Rango :0 - 7
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
		int fila = i / 8; // Divide el índice por 8 para obtener la fila. Rango :0 - 7
		int columna = i % 8; // Obtiene el resto de la división para obtener la columna. Rango :0 - 7
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
	if (x > -16.0f && x < 16.0f && y > -16.0f && y < 16.0f) {
		return true;
	}
	return false;
}

Casilla Tablero::getCasilla_Pos(float x, float y) {
	int num;
	for (int i = 0; i < 8; i++) {//cambio fila
		for (int j = 0; j < 8; j++) {//cambio columna
			if (x >= (4 * j - 16.0f) && x <= (4 * j - 12.0f) && y >= (4 * i - 16.0f) && y <= (4 * i - 12.0f))
				num = 8 * i + j;
		}		
	}
	return casilla[num];
}
Casilla Tablero::getCasilla_Ind(int i) {
	return casilla[i];
}

int Tablero::getIndexCasilla(Casilla& C) {
	for (int i = 0; i < 64; i++) {
		if (casilla[i] == C) {
			return i;
		}
	}
	return -1;
}

#include "Tablero.h"


Tablero::Tablero() {};
Tablero::~Tablero() {};

void Tablero::dibujaTab() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			casilla[i][j].dibuja();
			casilla[i][j].setPos(-14 + 4 * i, -14 + 4 * j);
			if ((i + j) % 2 == 0) casilla[i][j].setColor(0, 0, 0);//si es par negro
			else casilla[i][j].setColor(255, 255, 255);//si es impar es blanco



		}
	}

	// Establecer el color de fondo
	glClearColor(1, 1, 0, 1.0);

}



void Tablero::dibujaPiezas() {

	pieza.dibuja();
	pieza.setPos(-14, -6),
	pieza.setColor(255, 0, 0);



	///////////////////////////BLANCAS//////////////////////////////
		//Dibuja los peones de los blancos
	for (int i = 0; i < 8; i++) {
		peones_blancos[i].dibuja_peon();
		peones_blancos[i].setPos(-14 + 4 * i, -10);
		peones_blancos[i].setColor(255, 0, 0);
	}

	//Dibuja las torres de los blancos
	torres_blancas[0].dibuja_torre();
	torres_blancas[0].setPos(-14, -14);
	torres_blancas[0].setColor(255, 0, 0);

	torres_blancas[1].dibuja_torre();
	torres_blancas[1].setPos(14, -14);
	torres_blancas[1].setColor(255, 0, 0);


	//Dibuja los caballos de los blancos
	caballos_blancos[0].dibuja_caballo();
	caballos_blancos[0].setPos(-10, -14);
	caballos_blancos[0].setColor(255, 0, 0);

	caballos_blancos[1].dibuja_caballo();
	caballos_blancos[1].setPos(10, -14);
	caballos_blancos[1].setColor(255, 0, 0);

	//Dibuja los alfiles de los blancos
	alfiles_blancos[0].dibuja_alfil();
	alfiles_blancos[0].setPos(-6, -14);
	alfiles_blancos[0].setColor(255, 0, 0);

	alfiles_blancos[1].dibuja_alfil();
	alfiles_blancos[1].setPos(6, -14);
	alfiles_blancos[1].setColor(255, 0, 0);

	//Dibuja el rey blanco
	rey_blanco.dibuja_rey();
	rey_blanco.setPos(2, -14),
	rey_blanco.setColor(255, 0, 0);


	//Dibuja la reina blanca
	reina_blanca.dibuja_reina();
	reina_blanca.setPos(-2, -14),
	reina_blanca.setColor(255, 0, 0);

	///////////////////////////NEGRAS//////////////////////////////


		//Dibuja los peones de los negros
	for (int i = 0; i < 8; i++) {
		peones_negros[i].dibuja_peon();
		peones_negros[i].setPos(-14 + 4 * i, 10);
		peones_negros[i].setColor(0, 255, 0);
	}



	//Dibuja las torres de los negros
	torres_negras[0].dibuja_torre();
	torres_negras[0].setPos(-14, 14);
	torres_negras[0].setColor(0, 255, 0);

	torres_negras[1].dibuja_torre();
	torres_negras[1].setPos(14, 14);
	torres_negras[1].setColor(0, 255, 0);


	//Dibuja los caballos de los negros
	caballos_negros[0].dibuja_caballo();
	caballos_negros[0].setPos(-10, 14);
	caballos_negros[0].setColor(0, 255, 0);

	caballos_negros[1].dibuja_caballo();
	caballos_negros[1].setPos(10, 14);
	caballos_negros[1].setColor(0, 255, 0);

	//Dibuja los alfiles de los negros
	alfiles_negros[0].dibuja_alfil();
	alfiles_negros[0].setPos(-6, 14);
	alfiles_negros[0].setColor(0, 255, 0);

	alfiles_negros[1].dibuja_alfil();
	alfiles_negros[1].setPos(6, 14);
	alfiles_negros[1].setColor(0, 255, 0);

	//Dibuja el rey negro
	rey_negro.dibuja_rey();
	rey_negro.setPos(2, 14),
	rey_negro.setColor(0, 255, 0);


	//Dibuja la reina negra
	reina_negra.dibuja_reina();
	reina_negra.setPos(-2, 14),
	reina_negra.setColor(0, 255, 0);
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


bool Tablero::estaDentroTablero(float x, float y) {
	if (x > -15.0f && x < 15.0f && y > -15.0f && y < 15.0f) {
		return true;
	}
	return false;
}
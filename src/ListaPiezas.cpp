#include "ListaPiezas.h"

ListaPiezas::ListaPiezas()
{
}

void ListaPiezas::inicializar()
{
	//********************+***PIEZAS BLANCAS*************************//

	//Dibuja los peones blancos 
	for (int i = 0; i < 8; i++) {
		peones_blancos[i].dibuja_peonBlanco();
		peones_blancos[i].setPos(-14 + 4 * i, -10);
		//peones_blancos[i].setColor(255, 0, 0);
	}

	//Dibuja los alfiles de los blancos
	alfiles_blancos[0].dibuja_alfilBlanco();
	alfiles_blancos[0].setPos(-6, -14);
	

	alfiles_blancos[1].dibuja_alfilBlanco();
	alfiles_blancos[1].setPos(6, -14);
	

	//********************+***PIEZAS NEGRAS*************************//
	
	//Dibuja los peones de los negros
	for (int i = 0; i < 8; i++) {
		peones_negros[i].dibuja_peonNegro();
		peones_negros[i].setPos(-14 + 4 * i, 10);
		peones_negros[i].setColor(0, 255, 0);
	}

	//Dibuja los alfiles de los negros
	alfiles_negros[0].dibuja_alfilNegro();
	alfiles_negros[0].setPos(-6, 14);
	

	alfiles_negros[1].dibuja_alfilNegro();
	alfiles_negros[1].setPos(6, 14);
	


	/*
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
	*/

}



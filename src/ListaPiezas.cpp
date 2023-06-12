#include "ListaPiezas.h"

ListaPiezas::ListaPiezas()
{

}

void ListaPiezas::inicializar_clasico()
{
	ListaPiezas::asignar_piezas();
	//********************+***PIEZAS BLANCAS*************************//

	//Dibuja los peones blancos 
	for (int i = 0; i < 8; i++) {
		peones_blancos[i].dibuja_peonBlanco();
		peones_blancos[i].setPos(-14 + 4 * i, -10);
	}

	//Dibuja los alfiles de los blancos
	alfiles_blancos[0].dibuja_alfilBlanco();
	alfiles_blancos[0].setPos(-6, -14);


	alfiles_blancos[1].dibuja_alfilBlanco();
	alfiles_blancos[1].setPos(6, -14);

	//Dibuja los caballos de los blancos
	caballos_blancos[0].dibuja_caballoBlanco();
	caballos_blancos[0].setPos(-10, -14);

	caballos_blancos[1].dibuja_caballoBlanco();
	caballos_blancos[1].setPos(10, -14);

	//Dibuja las torres de los blancos
	torres_blancas[0].dibuja_torreBlanca();
	torres_blancas[0].setPos(-14, -14);

	torres_blancas[1].dibuja_torreBlanca();
	torres_blancas[1].setPos(14, -14);

	//Dibuja la reina blanca
	reina_blanca.dibuja_reinaBlanca();
	reina_blanca.setPos(-2, -14);

	//Dibuja el rey blanco
	rey_blanco.dibuja_reyBlanco();
	rey_blanco.setPos(2, -14);

	//********************+***PIEZAS NEGRAS*************************//

	//Dibuja los peones de los negros
	for (int i = 0; i < 8; i++) {
		peones_negros[i].dibuja_peonNegro();
		peones_negros[i].setPos(-14 + 4 * i, 10);
	}

	//Dibuja los alfiles de los negros
	alfiles_negros[0].dibuja_alfilNegro();
	alfiles_negros[0].setPos(-6, 14);


	alfiles_negros[1].dibuja_alfilNegro();
	alfiles_negros[1].setPos(6, 14);

	//Dibuja los caballos de los negros
	caballos_negros[0].dibuja_caballoNegro();
	caballos_negros[0].setPos(-10, 14);

	caballos_negros[1].dibuja_caballoNegro();
	caballos_negros[1].setPos(10, 14);

	//Dibuja las torres de los negros
	torres_negras[0].dibuja_torreNegra();
	torres_negras[0].setPos(-14, 14);


	torres_negras[1].dibuja_torreNegra();
	torres_negras[1].setPos(14, 14);


	//Dibuja la reina negra
	reina_negra.dibuja_reinaNegra();
	reina_negra.setPos(-2, 14);

	//Dibuja el rey negro
	rey_negro.dibuja_reyNegro();
	rey_negro.setPos(2, 14);


}

void ListaPiezas::inicializar_flores()
{
	ListaPiezas::asignar_piezas();
	//********************+***PIEZAS BLANCAS*************************//

//Dibuja los peones blancos 
	for (int i = 0; i < 8; i++) {
		peones_blancos[i].dibuja_peonFlor();
		peones_blancos[i].setPos(-14 + 4 * i, -10);
		//peones_blancos[i].setColor(255, 0, 0);
	}

	glColor3f(1.0f, 1.0f, 1.0f); // Establecer el color blanco
	//Dibuja los alfiles de los blancos
	alfiles_blancos[0].dibuja_alfilFlor();
	alfiles_blancos[0].setPos(-6, -14);


	alfiles_blancos[1].dibuja_alfilFlor();
	alfiles_blancos[1].setPos(6, -14);

	//Dibuja los caballos de los blancos
	caballos_blancos[0].dibuja_caballoFlor();
	caballos_blancos[0].setPos(-10, -14);

	caballos_blancos[1].dibuja_caballoFlor();
	caballos_blancos[1].setPos(10, -14);

	//Dibuja las torres de los blancos
	torres_blancas[0].dibuja_torreFlor();
	torres_blancas[0].setPos(-14, -14);

	torres_blancas[1].dibuja_torreFlor();
	torres_blancas[1].setPos(14, -14);

	//Dibuja la reina blanca
	reina_blanca.dibuja_reinaFlor();
	reina_blanca.setPos(-2, -14);

	//Dibuja el rey blanco
	rey_blanco.dibuja_reyFlor();
	rey_blanco.setPos(2, -14);


	//********************+***PIEZAS NEGRAS*************************//

	//Dibuja los peones de los negros
	for (int i = 0; i < 8; i++) {
		peones_negros[i].dibuja_peonBosque();
		peones_negros[i].setPos(-14 + 4 * i, 10);
		peones_negros[i].setColor(0, 255, 0);
	}

	//Dibuja los alfiles de los negros
	alfiles_negros[0].dibuja_alfilBosque();
	alfiles_negros[0].setPos(-6, 14);


	alfiles_negros[1].dibuja_alfilBosque();
	alfiles_negros[1].setPos(6, 14);

	//Dibuja los caballos de los negros
	caballos_negros[0].dibuja_caballoBosque();
	caballos_negros[0].setPos(-10, 14);

	caballos_negros[1].dibuja_caballoBosque();
	caballos_negros[1].setPos(10, 14);

	//Dibuja las torres de los negros
	torres_negras[0].dibuja_torreBosque();
	torres_negras[0].setPos(-14, 14);


	torres_negras[1].dibuja_torreBosque();
	torres_negras[1].setPos(14, 14);


	//Dibuja la reina negra
	reina_negra.dibuja_reinaBosque();
	reina_negra.setPos(-2, 14);

	//Dibuja el rey negro
	rey_negro.dibuja_reyBosque();
	rey_negro.setPos(2, 14);


}


void ListaPiezas::asignar_piezas() {
	for (int i = 0; i < 8; i++) {
		piezas[i] = peones_blancos[i];
	}
	for (int i = 0; i < 8; i++) {
		piezas[i + 8] = peones_negros[i];
	}
	for (int i = 0; i < 2; i++) {
		piezas[i + 16] = torres_blancas[i];
	}
	for (int i = 0; i < 2; i++) {
		piezas[i + 18] = torres_negras[i];
	}
	for (int i = 0; i < 2; i++) {
		piezas[i + 20] = caballos_blancos[i];
	}
	for (int i = 0; i < 2; i++) {
		piezas[i + 22] = caballos_negros[i];
	}
	for (int i = 0; i < 2; i++) {
		piezas[i + 24] = alfiles_blancos[i];
	}
	for (int i = 0; i < 2; i++) {
		piezas[i + 26] = alfiles_negros[i];
	}
	piezas[28] = rey_blanco;
	piezas[29] = rey_negro;
	piezas[30] = reina_blanca;
	piezas[31] = reina_negra;

}

void ListaPiezas::borrar_piezas()
{
	for (int i = 0; i < 8; i++) {
		peones_blancos[i] = Peon();
		peones_negros[i] = Peon();
	}

	for (int i = 0; i < 2; i++) {
		alfiles_blancos[i] = Alfil();
		alfiles_negros[i] = Alfil();
		caballos_blancos[i] = Caballo();
		caballos_negros[i] = Caballo();
		torres_blancas[i] = Torre();
		torres_negras[i] = Torre();
	}

	reina_blanca = Reina();
	reina_negra = Reina();
	rey_blanco = Rey();
	rey_negro = Rey();
}


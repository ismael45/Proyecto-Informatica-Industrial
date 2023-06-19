#include "ListaPiezas.h"

ListaPiezas::ListaPiezas()
{

	//PIEZAS BLANCAS
	for (int i = 0; i < 8; i++) {
		peones_blancos[i].setPos(-14 + 4 * i, -10);
	}
	torres_blancas[0].setPos(-14, -14);
	torres_blancas[1].setPos(14, -14);

	caballos_blancos[0].setPos(-10, -14);
	caballos_blancos[1].setPos(10, -14);

	alfiles_blancos[0].setPos(-6, -14);
	alfiles_blancos[1].setPos(6, -14);

	rey_blanco.setPos(2, -14);
	reina_blanca[0].setPos(-2, -14);


	//PIEZAS NEGRAS
	for (int i = 0; i < 8; i++) {
		peones_negros[i].setPos(-14 + 4 * i, 10);
	}
	torres_negras[0].setPos(-14, 14);
	torres_negras[1].setPos(14, 14);

	caballos_negros[0].setPos(-10, 14);
	caballos_negros[1].setPos(10, 14);

	alfiles_negros[0].setPos(-6, 14);
	alfiles_negros[1].setPos(6, 14);

	rey_negro.setPos(2, 14);
	reina_negra[0].setPos(-2, 14);

}


void ListaPiezas::actualizar_flores()
{
	ListaPiezas::asignar_piezas();
	//********************+***PIEZAS BLANCAS*************************//

	// PEONES
	for (int i = 0; i < 8; i++) {
		peones_blancos[i].setPos(peones_blancos[i].getPos().x, peones_blancos[i].getPos().y);
		peones_blancos[i].setColor(BLANCAS);
		peones_blancos[i].setTipo(FLORES);
		peones_blancos[i].dibuja();
	}

	// TORRES
	for (int i = 0; i < 2; i++) {
		torres_blancas[i].setPos(torres_blancas[i].getPos().x, torres_blancas[i].getPos().y);
		torres_blancas[i].setColor(BLANCAS);
		torres_blancas[i].setTipo(FLORES);
		torres_blancas[i].dibuja();
	}

	// CABALLOS
	for (int i = 0; i < 2; i++) {
		caballos_blancos[i].setPos(caballos_blancos[i].getPos().x, caballos_blancos[i].getPos().y);
		caballos_blancos[i].setColor(BLANCAS);
		caballos_blancos[i].setTipo(FLORES);
		caballos_blancos[i].dibuja();
	}

	// ALFILES
	for (int i = 0; i < 2; i++) {
		alfiles_blancos[i].setPos(alfiles_blancos[i].getPos().x, alfiles_blancos[i].getPos().y);
		alfiles_blancos[i].setColor(BLANCAS);
		alfiles_blancos[i].setTipo(FLORES);
		alfiles_blancos[i].dibuja();
	}

	// REY
	rey_blanco.setPos(rey_blanco.getPos().x, rey_blanco.getPos().y);
	rey_blanco.setColor(BLANCAS);
	rey_blanco.setTipo(FLORES);
	rey_blanco.dibuja();

	// REINA
	reina_blanca[0].setPos(reina_blanca[0].getPos().x, reina_blanca[0].getPos().y);
	reina_blanca[0].setColor(BLANCAS);
	reina_blanca[0].setTipo(FLORES);
	reina_blanca[0].dibuja();



	//********************+***PIEZAS NEGRAS*************************//
	// PEONES
	for (int i = 0; i < 8; i++) {
		peones_negros[i].setPos(peones_negros[i].getPos().x, peones_negros[i].getPos().y);
		peones_negros[i].setColor(NEGRAS);
		peones_negros[i].setTipo(FLORES);
		peones_negros[i].dibuja();
	}

	// TORRES
	for (int i = 0; i < 2; i++) {
		torres_negras[i].setPos(torres_negras[i].getPos().x, torres_negras[i].getPos().y);
		torres_negras[i].setColor(NEGRAS);
		torres_negras[i].setTipo(FLORES);
		torres_negras[i].dibuja();
	}

	// CABALLOS
	for (int i = 0; i < 2; i++) {
		caballos_negros[i].setPos(caballos_negros[i].getPos().x, caballos_negros[i].getPos().y);
		caballos_negros[i].setColor(NEGRAS);
		caballos_negros[i].setTipo(FLORES);
		caballos_negros[i].dibuja();
	}

	// ALFILES
	for (int i = 0; i < 2; i++) {
		alfiles_negros[i].setPos(alfiles_negros[i].getPos().x, alfiles_negros[i].getPos().y);
		alfiles_negros[i].setColor(NEGRAS);
		alfiles_negros[i].setTipo(FLORES);
		alfiles_negros[i].dibuja();
	}

	// REY
	rey_negro.setPos(rey_negro.getPos().x, rey_negro.getPos().y);
	rey_negro.setColor(NEGRAS);
	rey_negro.setTipo(FLORES);
	rey_negro.dibuja();

	// REINA
	reina_negra[0].setPos(reina_negra[0].getPos().x, reina_negra[0].getPos().y);
	reina_negra[0].setColor(NEGRAS);
	reina_negra[0].setTipo(FLORES);
	reina_negra[0].dibuja();


}


void ListaPiezas::actualizar_clasico()
{

	ListaPiezas::asignar_piezas();
	//********************+***PIEZAS BLANCAS*************************//

	// PEONES
	for (int i = 0; i < 8; i++) {
		peones_blancos[i].setPos(peones_blancos[i].getPos().x, peones_blancos[i].getPos().y);
		peones_blancos[i].setColor(BLANCAS);
		peones_blancos[i].setTipo(CLASICAS);
		peones_blancos[i].dibuja();
	}

	// TORRES
	for (int i = 0; i < 2; i++) {
		torres_blancas[i].setPos(torres_blancas[i].getPos().x, torres_blancas[i].getPos().y);
		torres_blancas[i].setColor(BLANCAS);
		torres_blancas[i].setTipo(CLASICAS);
		torres_blancas[i].dibuja();
	}

	// CABALLOS
	for (int i = 0; i < 2; i++) {
		caballos_blancos[i].setPos(caballos_blancos[i].getPos().x, caballos_blancos[i].getPos().y);
		caballos_blancos[i].setColor(BLANCAS);
		caballos_blancos[i].setTipo(CLASICAS);
		caballos_blancos[i].dibuja();
	}

	// ALFILES
	for (int i = 0; i < 2; i++) {
		alfiles_blancos[i].setPos(alfiles_blancos[i].getPos().x, alfiles_blancos[i].getPos().y);
		alfiles_blancos[i].setColor(BLANCAS);
		alfiles_blancos[i].setTipo(CLASICAS);
		alfiles_blancos[i].dibuja();
	}

	// REY
	rey_blanco.setPos(rey_blanco.getPos().x, rey_blanco.getPos().y);
	rey_blanco.setColor(BLANCAS);
	rey_blanco.setTipo(CLASICAS);
	rey_blanco.dibuja();

	// REINA
	reina_blanca[0].setPos(reina_blanca[0].getPos().x, reina_blanca[0].getPos().y);
	reina_blanca[0].setColor(BLANCAS);
	reina_blanca[0].setTipo(CLASICAS);
	reina_blanca[0].dibuja();



	//********************+***PIEZAS NEGRAS*************************//
	// PEONES
	for (int i = 0; i < 8; i++) {
		peones_negros[i].setPos(peones_negros[i].getPos().x, peones_negros[i].getPos().y);
		peones_negros[i].setColor(NEGRAS);
		peones_negros[i].setTipo(CLASICAS);
		peones_negros[i].dibuja();
	}

	// TORRES
	for (int i = 0; i < 2; i++) {
		torres_negras[i].setPos(torres_negras[i].getPos().x, torres_negras[i].getPos().y);
		torres_negras[i].setColor(NEGRAS);
		torres_negras[i].setTipo(CLASICAS);
		torres_negras[i].dibuja();
	}

	// CABALLOS
	for (int i = 0; i < 2; i++) {
		caballos_negros[i].setPos(caballos_negros[i].getPos().x, caballos_negros[i].getPos().y);
		caballos_negros[i].setColor(NEGRAS);
		caballos_negros[i].setTipo(CLASICAS);
		caballos_negros[i].dibuja();
	}

	// ALFILES
	for (int i = 0; i < 2; i++) {
		alfiles_negros[i].setPos(alfiles_negros[i].getPos().x, alfiles_negros[i].getPos().y);
		alfiles_negros[i].setColor(NEGRAS);
		alfiles_negros[i].setTipo(CLASICAS);
		alfiles_negros[i].dibuja();
	}

	// REY
	rey_negro.setPos(rey_negro.getPos().x, rey_negro.getPos().y);
	rey_negro.setColor(NEGRAS);
	rey_negro.setTipo(CLASICAS);
	rey_negro.dibuja();

	// REINA
	reina_negra[0].setPos(reina_negra[0].getPos().x, reina_negra[0].getPos().y);
	reina_negra[0].setColor(NEGRAS);
	reina_negra[0].setTipo(CLASICAS);
	reina_negra[0].dibuja();
}




void ListaPiezas::asignar_piezas() {
	// Piezas blancas
	for (int i = 0; i < 8; i++) {
		 piezas[i] =  peones_blancos[i];
	}

	piezas[8] = torres_blancas[0];
	piezas[9] = torres_blancas[1];

	piezas[10] = caballos_blancos[0];
	piezas[11] = caballos_blancos[1];

	piezas[12] = alfiles_blancos[0];
	piezas[13] = alfiles_blancos[1];

	piezas[14] = rey_blanco;

	piezas[15] = reina_blanca[0];

	for (int i = 1; i < 9; i++) {
		piezas[31+i] = reina_blanca[i];
	}

	// Piezas negras
	for (int i = 0; i < 8; i++) {
		piezas[16 + i] = peones_negros[i];
	}

	piezas[24] = torres_negras[0];
	piezas[25] = torres_negras[1];

	piezas[26] = caballos_negros[0];
	piezas[27] = caballos_negros[1];

	piezas[28] = alfiles_negros[0];
	piezas[29] = alfiles_negros[1];

	piezas[30] = rey_negro;

	piezas[31] = reina_negra[0];
	for (int i = 1; i < 9; i++) {
		piezas[39+i] = reina_negra[i];
	}
}


void ListaPiezas::borrar_piezas()
{
	for (int i = 0; i < 8; i++) {
		peones_blancos[i] = Peon();
	}
	for (int i = 0; i < 8; i++) {
		peones_negros[i] = Peon();
	}


}


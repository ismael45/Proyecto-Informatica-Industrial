#include "ListaPiezas.h"

ListaPiezas::ListaPiezas()
{

}


void ListaPiezas::inicializar_flores()
{
	//********************+***PIEZAS BLANCAS*************************//

	//PEONES
	for (int i = 0; i < 8; i++) {
		peones_blancos[i].setPos(-14 + 4 * i, -10);
		peones_blancos[i].setColor(BLANCAS);
		peones_blancos[i].setTipo(FLORES);
		peones_blancos[i].dibuja();
	}

	//TORRES
	torres_blancas[0].setPos(-14, -14);
	torres_blancas[0].setColor(BLANCAS);
	torres_blancas[0].setTipo(FLORES);
	torres_blancas[0].dibuja();

	torres_blancas[1].setPos(14, -14);
	torres_blancas[1].setColor(BLANCAS);
	torres_blancas[1].setTipo(FLORES);
	torres_blancas[1].dibuja();

	//CABALLOS
	caballos_blancos[0].setPos(-10, -14);
	caballos_blancos[0].setColor(BLANCAS);
	caballos_blancos[0].setTipo(FLORES);
	caballos_blancos[0].dibuja();

	caballos_blancos[1].setPos(10, -14);
	caballos_blancos[1].setColor(BLANCAS);
	caballos_blancos[1].setTipo(FLORES);
	caballos_blancos[1].dibuja();

	//ALFILES
	alfiles_blancos[0].setPos(-6, -14);
	alfiles_blancos[0].setColor(BLANCAS);
	alfiles_blancos[0].setTipo(FLORES);
	alfiles_blancos[0].dibuja();

	alfiles_blancos[1].setPos(6, -14);
	alfiles_blancos[1].setColor(BLANCAS);
	alfiles_blancos[1].setTipo(FLORES);
	alfiles_blancos[1].dibuja();

	//REY
	rey_blanco.setPos(2, -14);
	rey_blanco.setColor(BLANCAS);
	rey_blanco.setTipo(FLORES);
	rey_blanco.dibuja();

	//REINA
	reina_blanca.setPos(-2, -14);
	reina_blanca.setColor(BLANCAS);
	reina_blanca.setTipo(FLORES);
	reina_blanca.dibuja();


	//********************+***PIEZAS NEGRAS*************************//
		//PEONES
	for (int i = 0; i < 8; i++) {
		peones_negros[i].setPos(-14 + 4 * i, 10);
		peones_negros[i].setColor(NEGRAS);
		peones_negros[i].setTipo(FLORES);
		peones_negros[i].dibuja();
	}

	//TORRES
	torres_negras[0].setPos(-14, 14);
	torres_negras[0].setColor(NEGRAS);
	torres_negras[0].setTipo(FLORES);
	torres_negras[0].dibuja();

	torres_negras[1].setPos(14, 14);
	torres_negras[1].setColor(NEGRAS);
	torres_negras[1].setTipo(FLORES);
	torres_negras[1].dibuja();

	//CABALLOS
	caballos_negros[0].setPos(-10, 14);
	caballos_negros[0].setColor(NEGRAS);
	caballos_negros[0].setTipo(FLORES);
	caballos_negros[0].dibuja();

	caballos_negros[1].setPos(10, 14);
	caballos_negros[1].setColor(NEGRAS);
	caballos_negros[1].setTipo(FLORES);
	caballos_negros[1].dibuja();

	//ALFILES
	alfiles_negros[0].setPos(-6, 14);
	alfiles_negros[0].setColor(NEGRAS);
	alfiles_negros[0].setTipo(FLORES);
	alfiles_negros[0].dibuja();

	alfiles_negros[1].setPos(6, 14);
	alfiles_negros[1].setColor(NEGRAS);
	alfiles_negros[1].setTipo(FLORES);
	alfiles_negros[1].dibuja();

	//REY
	rey_negro.setPos(2, 14);
	rey_negro.setColor(NEGRAS);
	rey_negro.setTipo(FLORES);
	rey_negro.dibuja();

	//REINA
	reina_negra.setPos(-2, 14);
	reina_negra.setColor(NEGRAS);
	reina_negra.setTipo(FLORES);
	reina_negra.dibuja();

}


void ListaPiezas::inicializar_clasico()
{
	//********************+***PIEZAS BLANCAS*************************//

	//PEONES
	for (int i = 0; i < 8; i++) {
		peones_blancos[i].setPos(-14 + 4 * i, -10);
		peones_blancos[i].setColor(BLANCAS);
		peones_blancos[i].setTipo(CLASICAS);
		peones_blancos[i].dibuja();
	}

	//TORRES
	torres_blancas[0].setPos(-14, -14);
	torres_blancas[0].setColor(BLANCAS);
	torres_blancas[0].setTipo(CLASICAS);
	torres_blancas[0].dibuja();

	torres_blancas[1].setPos(14, -14);
	torres_blancas[1].setColor(BLANCAS);
	torres_blancas[1].setTipo(CLASICAS);
	torres_blancas[1].dibuja();

	//CABALLOS
	caballos_blancos[0].setPos(-10, -14);
	caballos_blancos[0].setColor(BLANCAS);
	caballos_blancos[0].setTipo(CLASICAS);
	caballos_blancos[0].dibuja();

	caballos_blancos[1].setPos(10, -14);
	caballos_blancos[1].setColor(BLANCAS);
	caballos_blancos[1].setTipo(CLASICAS);
	caballos_blancos[1].dibuja();

	//ALFILES
	alfiles_blancos[0].setPos(-6, -14);
	alfiles_blancos[0].setColor(BLANCAS);
	alfiles_blancos[0].setTipo(CLASICAS);
	alfiles_blancos[0].dibuja();

	alfiles_blancos[1].setPos(6, -14);
	alfiles_blancos[1].setColor(BLANCAS);
	alfiles_blancos[1].setTipo(CLASICAS);
	alfiles_blancos[1].dibuja();

	//REY
	rey_blanco.setPos(2, -14);
	rey_blanco.setColor(BLANCAS);
	rey_blanco.setTipo(CLASICAS);
	rey_blanco.dibuja();

	//REINA
	reina_blanca.setPos(-2, -14);
	reina_blanca.setColor(BLANCAS);
	reina_blanca.setTipo(CLASICAS);
	reina_blanca.dibuja();


	//********************+***PIEZAS NEGRAS*************************//
		//PEONES
	for (int i = 0; i < 8; i++) {
		peones_negros[i].setPos(-14 + 4 * i, 10);
		peones_negros[i].setColor(NEGRAS);
		peones_negros[i].setTipo(CLASICAS);
		peones_negros[i].dibuja();
	}

	//TORRES
	torres_negras[0].setPos(-14, 14);
	torres_negras[0].setColor(NEGRAS);
	torres_negras[0].setTipo(CLASICAS);
	torres_negras[0].dibuja();

	torres_negras[1].setPos(14, 14);
	torres_negras[1].setColor(NEGRAS);
	torres_negras[1].setTipo(CLASICAS);
	torres_negras[1].dibuja();

	//CABALLOS
	caballos_negros[0].setPos(-10, 14);
	caballos_negros[0].setColor(NEGRAS);
	caballos_negros[0].setTipo(CLASICAS);
	caballos_negros[0].dibuja();

	caballos_negros[1].setPos(10, 14);
	caballos_negros[1].setColor(NEGRAS);
	caballos_negros[1].setTipo(CLASICAS);
	caballos_negros[1].dibuja();

	//ALFILES
	alfiles_negros[0].setPos(-6, 14);
	alfiles_negros[0].setColor(NEGRAS);
	alfiles_negros[0].setTipo(CLASICAS);
	alfiles_negros[0].dibuja();

	alfiles_negros[1].setPos(6, 14);
	alfiles_negros[1].setColor(NEGRAS);
	alfiles_negros[1].setTipo(CLASICAS);
	alfiles_negros[1].dibuja();

	//REY
	rey_negro.setPos(2, 14);
	rey_negro.setColor(NEGRAS);
	rey_negro.setTipo(CLASICAS);
	rey_negro.dibuja();

	//REINA
	reina_negra.setPos(-2, 14);
	reina_negra.setColor(NEGRAS);
	reina_negra.setTipo(CLASICAS);
	reina_negra.dibuja();
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


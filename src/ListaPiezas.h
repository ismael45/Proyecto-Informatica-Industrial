#pragma once
#include "Peon.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Torre.h"
#include "Reina.h"
#include "Rey.h"


class ListaPiezas
{
public:
	////////////////////

	Peon peones_blancos[8];			//piezas 0 - 7
	Peon peones_negros[8];			//piezas 16 - 23

	Torre torres_blancas[2];		//piezas 8 - 9
	Torre torres_negras[2];			//piezas 24 - 25

	Caballo caballos_blancos[2];	//piezas 10 - 11
	Caballo caballos_negros[2];		//piezas 26 - 27

	Alfil alfiles_blancos[2];		//piezas 12 - 13
	Alfil alfiles_negros[2];		//piezas 28 - 29

	Rey rey_blanco;					//pieza 14
	Rey rey_negro;					//piezas 30

	//Reina reina_blanca;	//piezas 15 
	//Reina reina_negra;	//piezas 31
	//debe poder haber hasta 9 reinas al mismo tiempo

	Reina reina_blanca[9];			//piezas: 15 será la principal y 32 a 39 las damas por promoción
	Reina reina_negra[9];			//piezas: 31 será la principal y 40 a 47 las damas por promoción

public:
	Pieza piezas[48];

	ListaPiezas();

	void actualizar_clasico();
	void actualizar_flores();


	void borrar_piezas();


	void asignar_piezas();
};

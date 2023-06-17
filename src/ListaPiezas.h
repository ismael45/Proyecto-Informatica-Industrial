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


	Peon peones_blancos[8]; //piezas 0 a 7
	Peon peones_negros[8]; //piezas 8 a 15

	Torre torres_blancas[2]; //piezas 16 a 17
	Torre torres_negras[2];  //piezas 18 a 19

	Caballo caballos_blancos[2]; //piezas 20 a 21
	Caballo caballos_negros[2];  //piezas 22 a 23

	Alfil alfiles_blancos[2]; //piezas 24 a 25
	Alfil alfiles_negros[2];  //piezas 26 a 27

	Rey rey_blanco;  //piezas 28
	Rey rey_negro;   //piezas 29

	Reina reina_blanca;  //piezas 30 
	Reina reina_negra;  //piezas 31

public:
	Pieza piezas[32];

	ListaPiezas();

	void actualizar_clasico();
	void actualizar_flores();


	void borrar_piezas();


	void asignar_piezas();
};

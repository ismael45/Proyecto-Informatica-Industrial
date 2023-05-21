#pragma once
#include "Casilla.h"
#include "Peon.h"
#include"Torre.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Reina.h"
#include "Rey.h"
#include "freeglut.h"
#include "Pieza.h"
#include "Vector2D.h"




class ListaPiezas
{
	Casilla casilla[8][8];
	ColorRGB color;
	Pieza pieza;

	Peon peones_blancos[8];
	Peon peones_negros[8];

	Torre torres_blancas[2];
	Torre torres_negras[2];

	Caballo caballos_blancos[2];
	Caballo caballos_negros[2];

	Alfil alfiles_blancos[2];
	Alfil alfiles_negros[2];

	Rey rey_blanco;
	Rey rey_negro;

	Reina reina_blanca;
	Reina reina_negra;
	

public:

	ListaPiezas();
	void inicializar();
	//void dibujar1();
	

};


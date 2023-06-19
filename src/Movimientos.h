#pragma once

#include <iostream>
#include "Tablero.h"
#include "Raton.h"
#include "ListaPiezas.h"
#include <Windows.h> //libreria para usar el rat�n

using namespace std;

class Movimientos {
private:
	ListaPiezas listapiezas;
	Raton raton;
	Tablero tablero;
	Vector2D pos_reyNegro, pos_reyBlanco;
	Vector2D pos_peonN, pos_peonB;
	Vector2D pos_torreN, pos_torreB;
	Vector2D pos_caballoN, pos_caballoB;
	Vector2D pos_alfilN, pos_alfilB;

	bool t;

	bool casillas_amenazadas_por_blancas[63] = { false };// vectores de booleanos para indicar qu� casillas se encuentran bajo amenaza inminente
	bool casillas_amenazadas_por_negras[63] = { false };
	bool casilla_ocupada = false;
public:

	void set_casillaOcupada();
	void reset_casillaOcupada();
	bool check_casillaOcupada();

	bool opcion[2];	//Bool de opciones de juego
	
	void MouseButton(int x, int y, int button, bool down);
	void dibuja();
	

	//bool movimiento_peon();
	bool movimiento_peon_blanco();
	bool movimiento_peon_negro();
	bool movimiento_torre();
	bool movimiento_alfil();
	bool movimiento_rey();
	bool movimiento_caballo();

	bool turnos(); //True= turno blancas false= turno negras

	void jaque();

	void piezaAmenaza(int i); //activa los bool de los arrays, a partir del indice de una pieza

	bool celdaAmenazada(int i); //se le pasa el numero de celda, y devuelve estado de "peligro inminente" o "calma"

	bool aux_ExisteCeldaConEnemigo(int i, int indice, float xx, float yy);
	void aux_DiscriminaAmenaza(int i, int indice);

	
};
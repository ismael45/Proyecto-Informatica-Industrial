#pragma once

#include <iostream>
#include "Tablero.h"
#include "Raton.h"
#include "ListaPiezas.h"
#include <Windows.h> //libreria para usar el ratón

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

	bool casillas_amenazadas_por_blancas[63] = { false };// vectores de booleanos para indicar qué casillas se encuentran bajo amenaza inminente
	bool casillas_amenazadas_por_negras[63] = { false };
	//bool casilla_ocupada = false;
public:

	/*void set_casillaOcupada();
	void reset_casillaOcupada();
	bool check_casillaOcupada();*/

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

	void piezaAmenazaACasillas(int i); //activa de los array, el bool de todas las casillas amenazadas, a partir del indice de una pieza

	bool checkCasillaAmenazada(int i); //se le pasa el numero de celda, y devuelve estado de "peligro inminente"=1 o "calma"=0

	bool aux_ExisteCeldaSinAliado(int i, int indice, float xx, float yy);
	void aux_DiscriminaQuienAmenaza(int i, int indice);

	void ResetDobles();
	void BanderasMovimiento();
	void enroqueCorto(int i);
	void enroqueLargo(int i);

	void aux_alCementerio(int indice_victima);
	void captura(Pieza atacante, Pieza victima);
	void captura(int indice, float destino_x, float destino_y);

};
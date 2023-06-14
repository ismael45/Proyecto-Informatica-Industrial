#include "Tablero.h"
#include "Raton.h"
#include "ListaPiezas.h"
#include "Menu.h"


#include <math.h>
#include <iostream>
#include <Windows.h> //libreria para usar el rat�n
#include "freeglut.h"


class Mundo
{
public:
	Mundo();
	virtual~Mundo();
private:
	ListaPiezas listapiezas;
	Raton raton;
	Tablero tablero;
	Menu menu;


public:
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	void MouseButton(int x, int y, int button, bool down);
	int Posicion_por_casilla(int x, int y);


	float x_ojo;
	float y_ojo;
	float z_ojo;


	//Bool de sucesos tras hacer clic
	bool opcion[2];

	bool casilla_seleccionada[64];

	int peon_blanco_seleccionado = -1;
	int peon_negro_seleccionado = -1;
	int alfil_blanco_seleccionado = -1;
	int alfil_negro_seleccionado = -1;
	int caballo_blanco_seleccionado = -1;
	int caballo_negro_seleccionado = -1;
	int torre_blanca_seleccionada = -1;
	int torre_negra_seleccionada = -1;
	int rey_blanco_seleccionado = -1;
	int rey_negro_seleccionado = -1;
	int reina_blanca_seleccionada = -1;
	int reina_negra_seleccionada = -1;



};
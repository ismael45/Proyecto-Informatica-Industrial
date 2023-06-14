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
	int final;


public:
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	void MouseButton(int x, int y, int button, bool down);


	float x_ojo;
	float y_ojo;
	float z_ojo;


	//Bool de sucesos tras hacer clic
	bool opcion[2];





};
#include "Tablero.h"
#include "Movimiento.h"
#include "ListaPiezas.h"
#include "Menu.h"


#include <math.h>
#include <iostream>
#include <Windows.h> //libreria para usar el ratón


enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };

class Mundo
{
public:
	Mundo();
	virtual~Mundo();
private:
	ListaPiezas listapiezas;
	Movimiento movimiento;
	Tablero tablero;
	Menu menu;
	

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

	bool suceso[200];


};

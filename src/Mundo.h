#include "Tablero.h"
#include "Casilla.h"
#include "Movimiento.h"
#include "ListaPiezas.h"
#include "Menu.h"


class Mundo
{
public:
	Mundo();
	virtual~Mundo();
private:
	ListaPiezas listapiezas;
	Tablero tablero;
	Menu menu;
	int x;
	int y;

	
	//Movimiento movimiento;

public:
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;

};

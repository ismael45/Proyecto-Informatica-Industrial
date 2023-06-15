#include "Menu.h"
#include "Movimientos.h"



class Mundo
{
public:
	Mundo();
	virtual~Mundo();
private:
	Menu menu;

	Movimientos movimientos;
	int final;



public:
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	void Mover(int x, int y , int button, bool down);


	float x_ojo;
	float y_ojo;
	float z_ojo;


};
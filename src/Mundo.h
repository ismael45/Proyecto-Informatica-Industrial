#include "Menu.h"
#include "Movimientos.h"



class Mundo
{
public:
	Mundo();
	virtual~Mundo();
private:
	Menu menu;
<<<<<<< HEAD
	Movimientos movimientos;
	int final;
=======
	int final;

>>>>>>> 1f1f14d2786f946ed6f43684cdd800b2b9350102

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
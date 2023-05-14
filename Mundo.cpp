#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

Mundo::Mundo() {};
Mundo::~Mundo() {};

void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, 0.0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	tablero.dibujaTab();
	tablero.dibujaMarco();
}

void Mundo::mueve()
{

}

void Mundo::inicializa()
{
	x_ojo=0.0;
	y_ojo=0.0;
	z_ojo=60.0;

}

void Mundo::tecla(unsigned char key)
{

}

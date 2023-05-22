#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

Mundo::Mundo() {};
Mundo::~Mundo() {};

void Mundo::rotarOjo()
{
	float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}
void Mundo::dibuja()
{


	gluLookAt(0.0, 0.0, 40,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo

	menu.dibuja_Fondo();
	menu.dibuja_opcion_1();
	menu.dibuja_opcion_2();
	menu.dibuja_texto();
	if (menu.detectarClic(x, y) == 1) {
		listapiezas.inicializar_flores();
		tablero.dibujaTab_flores();
		tablero.dibujaMarco_flores();
	

	}
	else if (menu.detectarClic(x, y) == 2) {
		listapiezas.inicializar_clasico();
		tablero.dibujaTab_clasico();
	    tablero.dibujaMarco_clasico();
	}
	
	
	
	


	glFlush();
	//glutSwapBuffers();
}

void Mundo::mueve()
{

}

void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 30;
	z_ojo = 0;

	//movimiento.setTablero(&tablero);

}

void Mundo::tecla(unsigned char key)
{
	/*switch (key)
	{
	case GLUT_KEY_LEFT:
		movimiento.moverIzquierda();
		break;
	case GLUT_KEY_RIGHT:
		movimiento.moverDerecha();
		break;
	case GLUT_KEY_UP:
		movimiento.moverArriba();
		break;
	case GLUT_KEY_DOWN:
		movimiento.moverAbajo();
		break;
	default:
		break;
	}*/
}



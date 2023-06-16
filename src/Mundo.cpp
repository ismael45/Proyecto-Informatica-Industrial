#include "Mundo.h"



using namespace std;

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


	//DIBUJAR MEN� PRINCIPAL
	menu.dibuja_Fondo();
	menu.dibuja_opcion_1();
	menu.dibuja_opcion_2();
	menu.dibuja_texto();

	movimientos.dibuja();

	

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

	movimientos.turnos() == true;

	cout << "PRUEBA" << endl;
	
}

void Mundo::tecla(unsigned char key)
{


}



void Mundo::Mover(int x, int y, int button, bool down) {
	movimientos.MouseButton(x, y, button, down);
	

}
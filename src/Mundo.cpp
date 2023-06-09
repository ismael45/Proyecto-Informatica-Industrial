#include "Mundo.h"
#include "freeglut.h"


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

	menu.dibuja_Fondo();
	menu.dibuja_opcion_1();
	menu.dibuja_opcion_2();
	menu.dibuja_texto();

	if (suceso[0]) {
		listapiezas.inicializar_flores();
		tablero.dibujaTab_flores();
		tablero.dibujaMarco_flores();
		if (suceso[58])
			tablero.Seleccionar_Casilla(0, 7);

	}
	if (suceso[1]) {
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
}

void Mundo::tecla(unsigned char key)
{

}

void Mundo::MouseButton(int x, int y, int button, bool down) {
	GLint viewport[4];//vista
	GLdouble modelview[16];//cordenadas del modelo
	GLdouble projection[16];//proyeccion de la vista en las coordenadas del modelo
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	GLfloat winX, winY, winZ; //coordenadas de pantalla
	GLdouble posX, posY, posZ; //cooordenadas de modelo (ajedrez)

	//hallar cordenadas X e Y de la pantalla
	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	//hallar coordenada Z de la pantalla
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	//conversión de coordenadas del ratón en pantalla a coordenadas en nuestro mundo
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	//mostrar en consola la posición en la que se hizo click
	std::cout << posX << "," << posY << "\n";

	if (posX >= -25.7677 && posX <= -16.1491 && posY <= 21.5664 && posY >= 14.5947) {
		cout << "Opcion 1" << endl;
		suceso[0] = true;
		suceso[1] = false;
	}//seleccionar opcion 1 
	if (posX >= 16.8984 && posX <=24.1805  && posY <= 21.5664 && posY >= 14.5947) {
		cout << "Opcion 2" << endl;
		suceso[0] = false;
		suceso[1] = true;
	}//seleccionar opcion 2
	
	if (posX >= -15.4322 && posX <= -12.062 && posY <= 15.8757 && posY >= 11.8846) {
		suceso[58] = true;
		cout << "Suceso 2" << endl;
	}
	else
		suceso[58] = false;


	//Empieza el codigo de las acciones a realizar con el ratón
	//ACCIONES: Seleccionar pieza a mover, seleccionar dónde colocar pieza
	//ACCIONES: Seleccionar modo de juego en el menú
	//...
}

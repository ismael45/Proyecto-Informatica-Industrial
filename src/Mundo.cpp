#include "Mundo.h"
#include "freeglut.h"

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
	//listapiezas.inicializar_clasico();
	listapiezas.inicializar_flores();
	tablero.dibujaTab_flores();
	tablero.dibujaMarco_flores();
	//tablero.dibujaTab_clasico();
	//tablero.dibujaMarco_clasico();

	texto.dibujar();

	


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
	////imprimir en pantalla dónde se encuentra el ratón
	//POINT MousePoint;
	//
	//if (GetCursorPos(&MousePoint)) {
	//	std::cout << MousePoint.x << "," << MousePoint.y << "\n";
	//}
	//GLUT_WINDOW_CURSOR;
	
	
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

	//Empieza el codigo de las acciones a realizar con el ratón
	//ACCIONES: Seleccionar pieza a mover, seleccionar dónde colocar pieza
	//ACCIONES: Seleccionar modo de juego en el menú
	//...
}
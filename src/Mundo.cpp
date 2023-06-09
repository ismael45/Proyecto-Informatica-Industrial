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

	if (opcion[0]) {
		listapiezas.inicializar_flores();
		tablero.dibujaTab_flores();
		tablero.dibujaMarco_flores();


		//COLOREAR LA CASILLA SELECICONADA DE ROJO
		for (int i = 0; i < 64; i++) {
			if (casilla[i]) {
				int fila = i / 8; // Divide el �ndice por 8 para obtener la fila
				int columna = i % 8; // Obtiene el resto de la divisi�n para obtener la columna
				tablero.Seleccionar_Casilla(columna, fila);
			}
		}


	}
	if (opcion[1]) {
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
	//conversi�n de coordenadas del rat�n en pantalla a coordenadas en nuestro mundo
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	//mostrar en consola la posici�n en la que se hizo click
	std::cout << posX << "," << posY << "\n";

	if (posX >= -25.7677 && posX <= -16.1491 && posY <= 21.5664 && posY >= 14.5947) {
		cout << "Opcion 1" << endl;
		opcion[0] = true;
		opcion[1] = false;
	}//seleccionar opcion 1 
	if (posX >= 16.8984 && posX <=24.1805  && posY <= 21.5664 && posY >= 14.5947) {
		cout << "Opcion 2" << endl;
		opcion[0] = false;
		opcion[1] = true;
	}//seleccionar opcion 2
	

	//SELECCION DE CASILLAS 
	float min_x = -15.9644, max_x = -12.1507;
	float min_y = -15.787, max_y = -11.9733;

	for (int i = 0; i < 64; i++) {
		if (posX >= min_x && posX <= max_x && posY <= max_y && posY >= min_y)casilla[i] = true;
		else casilla[i] = false;
		min_x += 4;
		max_x += 4;
		if (i == 7) {
			min_x = -15.9644;
			max_x = -12.1507;
			min_y += 4;
			max_y += 4;
		}
		if (i == 15) {
			min_x = -15.9644;
			max_x = -12.1507;
			min_y += 4;
			max_y += 4;
		}
		if (i == 23) {
			min_x = -15.9644;
			max_x = -12.1507;
			min_y += 4;
			max_y += 4;
		}
		if (i == 31) {
			min_x = -15.9644;
			max_x = -12.1507;
			min_y += 4;
			max_y += 4;
		}
		if (i == 39) {
			min_x = -15.9644;
			max_x = -12.1507;
			min_y += 4;
			max_y += 4;
		}
		if (i == 47) {
			min_x = -15.9644;
			max_x = -12.1507;
			min_y += 4;
			max_y += 4;
		}
		if (i == 55) {
			min_x = -15.9644;
			max_x = -12.1507;
			min_y += 4;
			max_y += 4;
		}


	}





	//Empieza el codigo de las acciones a realizar con el rat�n
	//ACCIONES: Seleccionar pieza a mover, seleccionar d�nde colocar pieza
	//ACCIONES: Seleccionar modo de juego en el men�
	//...
}


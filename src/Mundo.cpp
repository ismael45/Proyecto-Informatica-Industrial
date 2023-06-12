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

	//SELECCIONAR OPCION FLORES
	if (opcion[0]) {
		listapiezas.inicializar_flores();
		tablero.dibujaTab_flores();
		tablero.dibujaMarco_flores();

		//COLOREAR LA CASILLA SELECICONADA DE ROJO
		for (int i = 0; i < 64; i++) {
			int columna = i / 8;
			int fila = i % 8;
			if (casillas[i]) {
				tablero.Seleccionar_Casilla(fila, columna);
			}
		}

	}

	//SELECCIONAR OPCION CLASICO
	if (opcion[1]) {
		listapiezas.inicializar_clasico();
		tablero.dibujaTab_clasico();
		tablero.dibujaMarco_clasico();



		//COLOREAR LA CASILLA SELECICONADA DE ROJO
		for (int i = 0; i < 64; i++) {
			int columna = i / 8; // Divide el �ndice por 8 para obtener la fila
			int fila = i % 8; // Obtiene el resto de la divisi�n para obtener la columna
			if (casillas[i]) {
				tablero.Seleccionar_Casilla(fila, columna);
			}
		}
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
	int movimiento = 0;
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


	//seleccionar opcion 1 
	if (posX >= -25.7677 && posX <= -16.1491 && posY <= 21.5664 && posY >= 14.5947) {
		cout << "Opcion 1" << endl;
		opcion[0] = true;
		opcion[1] = false;
	}

	//seleccionar opcion 2
	if (posX >= 16.8984 && posX <= 24.1805 && posY <= 21.5664 && posY >= 14.5947) {
		cout << "Opcion 2" << endl;
		opcion[0] = false;
		opcion[1] = true;
	}

	float tolerancia = 2;
	//SELECCION DE CASILLAS 
	for (int i = 0; i < 64; i++) {
		int columna = i / 8; // Divide el �ndice por 8 para obtener la fila
		int fila = i % 8; // Obtiene el resto de la divisi�n para obtener la columna
		if (posX >= tablero.getPos_Casilla(fila, columna).x - tolerancia &&
			posX <= tablero.getPos_Casilla(fila, columna).x + tolerancia &&
			posY >= tablero.getPos_Casilla(fila, columna).y - tolerancia &&
			posY <= tablero.getPos_Casilla(fila, columna).y + tolerancia) {
			casillas[i] = true;
			cout << "Casilla " << i << endl;
		}
		else {
			casillas[i] = false;
		}
	}
	//SELECION DE PIEZAS
	for (int i = 0; i < 32; i++) {
		if (posX >= listapiezas.piezas[i].getPos().x - tolerancia &&
			posX <= listapiezas.piezas[i].getPos().x + tolerancia &&
			posY >= listapiezas.piezas[i].getPos().y - tolerancia &&
			posY <= listapiezas.piezas[i].getPos().y + tolerancia) {
			piezas[i] = true;
			cout << "Pieza " << i << endl;
			cout << "Casilla " << Posicion_por_casilla(listapiezas.piezas[i].getPos().x,
				listapiezas.piezas[i].getPos().y) << endl;

		}
		else piezas[i] = false;

	}







	//Empieza el codigo de las acciones a realizar con el rat�n
	//ACCIONES: Seleccionar pieza a mover, seleccionar d�nde colocar pieza
	//ACCIONES: Seleccionar modo de juego en el men�
	//...
}



int Mundo::Posicion_por_casilla(int x, int y) {
	int valor = 0;
	if (x == -14 && y == -14)valor = 0;
	if (x == -10 && y == -14)valor = 1;
	if (x == -6 && y == -14)valor = 2;
	if (x == -2 && y == -14)valor = 3;
	if (x == 2 && y == -14)valor = 4;
	if (x == 6 && y == -14)valor = 5;
	if (x == 10 && y == -14)valor = 6;
	if (x == 14 && y == -14)valor = 7;
	if (x == -14 && y == -10)valor = 8;
	if (x == -10 && y == -10)valor = 9;
	if (x == -6 && y == -10)valor = 10;
	if (x == -2 && y == -10)valor = 11;
	if (x == 2 && y == -10)valor = 12;
	if (x == 6 && y == -10)valor = 13;
	if (x == 10 && y == -10)valor = 14;
	if (x == 14 && y == -10)valor = 15;
	if (x == -14 && y == -6)valor = 16;
	if (x == -10 && y == -6)valor = 17;
	if (x == -6 && y == -6)valor = 18;
	if (x == -2 && y == -6)valor = 19;
	if (x == 2 && y == -6)valor = 20;
	if (x == 6 && y == -6)valor = 21;
	if (x == 10 && y == -6)valor = 22;
	if (x == 14 && y == -6)valor = 23;
	if (x == -14 && y == -2)valor = 24;
	if (x == -10 && y == -2)valor = 25;
	if (x == -6 && y == -2)valor = 26;
	if (x == -2 && y == -2)valor = 27;
	if (x == 2 && y == -2)valor = 28;
	if (x == 6 && y == -2)valor = 29;
	if (x == 10 && y == -2)valor = 30;
	if (x == 14 && y == -2)valor = 31;
	if (x == -14 && y == 2)valor = 32;
	if (x == -10 && y == 2)valor = 33;
	if (x == -6 && y == 2)valor = 34;
	if (x == -2 && y == 2)valor = 35;
	if (x == 2 && y == 2)valor = 36;
	if (x == 6 && y == 2)valor = 37;
	if (x == 10 && y == 2)valor = 38;
	if (x == 14 && y == 2)valor = 39;
	if (x == -14 && y == 6)valor = 40;
	if (x == -10 && y == 6)valor = 41;
	if (x == -6 && y == 6)valor = 42;
	if (x == -2 && y == 6)valor = 43;
	if (x == 2 && y == 6)valor = 44;
	if (x == 6 && y == 6)valor = 45;
	if (x == 10 && y == 6)valor = 46;
	if (x == 14 && y == 6)valor = 47;
	if (x == -14 && y == 10)valor = 48;
	if (x == -10 && y == 10)valor = 49;
	if (x == -6 && y == 10)valor = 50;
	if (x == -2 && y == 10)valor = 51;
	if (x == 2 && y == 10)valor = 52;
	if (x == 6 && y == 10)valor = 53;
	if (x == 10 && y == 10)valor = 54;
	if (x == 14 && y == 10)valor = 55;
	if (x == -14 && y == 14)valor = 56;
	if (x == -10 && y == 14)valor = 57;
	if (x == -6 && y == 14)valor = 58;
	if (x == -2 && y == 14)valor = 59;
	if (x == 2 && y == 14)valor = 60;
	if (x == 6 && y == 14)valor = 61;
	if (x == 10 && y == 14)valor = 62;
	if (x == 14 && y == 14)valor = 63;
	return valor;
}


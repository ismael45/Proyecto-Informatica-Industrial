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
		listapiezas.actualizar_flores();
		tablero.dibujaTab_flores();
		tablero.dibujaMarco_flores();

		

		//COLOREAR LA CASILLA SELECICONADA DE ROJO
	//for (int i = 0; i < 64; i++) {
	//		if (casilla_seleccionada[i]) {
	//			tablero.Seleccionar_Casilla(i);
	//		}
	//	}

	}

	//SELECCIONAR OPCION CLASICO
	if (opcion[1]) {
		listapiezas.actualizar_clasico();
		tablero.dibujaTab_clasico();
		tablero.dibujaMarco_clasico();

		

		//COLOREAR LA CASILLA SELECICONADA DE ROJO
		//for (int i = 0; i < 64; i++) {
		//	int columna = i / 8; // Divide el �ndice por 8 para obtener la fila
		//	int fila = i % 8; // Obtiene el resto de la divisi�n para obtener la columna
		//	if (casilla_seleccionada[i]) {
		//		tablero.Seleccionar_Casilla(fila, columna);
		//	}
		//}
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


	float tolerancia = 2;




	//cuando se produzca un click
	if (down) {

		//SELECCION DE MENUS
		//seleccionar opcion 1 
		if (posX >= -25.7677 - 5 && posX <= -16.1491 - 5 && posY <= 21.5664 && posY >= 14.5947) {
			cout << "Opcion 1" << endl;
			opcion[0] = true;
			opcion[1] = false;

		}

		//seleccionar opcion 2
		if (posX >= 16.8984 + 5 && posX <= 24.1805 + 5 && posY <= 21.5664 && posY >= 14.5947) {
			cout << "Opcion 2" << endl;
			opcion[0] = false;
			opcion[1] = true;
		}


		//MOVIMIENTOS PIEZAS POR CLICKS
		if (tablero.estaDentroTablero(posX, posY) == true) {

			// SELECCION DE CASILLA
			for (int i = 0; i < 64; i++) {
				if (posX >= tablero.getPos_Casilla(i).x - tolerancia &&
					posX <= tablero.getPos_Casilla(i).x + tolerancia &&
					posY >= tablero.getPos_Casilla(i).y - tolerancia &&
					posY <= tablero.getPos_Casilla(i).y + tolerancia) {
					raton.casilla_seleccionada = i;
					raton.destino = { tablero.getPos_Casilla(i).x, tablero.getPos_Casilla(i).y };
					cout << listapiezas.piezas[0].getPos().x << ", " << listapiezas.piezas[0].getPos().y;

					// Verificar si la casilla seleccionada está ocupada por otro peón
					bool casilla_ocupada = false;
					for (int j = 0; j < 8; j++) {
						if (raton.peon_blanco_seleccionado != j &&
							raton.destino.x == listapiezas.peones_blancos[j].getPos().x &&
							raton.destino.y == listapiezas.peones_blancos[j].getPos().y) {
							casilla_ocupada = true;
							break;
						}
					}

					// Realizar el movimiento del peón si la casilla no está ocupada
					if (!casilla_ocupada && raton.peon_blanco_seleccionado != -1) {
						listapiezas.peones_blancos[raton.peon_blanco_seleccionado].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Peón blanco " << raton.peon_blanco_seleccionado << " a la casilla " << i << endl;
					}
				}
				else {
					raton.casilla_seleccionada = -1;
				}
			}

			///////////////////////////////////////////////////////////////////////////



			// SELECCION DE PEONES BLANCOS
			int peon_seleccionado_previo = raton.peon_blanco_seleccionado; // Almacenar el índice del peón previamente seleccionado
			raton.peon_blanco_seleccionado = -1; // Desseleccionar el peón por defecto

			for (int i = 0; i < 8; i++) {
				if (posX >= listapiezas.peones_blancos[i].getPos().x - tolerancia &&
					posX <= listapiezas.peones_blancos[i].getPos().x + tolerancia &&
					posY >= listapiezas.peones_blancos[i].getPos().y - tolerancia &&
					posY <= listapiezas.peones_blancos[i].getPos().y + tolerancia) {
					if (peon_seleccionado_previo == i) {
						// Hacer clic por segunda vez en el mismo peón: deseleccionar
						raton.peon_blanco_seleccionado = -1;
						cout << "Peón blanco " << i << " deseleccionado" << endl;
					}
					else {
						// Hacer clic en un peón diferente: seleccionar el nuevo peón
						raton.peon_blanco_seleccionado = i;
						cout << "Peón blanco " << i << " seleccionado" << endl;
					}
				}
			}


		}

	}
}
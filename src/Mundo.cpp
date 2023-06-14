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
	/*	for (int i = 0; i < 64; i++) {
			int columna = i / 8;
			int fila = i % 8;
			if (casilla_seleccionada[i]) {
				tablero.Seleccionar_Casilla(fila, columna);
			}
		}*/

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

	//cuando se produzca un click
	if (down) {
		//std::cout << (int)posX << "," << (int)posY << "\n";
		//MOVIMIENTOS PIEZAS POR CLICKS
		if (tablero.estaDentroTablero(posX, posY) == true) {
			if (raton.click == 0) {
				raton.origen = { (float)posX, (float)posY };
				raton.click = 1; //marcador de que se ha hecho click una primera vez
				//std::cout << "ORIGEN:"<<raton.origen.x << "," << raton.origen.y << "\n";
			}
			else if (raton.click == 1) {
				raton.destino = { (float)posX, (float)posY };
				raton.click = 0;
				//std::cout << "DESTINO:" << raton.destino.x << "," << raton.destino.y << "\n";
			}
		}
		//ELECCION DE MENUS
		//seleccionar opcion 1 
		if (posX >= -25.7677-5 && posX <= -16.1491-5 && posY <= 21.5664 && posY >= 14.5947) {
			cout << "Opcion 1" << endl;
			opcion[0] = true;
			opcion[1] = false;
		}

		//seleccionar opcion 2
		if (posX >= 16.8984+5 && posX <= 24.1805+5 && posY <= 21.5664 && posY >= 14.5947) {
			cout << "Opcion 2" << endl;
			opcion[0] = false;
			opcion[1] = true;

		}


		float tolerancia = 2;
		// SELECCION DE CASILLAS 
		for (int i = 0; i < 64; i++) {

			if (posX >= tablero.getPos_Casilla(i).x - tolerancia &&
				posX <= tablero.getPos_Casilla(i).x + tolerancia &&
				posY >= tablero.getPos_Casilla(i).y - tolerancia &&
				posY <= tablero.getPos_Casilla(i).y + tolerancia) {
				casilla_seleccionada[i] = true;
				cout << "Casilla " << i << endl;

			}
			else {
				casilla_seleccionada[i] = false;
			}
		}

	// SELECCION DE PEONES BLANCOS
		for (int i = 0; i < 8; i++) {
			if (posX >= listapiezas.peones_blancos[i].getPos().x - tolerancia &&
				posX <= listapiezas.peones_blancos[i].getPos().x + tolerancia &&
				posY >= listapiezas.peones_blancos[i].getPos().y - tolerancia &&
				posY <= listapiezas.peones_blancos[i].getPos().y + tolerancia) {
				if (peon_blanco_seleccionado == -1) {
					peon_blanco_seleccionado = i;
					cout << "Peon blanco " << i << " seleccionado" << endl;
				}
				else {
					peon_blanco_seleccionado = -1; // Deseleccionar el peón si ya había uno seleccionado
					cout << "Peon deseleccionado" << endl;
				}
			}
		}

		if (peon_blanco_seleccionado != -1 && raton.click == 0) {
			// Si hay un peón seleccionado y se ha hecho el segundo click en una casilla vacía
			if (!casilla_seleccionada[peon_blanco_seleccionado]) {
				listapiezas.peones_blancos[peon_blanco_seleccionado].setPos(raton.destino.x, raton.destino.y);
				cout << "Moviendo peon blanco " << peon_blanco_seleccionado << " a la casilla destino" << endl;
			}
			else {
				cout << "No se puede mover el peon " << peon_blanco_seleccionado << " a una casilla ocupada" << endl;
			}
			peon_blanco_seleccionado = -1; // Deseleccionar el peón después de hacer el movimiento
		}
		else if (raton.click == 0) {
			cout << "";
		}


/*		// SELECCION DE PEONES NEGROS
		for (int i = 0; i < 8; i++) {
			if (posX >= listapiezas.peones_negros[i].getPos().x - tolerancia &&
				posX <= listapiezas.peones_negros[i].getPos().x + tolerancia &&
				posY >= listapiezas.peones_negros[i].getPos().y - tolerancia &&
				posY <= listapiezas.peones_negros[i].getPos().y + tolerancia) {
				if (peon_negro_seleccionado == -1) {
					peon_negro_seleccionado = i;
					cout << "Peon negro " << i << " seleccionado" << endl;
				}
				else {
					peon_negro_seleccionado = -1; // Deseleccionar el peón si ya había uno seleccionado
					cout << "Peon negro deseleccionado" << endl;
				}
			}
		}

		if (peon_negro_seleccionado != -1 && raton.click == 0) {
			// Si hay un peón seleccionado y se ha hecho el segundo click en una casilla vacía
			if (!casillas[peon_negro_seleccionado]) {
				listapiezas.peones_negros[peon_negro_seleccionado].setPos(raton.destino.x, raton.destino.y);
				cout << "Moviendo peon negro " << peon_negro_seleccionado << " a la casilla destino" << endl;
			}
			else {
				cout << "No se puede mover el peon negro " << peon_negro_seleccionado << " a una casilla ocupada" << endl;
			}
			peon_negro_seleccionado = -1; // Deseleccionar el peón después de hacer el movimiento
		}
		else if (raton.click == 0) {
			cout << "";
		}*/


	/*	// SELECCION DE ALFILES BLANCOS
		for (int i = 0; i < 2; i++) {
			if (posX >= listapiezas.alfiles_blancos[i].getPos().x - tolerancia &&
				posX <= listapiezas.alfiles_blancos[i].getPos().x + tolerancia &&
				posY >= listapiezas.alfiles_blancos[i].getPos().y - tolerancia &&
				posY <= listapiezas.alfiles_blancos[i].getPos().y + tolerancia) {
				if (alfil_blanco_seleccionado == -1) {
					alfil_blanco_seleccionado = i;
					cout << "Alfil blanco " << i << " seleccionado" << endl;
				}
				else {
					alfil_blanco_seleccionado = -1; // Deseleccionar el alfil si ya había uno seleccionado
					cout << "Alfil blanco deseleccionado" << endl;
				}
			}
		}

		if (alfil_blanco_seleccionado != -1 && raton.click == 0) {
			// Si hay un alfil seleccionado y se ha hecho el segundo click en una casilla vacía
			if (!casillas[alfil_blanco_seleccionado + 8]) {
				listapiezas.alfiles_blancos[alfil_blanco_seleccionado].setPos(raton.destino.x, raton.destino.y);
				cout << "Moviendo alfil blanco " << alfil_blanco_seleccionado << " a la casilla destino" << endl;
			}
			else {
				cout << "No se puede mover el alfil blanco " << alfil_blanco_seleccionado << " a una casilla ocupada" << endl;
			}
			alfil_blanco_seleccionado = -1; // Deseleccionar el alfil después de hacer el movimiento
		}
		else if (raton.click == 0) {
			cout << "";
		}

		// SELECCION DE ALFILES NEGROS
		for (int i = 0; i < 2; i++) {
			if (posX >= listapiezas.alfiles_negros[i].getPos().x - tolerancia &&
				posX <= listapiezas.alfiles_negros[i].getPos().x + tolerancia &&
				posY >= listapiezas.alfiles_negros[i].getPos().y - tolerancia &&
				posY <= listapiezas.alfiles_negros[i].getPos().y + tolerancia) {
				if (alfil_negro_seleccionado == -1) {
					alfil_negro_seleccionado = i;
					cout << "Alfil negro " << i << " seleccionado" << endl;
				}
				else {
					alfil_negro_seleccionado = -1; // Deseleccionar el alfil si ya había uno seleccionado
					cout << "Alfil negro deseleccionado" << endl;
				}
			}
		}

		if (alfil_negro_seleccionado != -1 && raton.click == 0) {
			// Si hay un alfil seleccionado y se ha hecho el segundo click en una casilla vacía
			if (!casillas[alfil_negro_seleccionado + 56]) {
				listapiezas.alfiles_negros[alfil_negro_seleccionado].setPos(raton.destino.x, raton.destino.y);
				cout << "Moviendo alfil negro " << alfil_negro_seleccionado << " a la casilla destino" << endl;
			}
			else {
				cout << "No se puede mover el alfil negro " << alfil_negro_seleccionado << " a una casilla ocupada" << endl;
			}
			alfil_negro_seleccionado = -1; // Deseleccionar el alfil después de hacer el movimiento
		}
		else if (raton.click == 0) {
			cout << "";
		}

		// SELECCION DE CABALLOS BLANCOS
		for (int i = 0; i < 2; i++) {
			if (posX >= listapiezas.caballos_blancos[i].getPos().x - tolerancia &&
				posX <= listapiezas.caballos_blancos[i].getPos().x + tolerancia &&
				posY >= listapiezas.caballos_blancos[i].getPos().y - tolerancia &&
				posY <= listapiezas.caballos_blancos[i].getPos().y + tolerancia) {
				if (caballo_blanco_seleccionado == -1) {
					caballo_blanco_seleccionado = i;
					cout << "Caballo blanco " << i << " seleccionado" << endl;
				}
				else {
					caballo_blanco_seleccionado = -1; // Deseleccionar el caballo si ya había uno seleccionado
					cout << "Caballo blanco deseleccionado" << endl;
				}
			}
		}

		if (caballo_blanco_seleccionado != -1 && raton.click == 0) {
			// Si hay un caballo seleccionado y se ha hecho el segundo click en una casilla vacía
			if (!casillas[caballo_blanco_seleccionado + 16]) {
				listapiezas.caballos_blancos[caballo_blanco_seleccionado].setPos(raton.destino.x, raton.destino.y);
				cout << "Moviendo caballo blanco " << caballo_blanco_seleccionado << " a la casilla destino" << endl;
			}
			else {
				cout << "No se puede mover el caballo blanco " << caballo_blanco_seleccionado << " a una casilla ocupada" << endl;
			}
			caballo_blanco_seleccionado = -1; // Deseleccionar el caballo después de hacer el movimiento
		}
		else if (raton.click == 0) {
			cout << "";
		}

		// SELECCION DE CABALLOS NEGROS
		for (int i = 0; i < 2; i++) {
			if (posX >= listapiezas.caballos_negros[i].getPos().x - tolerancia &&
				posX <= listapiezas.caballos_negros[i].getPos().x + tolerancia &&
				posY >= listapiezas.caballos_negros[i].getPos().y - tolerancia &&
				posY <= listapiezas.caballos_negros[i].getPos().y + tolerancia) {
				if (caballo_negro_seleccionado == -1) {
					caballo_negro_seleccionado = i;
					cout << "Caballo negro " << i << " seleccionado" << endl;
				}
				else {
					caballo_negro_seleccionado = -1; // Deseleccionar el caballo si ya había uno seleccionado
					cout << "Caballo negro deseleccionado" << endl;
				}
			}
		}

		if (caballo_negro_seleccionado != -1 && raton.click == 0) {
			// Si hay un caballo seleccionado y se ha hecho el segundo click en una casilla vacía
			if (!casillas[caballo_negro_seleccionado + 48]) {
				listapiezas.caballos_negros[caballo_negro_seleccionado].setPos(raton.destino.x, raton.destino.y);
				cout << "Moviendo caballo negro " << caballo_negro_seleccionado << " a la casilla destino" << endl;
			}
			else {
				cout << "No se puede mover el caballo negro " << caballo_negro_seleccionado << " a una casilla ocupada" << endl;
			}
			caballo_negro_seleccionado = -1; // Deseleccionar el caballo después de hacer el movimiento
		}
		else if (raton.click == 0) {
			cout << "";
		}

		// SELECCION DE TORRES BLANCAS
		for (int i = 0; i < 2; i++) {
			if (posX >= listapiezas.torres_blancas[i].getPos().x - tolerancia &&
				posX <= listapiezas.torres_blancas[i].getPos().x + tolerancia &&
				posY >= listapiezas.torres_blancas[i].getPos().y - tolerancia &&
				posY <= listapiezas.torres_blancas[i].getPos().y + tolerancia) {
				if (torre_blanca_seleccionada == -1) {
					torre_blanca_seleccionada = i;
					cout << "Torre blanca " << i << " seleccionada" << endl;
				}
				else {
					torre_blanca_seleccionada = -1; // Deseleccionar la torre si ya había una seleccionada
					cout << "Torre blanca deseleccionada" << endl;
				}
			}
		}

		if (torre_blanca_seleccionada != -1 && raton.click == 0) {
			// Si hay una torre seleccionada y se ha hecho el segundo click en una casilla vacía
			if (!casillas[torre_blanca_seleccionada + 24]) {
				listapiezas.torres_blancas[torre_blanca_seleccionada].setPos(raton.destino.x, raton.destino.y);
				cout << "Moviendo torre blanca " << torre_blanca_seleccionada << " a la casilla destino" << endl;
			}
			else {
				cout << "No se puede mover la torre blanca " << torre_blanca_seleccionada << " a una casilla ocupada" << endl;
			}
			torre_blanca_seleccionada = -1; // Deseleccionar la torre después de hacer el movimiento
		}
		else if (raton.click == 0) {
			cout << "";
		}

		// SELECCION DE TORRES NEGRAS
		for (int i = 0; i < 2; i++) {
			if (posX >= listapiezas.torres_negras[i].getPos().x - tolerancia &&
				posX <= listapiezas.torres_negras[i].getPos().x + tolerancia &&
				posY >= listapiezas.torres_negras[i].getPos().y - tolerancia &&
				posY <= listapiezas.torres_negras[i].getPos().y + tolerancia) {
				if (torre_negra_seleccionada == -1) {
					torre_negra_seleccionada = i;
					cout << "Torre negra " << i << " seleccionada" << endl;
				}
				else {
					torre_negra_seleccionada = -1; // Deseleccionar la torre si ya había una seleccionada
					cout << "Torre negra deseleccionada" << endl;
				}
			}
		}

		if (torre_negra_seleccionada != -1 && raton.click == 0) {
			// Si hay una torre seleccionada y se ha hecho el segundo click en una casilla vacía
			if (!casillas[torre_negra_seleccionada + 56]) {
				listapiezas.torres_negras[torre_negra_seleccionada].setPos(raton.destino.x, raton.destino.y);
				cout << "Moviendo torre negra " << torre_negra_seleccionada << " a la casilla destino" << endl;
			}
			else {
				cout << "No se puede mover la torre negra " << torre_negra_seleccionada << " a una casilla ocupada" << endl;
			}
			torre_negra_seleccionada = -1; // Deseleccionar la torre después de hacer el movimiento
		}
		else if (raton.click == 0) {
			cout << "";
		}

		// SELECCION DE REY BLANCO
		if (posX >= listapiezas.rey_blanco.getPos().x - tolerancia &&
			posX <= listapiezas.rey_blanco.getPos().x + tolerancia &&
			posY >= listapiezas.rey_blanco.getPos().y - tolerancia &&
			posY <= listapiezas.rey_blanco.getPos().y + tolerancia) {
			if (rey_blanco_seleccionado == false) {
				rey_blanco_seleccionado = true;
				cout << "Rey blanco seleccionado" << endl;
			}
			else {
				rey_blanco_seleccionado = false; // Deseleccionar el rey si ya estaba seleccionado
				cout << "Rey blanco deseleccionado" << endl;
			}
		}

		if (rey_blanco_seleccionado && raton.click == 0) {
			// Si el rey blanco está seleccionado y se ha hecho el segundo click en una casilla vacía
			if (!casillas[60]) {
				listapiezas.rey_blanco.setPos(raton.destino.x, raton.destino.y);
				cout << "Moviendo rey blanco a la casilla destino" << endl;
			}
			else {
				cout << "No se puede mover el rey blanco a una casilla ocupada" << endl;
			}
			rey_blanco_seleccionado = false; // Deseleccionar el rey después de hacer el movimiento
		}
		else if (raton.click == 0) {
			cout << "";
		}

		// SELECCION DE REY NEGRO
		if (posX >= listapiezas.rey_negro.getPos().x - tolerancia &&
			posX <= listapiezas.rey_negro.getPos().x + tolerancia &&
			posY >= listapiezas.rey_negro.getPos().y - tolerancia &&
			posY <= listapiezas.rey_negro.getPos().y + tolerancia) {
			if (rey_negro_seleccionado == false) {
				rey_negro_seleccionado = true;
				cout << "Rey negro seleccionado" << endl;
			}
			else {
				rey_negro_seleccionado = false; // Deseleccionar el rey si ya estaba seleccionado
				cout << "Rey negro deseleccionado" << endl;
			}
		}

		if (rey_negro_seleccionado && raton.click == 0) {
			// Si el rey negro está seleccionado y se ha hecho el segundo click en una casilla vacía
			if (!casillas[4]) {
				listapiezas.rey_negro.setPos(raton.destino.x, raton.destino.y);
				cout << "Moviendo rey negro a la casilla destino" << endl;
			}
			else {
				cout << "No se puede mover el rey negro a una casilla ocupada" << endl;
			}
			rey_negro_seleccionado = false; // Deseleccionar el rey después de hacer el movimiento
		}
		else if (raton.click == 0) {
			cout << "";
		}

		// SELECCION DE REINA BLANCA
		if (posX >= listapiezas.reina_blanca.getPos().x - tolerancia &&
			posX <= listapiezas.reina_blanca.getPos().x + tolerancia &&
			posY >= listapiezas.reina_blanca.getPos().y - tolerancia &&
			posY <= listapiezas.reina_blanca.getPos().y + tolerancia) {
			if (reina_blanca_seleccionada == false) {
				reina_blanca_seleccionada = true;
				cout << "Reina blanca seleccionada" << endl;
			}
			else {
				reina_blanca_seleccionada = false; // Deseleccionar la reina si ya estaba seleccionada
				cout << "Reina blanca deseleccionada" << endl;
			}
		}

		if (reina_blanca_seleccionada && raton.click == 0) {
			// Si la reina blanca está seleccionada y se ha hecho el segundo click en una casilla vacía
			if (!casillas[59]) {
				listapiezas.reina_blanca.setPos(raton.destino.x, raton.destino.y);
				cout << "Moviendo reina blanca a la casilla destino" << endl;
			}
			else {
				cout << "No se puede mover la reina blanca a una casilla ocupada" << endl;
			}
			reina_blanca_seleccionada = false; // Deseleccionar la reina después de hacer el movimiento
		}
		else if (raton.click == 0) {
			cout << "";
		}

		// SELECCION DE REINA NEGRA
		if (posX >= listapiezas.reina_negra.getPos().x - tolerancia &&
			posX <= listapiezas.reina_negra.getPos().x + tolerancia &&
			posY >= listapiezas.reina_negra.getPos().y - tolerancia &&
			posY <= listapiezas.reina_negra.getPos().y + tolerancia) {
			if (reina_negra_seleccionada == false) {
				reina_negra_seleccionada = true;
				cout << "Reina negra seleccionada" << endl;
			}
			else {
				reina_negra_seleccionada = false; // Deseleccionar la reina si ya estaba seleccionada
				cout << "Reina negra deseleccionada" << endl;
			}
		}

		if (reina_negra_seleccionada && raton.click == 0) {
			// Si la reina negra está seleccionada y se ha hecho el segundo click en una casilla vacía
			if (!casillas[3]) {
				listapiezas.reina_negra.setPos(raton.destino.x, raton.destino.y);
				cout << "Moviendo reina negra a la casilla destino" << endl;
			}
			else {
				cout << "No se puede mover la reina negra a una casilla ocupada" << endl;
			}
			reina_negra_seleccionada = false; // Deseleccionar la reina después de hacer el movimiento
		}
		else if (raton.click == 0) {
			cout << "";
		}*/












































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


#include "Movimientos.h"



void Movimientos::MouseButton(int x, int y, int button, bool down) {
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
	//conversi�n de coordenadas del raton en pantalla a coordenadas en nuestro mundo
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
					cout << raton.destino.x << ", " << raton.destino.y << endl;

					// Verificar si la casilla seleccionada está ocupada por otra pieza
					bool casilla_ocupada = false;
					for (int j = 0; j < 32; j++) {
						if (raton.pieza_seleccionada != j &&
							raton.destino.x == listapiezas.piezas[j].getPos().x &&
							raton.destino.y == listapiezas.piezas[j].getPos().y) {
							casilla_ocupada = true;
							break;
						}
					}

					//PIEZAS BLANCAS//


					// Realizar el movimiento del peón si la casilla no está ocupada
					if (!casilla_ocupada && raton.peon_blanco_seleccionado != -1 && movimiento_peon()) {
						listapiezas.peones_blancos[raton.peon_blanco_seleccionado].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Peón blanco " << raton.peon_blanco_seleccionado << " a la casilla " << i << endl;
					}

					// Realizar el movimiento de la torre si la casilla no está ocupada
					if (!casilla_ocupada && raton.torre_blanca_seleccionada != -1) {
						listapiezas.torres_blancas[raton.torre_blanca_seleccionada].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Torre blanca " << raton.torre_blanca_seleccionada << " a la casilla " << i << endl;
					}

					// Realizar el movimiento del caballo blanco si la casilla no está ocupada
					if (!casilla_ocupada && raton.caballo_blanco_seleccionado != -1) {
						listapiezas.caballos_blancos[raton.caballo_blanco_seleccionado].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Caballo blanco " << raton.caballo_blanco_seleccionado << " a la casilla " << i << endl;
					}

					// Realizar el movimiento del alfil blanco si la casilla no está ocupada
					if (!casilla_ocupada && raton.alfil_blanco_seleccionado != -1) {
						listapiezas.alfiles_blancos[raton.alfil_blanco_seleccionado].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Alfil blanco " << raton.alfil_blanco_seleccionado << " a la casilla " << i << endl;
					}

					// Realizar el movimiento del rey blanco si la casilla no está ocupada
					if (!casilla_ocupada && raton.rey_blanco_seleccionado != -1) {
						listapiezas.rey_blanco.setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Rey blanco a la casilla " << i << endl;
					}

					// Realizar el movimiento de la reina blanca si la casilla no está ocupada
					if (!casilla_ocupada && raton.reina_blanca_seleccionada != -1) {
						listapiezas.reina_blanca.setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Reina blanca a la casilla " << i << endl;
					}

					//PIEZAS NEGRAS//

					// Realizar el movimiento del peón negro si la casilla no está ocupada
					if (!casilla_ocupada && raton.peon_negro_seleccionado != -1) {
						listapiezas.peones_negros[raton.peon_negro_seleccionado].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Peón negro " << raton.peon_negro_seleccionado << " a la casilla " << i << endl;
					}

					// Realizar el movimiento de la torre negra si la casilla no está ocupada
					if (!casilla_ocupada && raton.torre_negra_seleccionada != -1) {
						listapiezas.torres_negras[raton.torre_negra_seleccionada].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Torre negra " << raton.torre_negra_seleccionada << " a la casilla " << i << endl;
					}

					// Realizar el movimiento del caballo negro si la casilla no está ocupada
					if (!casilla_ocupada && raton.caballo_negro_seleccionado != -1) {
						listapiezas.caballos_negros[raton.caballo_negro_seleccionado].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Caballo negro " << raton.caballo_negro_seleccionado << " a la casilla " << i << endl;
					}

					// Realizar el movimiento del alfil negro si la casilla no está ocupada
					if (!casilla_ocupada && raton.alfil_negro_seleccionado != -1) {
						listapiezas.alfiles_negros[raton.alfil_negro_seleccionado].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Alfil negro " << raton.alfil_negro_seleccionado << " a la casilla " << i << endl;
					}

					// Realizar el movimiento del rey negro si la casilla no está ocupada
					if (!casilla_ocupada && raton.rey_negro_seleccionado != -1) {
						listapiezas.rey_negro.setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Rey negro a la casilla " << i << endl;
					}

					// Realizar el movimiento de la reina negra si la casilla no está ocupada
					if (!casilla_ocupada && raton.reina_negra_seleccionada != -1) {
						listapiezas.reina_negra.setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Reina negra a la casilla " << i << endl;
					}



				}
				else {
					raton.casilla_seleccionada = -1;
				}
			}

			//////////////////////////////////SELECCION DE PIEZAS/////////////////////////////////////////


			//$$$$$$$$$$$$$$$PIEZAS BLANCAS$$$$$$$$$$$$$$$$$$//


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
			/////////////////////////

					// SELECCION DE TORRES BLANCAS
			int torre_seleccionada_previa = raton.torre_blanca_seleccionada; // Almacenar el índice de la torre previamente seleccionada
			raton.torre_blanca_seleccionada = -1; // Desseleccionar la torre por defecto

			for (int i = 0; i < 2; i++) {
				if (posX >= listapiezas.torres_blancas[i].getPos().x - tolerancia &&
					posX <= listapiezas.torres_blancas[i].getPos().x + tolerancia &&
					posY >= listapiezas.torres_blancas[i].getPos().y - tolerancia &&
					posY <= listapiezas.torres_blancas[i].getPos().y + tolerancia) {
					if (torre_seleccionada_previa == i) {
						// Hacer clic por segunda vez en la misma torre: deseleccionar
						raton.torre_blanca_seleccionada = -1;
						cout << "Torre blanca " << i << " deseleccionada" << endl;
					}
					else {
						// Hacer clic en un peón diferente: seleccionar la nueva torre
						raton.torre_blanca_seleccionada = i;
						cout << "Torre blanca " << i << " seleccionada" << endl;
					}
				}
			}
			/////////////////////////

					// SELECCION DE CABALLOS BLANCOS
			int caballo_blanco_seleccionado_previo = raton.caballo_blanco_seleccionado; // Almacenar el índice del caballo blanco previamente seleccionado
			raton.caballo_blanco_seleccionado = -1; // Desseleccionar el caballo blanco por defecto

			for (int i = 0; i < 2; i++) {
				if (posX >= listapiezas.caballos_blancos[i].getPos().x - tolerancia &&
					posX <= listapiezas.caballos_blancos[i].getPos().x + tolerancia &&
					posY >= listapiezas.caballos_blancos[i].getPos().y - tolerancia &&
					posY <= listapiezas.caballos_blancos[i].getPos().y + tolerancia) {
					if (caballo_blanco_seleccionado_previo == i) {
						// Hacer clic por segunda vez en el mismo caballo blanco: deseleccionar
						raton.caballo_blanco_seleccionado = -1;
						cout << "Caballo blanco " << i << " deseleccionado" << endl;
					}
					else {
						// Hacer clic en un caballo blanco diferente: seleccionar el nuevo caballo blanco
						raton.caballo_blanco_seleccionado = i;
						cout << "Caballo blanco " << i << " seleccionado" << endl;
					}
				}
			}
			/////////////////////////

			// SELECCION DE ALFILES BLANCOS
			int alfil_blanco_seleccionado_previo = raton.alfil_blanco_seleccionado; // Almacenar el índice del alfil blanco previamente seleccionado
			raton.alfil_blanco_seleccionado = -1; // Desseleccionar el alfil blanco por defecto

			for (int i = 0; i < 2; i++) {
				if (posX >= listapiezas.alfiles_blancos[i].getPos().x - tolerancia &&
					posX <= listapiezas.alfiles_blancos[i].getPos().x + tolerancia &&
					posY >= listapiezas.alfiles_blancos[i].getPos().y - tolerancia &&
					posY <= listapiezas.alfiles_blancos[i].getPos().y + tolerancia) {
					if (alfil_blanco_seleccionado_previo == i) {
						// Hacer clic por segunda vez en el mismo alfil blanco: deseleccionar
						raton.alfil_blanco_seleccionado = -1;
						cout << "Alfil blanco " << i << " deseleccionado" << endl;
					}
					else {
						// Hacer clic en un alfil blanco diferente: seleccionar el nuevo alfil blanco
						raton.alfil_blanco_seleccionado = i;
						cout << "Alfil blanco " << i << " seleccionado" << endl;
					}
				}
			}
			/////////////////////////

			// SELECCION DE REY BLANCO
			int rey_blanco_seleccionado_previo = raton.rey_blanco_seleccionado; // Almacenar el índice del rey blanco previamente seleccionado
			raton.rey_blanco_seleccionado = -1; // Desseleccionar el rey blanco por defecto

			// Solo hay un rey blanco
			if (posX >= listapiezas.rey_blanco.getPos().x - tolerancia &&
				posX <= listapiezas.rey_blanco.getPos().x + tolerancia &&
				posY >= listapiezas.rey_blanco.getPos().y - tolerancia &&
				posY <= listapiezas.rey_blanco.getPos().y + tolerancia) {
				if (rey_blanco_seleccionado_previo == 0) {
					// Hacer clic por segunda vez en el mismo rey blanco: deseleccionar
					raton.rey_blanco_seleccionado = -1;
					cout << "Rey blanco deseleccionado" << endl;
				}
				else {
					// Hacer clic en un rey blanco diferente: seleccionar el nuevo rey blanco
					raton.rey_blanco_seleccionado = 0;
					cout << "Rey blanco seleccionado" << endl;
				}
			}
			/////////////////////////

							// SELECCION DE REINA BLANCA
			int reina_blanca_seleccionada_previa = raton.reina_blanca_seleccionada; // Almacenar el índice de la reina blanca previamente seleccionada
			raton.reina_blanca_seleccionada = -1; // Desseleccionar la reina blanca por defecto

			// Solo hay una reina blanca
			if (posX >= listapiezas.reina_blanca.getPos().x - tolerancia &&
				posX <= listapiezas.reina_blanca.getPos().x + tolerancia &&
				posY >= listapiezas.reina_blanca.getPos().y - tolerancia &&
				posY <= listapiezas.reina_blanca.getPos().y + tolerancia) {
				if (reina_blanca_seleccionada_previa == 0) {
					// Hacer clic por segunda vez en la misma reina blanca: deseleccionar
					raton.reina_blanca_seleccionada = -1;
					cout << "Reina blanca deseleccionada" << endl;
				}
				else {
					// Hacer clic en una reina blanca diferente: seleccionar la nueva reina blanca
					raton.reina_blanca_seleccionada = 0;
					cout << "Reina blanca seleccionada" << endl;
				}
			}
			/////////////////////////


	//$$$$$$$$$$$$$$$PIEZAS NEGRAS$$$$$$$$$$$$$$$$$$//

			// SELECCION DE PEONES NEGROS
			int peon_negro_seleccionado_previo = raton.peon_negro_seleccionado; // Almacenar el índice del peón negro previamente seleccionado
			raton.peon_negro_seleccionado = -1; // Desseleccionar el peón negro por defecto

			for (int i = 0; i < 8; i++) {
				if (posX >= listapiezas.peones_negros[i].getPos().x - tolerancia &&
					posX <= listapiezas.peones_negros[i].getPos().x + tolerancia &&
					posY >= listapiezas.peones_negros[i].getPos().y - tolerancia &&
					posY <= listapiezas.peones_negros[i].getPos().y + tolerancia) {
					if (peon_negro_seleccionado_previo == i) {
						// Hacer clic por segunda vez en el mismo peón negro: deseleccionar
						raton.peon_negro_seleccionado = -1;
						cout << "Peón negro " << i << " deseleccionado" << endl;
					}
					else {
						// Hacer clic en un peón negro diferente: seleccionar el nuevo peón negro
						raton.peon_negro_seleccionado = i;
						cout << "Peón negro " << i << " seleccionado" << endl;
					}
				}
			}
			/////////////////////////

			// SELECCION DE TORRES NEGRAS
			int torre_negra_seleccionada_previa = raton.torre_negra_seleccionada; // Almacenar el índice de la torre negra previamente seleccionada
			raton.torre_negra_seleccionada = -1; // Desseleccionar la torre negra por defecto

			for (int i = 0; i < 2; i++) {
				if (posX >= listapiezas.torres_negras[i].getPos().x - tolerancia &&
					posX <= listapiezas.torres_negras[i].getPos().x + tolerancia &&
					posY >= listapiezas.torres_negras[i].getPos().y - tolerancia &&
					posY <= listapiezas.torres_negras[i].getPos().y + tolerancia) {
					if (torre_negra_seleccionada_previa == i) {
						// Hacer clic por segunda vez en la misma torre negra: deseleccionar
						raton.torre_negra_seleccionada = -1;
						cout << "Torre negra " << i << " deseleccionada" << endl;
					}
					else {
						// Hacer clic en una torre negra diferente: seleccionar la nueva torre negra
						raton.torre_negra_seleccionada = i;
						cout << "Torre negra " << i << " seleccionada" << endl;
					}
				}
			}
			/////////////////////////

			// SELECCION DE CABALLOS NEGROS
			int caballo_negro_seleccionado_previo = raton.caballo_negro_seleccionado; // Almacenar el índice del caballo negro previamente seleccionado
			raton.caballo_negro_seleccionado = -1; // Desseleccionar el caballo negro por defecto

			for (int i = 0; i < 2; i++) {
				if (posX >= listapiezas.caballos_negros[i].getPos().x - tolerancia &&
					posX <= listapiezas.caballos_negros[i].getPos().x + tolerancia &&
					posY >= listapiezas.caballos_negros[i].getPos().y - tolerancia &&
					posY <= listapiezas.caballos_negros[i].getPos().y + tolerancia) {
					if (caballo_negro_seleccionado_previo == i) {
						// Hacer clic por segunda vez en el mismo caballo negro: deseleccionar
						raton.caballo_negro_seleccionado = -1;
						cout << "Caballo negro " << i << " deseleccionado" << endl;
					}
					else {
						// Hacer clic en un caballo negro diferente: seleccionar el nuevo caballo negro
						raton.caballo_negro_seleccionado = i;
						cout << "Caballo negro " << i << " seleccionado" << endl;
					}
				}
			}
			/////////////////////////

			// SELECCION DE ALFILES NEGROS
			int alfil_negro_seleccionado_previo = raton.alfil_negro_seleccionado; // Almacenar el índice del alfil negro previamente seleccionado
			raton.alfil_negro_seleccionado = -1; // Desseleccionar el alfil negro por defecto

			for (int i = 0; i < 2; i++) {
				if (posX >= listapiezas.alfiles_negros[i].getPos().x - tolerancia &&
					posX <= listapiezas.alfiles_negros[i].getPos().x + tolerancia &&
					posY >= listapiezas.alfiles_negros[i].getPos().y - tolerancia &&
					posY <= listapiezas.alfiles_negros[i].getPos().y + tolerancia) {
					if (alfil_negro_seleccionado_previo == i) {
						// Hacer clic por segunda vez en el mismo alfil negro: deseleccionar
						raton.alfil_negro_seleccionado = -1;
						cout << "Alfil negro " << i << " deseleccionado" << endl;
					}
					else {
						// Hacer clic en un alfil negro diferente: seleccionar el nuevo alfil negro
						raton.alfil_negro_seleccionado = i;
						cout << "Alfil negro " << i << " seleccionado" << endl;
					}
				}
			}
			/////////////////////////

			// SELECCION DE REY NEGRO
			int rey_negro_seleccionado_previo = raton.rey_negro_seleccionado; // Almacenar el índice del rey negro previamente seleccionado
			raton.rey_negro_seleccionado = -1; // Desseleccionar el rey negro por defecto

			// Solo hay un rey negro
			if (posX >= listapiezas.rey_negro.getPos().x - tolerancia &&
				posX <= listapiezas.rey_negro.getPos().x + tolerancia &&
				posY >= listapiezas.rey_negro.getPos().y - tolerancia &&
				posY <= listapiezas.rey_negro.getPos().y + tolerancia) {
				if (rey_negro_seleccionado_previo == 0) {
					// Hacer clic por segunda vez en el mismo rey negro: deseleccionar
					raton.rey_negro_seleccionado = -1;
					cout << "Rey negro deseleccionado" << endl;
				}
				else {
					// Hacer clic en un rey negro diferente: seleccionar el nuevo rey negro
					raton.rey_negro_seleccionado = 0;
					cout << "Rey negro seleccionado" << endl;
				}
			}
			/////////////////////////

			// SELECCION DE REINA NEGRA
			int reina_negra_seleccionada_previa = raton.reina_negra_seleccionada; // Almacenar el índice de la reina negra previamente seleccionada
			raton.reina_negra_seleccionada = -1; // Desseleccionar la reina negra por defecto

			// Solo hay una reina negra
			if (posX >= listapiezas.reina_negra.getPos().x - tolerancia &&
				posX <= listapiezas.reina_negra.getPos().x + tolerancia &&
				posY >= listapiezas.reina_negra.getPos().y - tolerancia &&
				posY <= listapiezas.reina_negra.getPos().y + tolerancia) {
				if (reina_negra_seleccionada_previa == 0) {
					// Hacer clic por segunda vez en la misma reina negra: deseleccionar
					raton.reina_negra_seleccionada = -1;
					cout << "Reina negra deseleccionada" << endl;
				}
				else {
					// Hacer clic en una reina negra diferente: seleccionar la nueva reina negra
					raton.reina_negra_seleccionada = 0;
					cout << "Reina negra seleccionada" << endl;
				}
			}
			/////////////////////////



		}

	}

	
}


void Movimientos::dibuja() {
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
		//	if (casilla_seleccionada[i]) {
		//		tablero.Seleccionar_Casilla(fila, columna);
		//	}
		//}
	}
}


bool Movimientos::movimiento_peon() {
	for (int i = 0; i < 8; i++) {
		if (raton.destino.x == listapiezas.peones_blancos[i].getPos().x &&
			raton.destino.y == listapiezas.peones_blancos[i].getPos().y + 1 ) {
			return true;
		}
	}
	return false;
}


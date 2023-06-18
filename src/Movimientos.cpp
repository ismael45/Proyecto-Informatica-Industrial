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
				if (posX > tablero.getPos_Casilla(i).x - tolerancia &&
					posX < tablero.getPos_Casilla(i).x + tolerancia &&
					posY > tablero.getPos_Casilla(i).y - tolerancia &&
					posY < tablero.getPos_Casilla(i).y + tolerancia) 
				{
					raton.casilla_seleccionada = i;
					raton.destino = { tablero.getPos_Casilla(i).x, tablero.getPos_Casilla(i).y };
					//cout << raton.destino.x << ", " << raton.destino.y << endl;

					// Verificar si la casilla seleccionada está ocupada por otra pieza
					bool casilla_ocupada = false;
					for (int j = 0; j < 32; j++) {
						if (raton.pieza_seleccionada != j &&
							raton.destino.x == listapiezas.piezas[j].getPos().x &&
							raton.destino.y == listapiezas.piezas[j].getPos().y) {
							casilla_ocupada = true;
							raton.origen= { tablero.getPos_Casilla(i).x, tablero.getPos_Casilla(i).y };
							//cout << "Origen:" << raton.origen.x << "," << raton.origen.y << endl;
							break;
						}
						
					}

					//PIEZAS BLANCAS//


					// Realizar el movimiento del peón si la casilla no está ocupada
					if (!casilla_ocupada && raton.peon_blanco_seleccionado != -1 && movimiento_peon_blanco()&& turnos()) {
						pos_peonB = { raton.destino };
						jaque();
						t = true;
						listapiezas.peones_blancos[raton.peon_blanco_seleccionado].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Peón blanco " << raton.peon_blanco_seleccionado << " a la casilla " << (tablero.getCasilla_Ind(i)).getCodigo() << endl;
						cout << "****Turno Negras****" << endl;
					}

					// Realizar el movimiento de la torre si la casilla no está ocupada
					if (!casilla_ocupada && raton.torre_blanca_seleccionada != -1 && movimiento_torre()&& turnos()) {
						pos_torreB = { raton.destino };
						jaque();
						t = true;
						listapiezas.torres_blancas[raton.torre_blanca_seleccionada].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Torre blanca " << raton.torre_blanca_seleccionada << " a la casilla " << (tablero.getCasilla_Ind(i)).getCodigo() << endl;
						cout << "****Turno Negras****" << endl;
					}

					// Realizar el movimiento del caballo blanco si la casilla no está ocupada
					if (!casilla_ocupada && raton.caballo_blanco_seleccionado != -1 && movimiento_caballo() && turnos()) {
						pos_caballoB = { raton.destino };
						jaque();
						t = true;
						listapiezas.caballos_blancos[raton.caballo_blanco_seleccionado].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Caballo blanco " << raton.caballo_blanco_seleccionado << " a la casilla " << (tablero.getCasilla_Ind(i)).getCodigo() << endl;
						cout << "****Turno Negras****" << endl;
					}

					// Realizar el movimiento del alfil blanco si la casilla no está ocupada
					if (!casilla_ocupada && raton.alfil_blanco_seleccionado != -1 && movimiento_alfil() && turnos()) {
						pos_alfilB = { raton.destino };
						jaque();
						t = true;
						listapiezas.alfiles_blancos[raton.alfil_blanco_seleccionado].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Alfil blanco " << raton.alfil_blanco_seleccionado << " a la casilla " << (tablero.getCasilla_Ind(i)).getCodigo() << endl;
						cout << "****Turno Negras****" << endl;
					}

					// Realizar el movimiento del rey blanco si la casilla no está ocupada
					if (!casilla_ocupada && raton.rey_blanco_seleccionado != -1 && movimiento_rey() && turnos()) {
						pos_reyBlanco = { raton.destino };
						t = true;
						listapiezas.rey_blanco.setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Rey blanco a la casilla " << (tablero.getCasilla_Ind(i)).getCodigo() << endl;
						cout << "****Turno Negras****" << endl;
					}

					// Realizar el movimiento de la reina blanca si la casilla no está ocupada
					if (!casilla_ocupada && raton.reina_blanca_seleccionada != -1 && (movimiento_alfil() || movimiento_torre()) && turnos()) {
						t = true;
						listapiezas.reina_blanca.setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Reina blanca a la casilla " << (tablero.getCasilla_Ind(i)).getCodigo() << endl;
						cout << "****Turno Negras****" << endl;
					}

					//PIEZAS NEGRAS//

					// Realizar el movimiento del peón negro si la casilla no está ocupada
					if (!casilla_ocupada && raton.peon_negro_seleccionado != -1 && movimiento_peon_negro() && !turnos()) {
						pos_peonN = { raton.destino };
						jaque();
						t = false;
						listapiezas.peones_negros[raton.peon_negro_seleccionado].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Peón negro " << raton.peon_negro_seleccionado << " a la casilla " << tablero.getCasilla_Ind(i).getCodigo() << endl;
						cout << "***Turno Blancas****" << endl;
					}

					// Realizar el movimiento de la torre negra si la casilla no está ocupada
					if (!casilla_ocupada && raton.torre_negra_seleccionada != -1 && movimiento_torre()&&!turnos()) {
						pos_torreN = { raton.destino };
						jaque();
						t = false;
						listapiezas.torres_negras[raton.torre_negra_seleccionada].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Torre negra " << raton.torre_negra_seleccionada << " a la casilla " << tablero.getCasilla_Ind(i).getCodigo() << endl;
						cout << "***Turno Blancas****" << endl;
					}

					// Realizar el movimiento del caballo negro si la casilla no está ocupada
					if (!casilla_ocupada && raton.caballo_negro_seleccionado != -1 && movimiento_caballo()&&!turnos()) {
						pos_caballoN = { raton.destino };
						jaque();
						t = false;
						listapiezas.caballos_negros[raton.caballo_negro_seleccionado].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Caballo negro " << raton.caballo_negro_seleccionado << " a la casilla " << tablero.getCasilla_Ind(i).getCodigo() << endl;
						cout << "***Turno Blancas****" << endl;
					}

					// Realizar el movimiento del alfil negro si la casilla no está ocupada
					if (!casilla_ocupada && raton.alfil_negro_seleccionado != -1 && movimiento_alfil()&&!turnos()) {
						pos_alfilN = { raton.destino };
						jaque();
						t = false;
						listapiezas.alfiles_negros[raton.alfil_negro_seleccionado].setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Alfil negro " << raton.alfil_negro_seleccionado << " a la casilla " << tablero.getCasilla_Ind(i).getCodigo() << endl;
						cout << "***Turno Blancas****" << endl;
					}

					// Realizar el movimiento del rey negro si la casilla no está ocupada
					if (!casilla_ocupada && raton.rey_negro_seleccionado != -1 && movimiento_rey() && !turnos()) {
						pos_reyNegro = { raton.destino };
						t = false;
						listapiezas.rey_negro.setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Rey negro a la casilla " << tablero.getCasilla_Ind(i).getCodigo() << endl;
						cout << "***Turno Blancas****" << endl;
					}

					// Realizar el movimiento de la reina negra si la casilla no está ocupada
					if (!casilla_ocupada && raton.reina_negra_seleccionada != -1 && ( movimiento_alfil()|| movimiento_torre() ) && !turnos()) {
						t = false;
						listapiezas.reina_negra.setPos(raton.destino.x, raton.destino.y);
						cout << "Movimiento realizado: Reina negra a la casilla " << tablero.getCasilla_Ind(i).getCodigo() << endl;
						cout << "***Turno Blancas****" << endl;
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
				if (posX > listapiezas.peones_blancos[i].getPos().x - tolerancia &&
					posX < listapiezas.peones_blancos[i].getPos().x + tolerancia &&
					posY > listapiezas.peones_blancos[i].getPos().y - tolerancia &&
					posY < listapiezas.peones_blancos[i].getPos().y + tolerancia) {
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
				if (posX > listapiezas.torres_blancas[i].getPos().x - tolerancia &&
					posX < listapiezas.torres_blancas[i].getPos().x + tolerancia &&
					posY > listapiezas.torres_blancas[i].getPos().y - tolerancia &&
					posY < listapiezas.torres_blancas[i].getPos().y + tolerancia) {
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
				if (posX > listapiezas.caballos_blancos[i].getPos().x - tolerancia &&
					posX < listapiezas.caballos_blancos[i].getPos().x + tolerancia &&
					posY > listapiezas.caballos_blancos[i].getPos().y - tolerancia &&
					posY < listapiezas.caballos_blancos[i].getPos().y + tolerancia) {
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
				if (posX > listapiezas.alfiles_blancos[i].getPos().x - tolerancia &&
					posX < listapiezas.alfiles_blancos[i].getPos().x + tolerancia &&
					posY > listapiezas.alfiles_blancos[i].getPos().y - tolerancia &&
					posY < listapiezas.alfiles_blancos[i].getPos().y + tolerancia) {
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
			if (posX > listapiezas.rey_blanco.getPos().x - tolerancia &&
				posX < listapiezas.rey_blanco.getPos().x + tolerancia &&
				posY > listapiezas.rey_blanco.getPos().y - tolerancia &&
				posY < listapiezas.rey_blanco.getPos().y + tolerancia) {
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
			if (posX > listapiezas.reina_blanca.getPos().x - tolerancia &&
				posX < listapiezas.reina_blanca.getPos().x + tolerancia &&
				posY > listapiezas.reina_blanca.getPos().y - tolerancia &&
				posY < listapiezas.reina_blanca.getPos().y + tolerancia) {
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
				if (posX > listapiezas.peones_negros[i].getPos().x - tolerancia &&
					posX < listapiezas.peones_negros[i].getPos().x + tolerancia &&
					posY > listapiezas.peones_negros[i].getPos().y - tolerancia &&
					posY < listapiezas.peones_negros[i].getPos().y + tolerancia) {
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
				if (posX > listapiezas.torres_negras[i].getPos().x - tolerancia &&
					posX < listapiezas.torres_negras[i].getPos().x + tolerancia &&
					posY > listapiezas.torres_negras[i].getPos().y - tolerancia &&
					posY < listapiezas.torres_negras[i].getPos().y + tolerancia) {
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
				if (posX > listapiezas.caballos_negros[i].getPos().x - tolerancia &&
					posX < listapiezas.caballos_negros[i].getPos().x + tolerancia &&
					posY > listapiezas.caballos_negros[i].getPos().y - tolerancia &&
					posY < listapiezas.caballos_negros[i].getPos().y + tolerancia) {
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
				if (posX > listapiezas.alfiles_negros[i].getPos().x - tolerancia &&
					posX < listapiezas.alfiles_negros[i].getPos().x + tolerancia &&
					posY > listapiezas.alfiles_negros[i].getPos().y - tolerancia &&
					posY < listapiezas.alfiles_negros[i].getPos().y + tolerancia) {
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
			if (posX > listapiezas.rey_negro.getPos().x - tolerancia &&
				posX < listapiezas.rey_negro.getPos().x + tolerancia &&
				posY > listapiezas.rey_negro.getPos().y - tolerancia &&
				posY < listapiezas.rey_negro.getPos().y + tolerancia) {
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
			if (posX > listapiezas.reina_negra.getPos().x - tolerancia &&
				posX < listapiezas.reina_negra.getPos().x + tolerancia &&
				posY > listapiezas.reina_negra.getPos().y - tolerancia &&
				posY < listapiezas.reina_negra.getPos().y + tolerancia) {
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

//*****************************************************************************************************************************
bool Movimientos::movimiento_peon_blanco() {//****************************************************************************************
	
		if ( (raton.destino.x == raton.origen.x) && ( (raton.destino.y == raton.origen.y + 4 ) ) )
		{
			return true;
		}
		else if ((raton.destino.x == raton.origen.x) && ((raton.destino.y == raton.origen.y + 8)
			&& (raton.origen.y < -8.0f) && (raton.origen.y > -12.0f)))
		{
			//activar la bandera de salto doble en el peón movido y..
			return true;
		}
	return false;
}
bool Movimientos::movimiento_peon_negro() {//****************************************************************************************


		if ((raton.destino.x == raton.origen.x) && ((raton.destino.y == raton.origen.y - 4)))
		{
			return true;
		}
		else if ((raton.destino.x == raton.origen.x) && ((raton.destino.y == raton.origen.y - 8)
			&& (raton.origen.y < 12.0f) && (raton.origen.y > 8.0f)))
		{
			//activar la bandera de salto doble y..
			return true;
		}
	return false;
}

bool Movimientos::movimiento_torre() {
	 
		if ((raton.destino.x == raton.origen.x && raton.destino.y!= raton.origen.y)|| 
			(raton.destino.x != raton.origen.x && raton.destino.y == raton.origen.y)) {
			return true;
		}	
	return false;
}

bool Movimientos::movimiento_alfil()
{
	int n = raton.destino.x - raton.origen.x;
		if (raton.destino.y - raton.origen.y== n) {
			return true;
		}
	return false;
}

bool Movimientos::movimiento_rey()
{
		if (raton.destino.x == raton.origen.x + 4 || raton.destino.y == raton.origen.y + 4 || 
			raton.destino.x == raton.origen.x - 4 || raton.destino.y == raton.origen.y - 4) {
			return true;
		}
	return false;
}

bool Movimientos::movimiento_caballo()
{
	int delta_filas = std::abs((raton.destino.x - raton.origen.x)/4);
	int delta_columnas = std::abs((raton.destino.y - raton.origen.y)/4);

	return ((delta_filas == 1 && delta_columnas == 2) || (delta_filas == 2 && delta_columnas == 1));

}



void Movimientos::jaque()
{
	//caballo
	int delta_filasN = std::abs((pos_reyBlanco.x - pos_caballoN.x) / 4);
	int delta_columnasN = std::abs((pos_reyBlanco.y - pos_caballoN.y) / 4);

	int delta_filasB = std::abs((pos_reyNegro.x - pos_caballoB.x) / 4);
	int delta_columnasB = std::abs((pos_reyNegro.y - pos_caballoB.y) / 4);

	//alfil
	int diffFilaN = std::abs((pos_reyBlanco.x - pos_alfilN.x));
	int diffColumnaN = std::abs((pos_reyBlanco.y - pos_alfilN.y));

	int diffFilaB = std::abs((pos_reyNegro.x - pos_alfilB.x));
	int diffColumnaB = std::abs((pos_reyNegro.y - pos_alfilB.y));

	//Jaque del peon negro al rey blanco
	if ((pos_peonN.x - 4 == pos_reyBlanco.x && pos_peonN.y + 4 == pos_reyBlanco.y) ||
		(pos_peonN.x - 4 == pos_reyBlanco.x && pos_peonN.y - 4 == pos_reyBlanco.y)  )
	{
		cout << "EQUIPO NEGRO: JAQUE " << endl;
	}

	//Jaque del peon blanco al rey negro
	if ((pos_peonB.x + 4 == pos_reyNegro.x && pos_peonB.y + 4 == pos_reyNegro.y) ||
		(pos_peonB.x + 4 == pos_reyNegro.x && pos_peonB.y - 4 == pos_reyNegro.y)  )
	{
		cout << "EQUIPO BLANCO: JAQUE " << endl;
	}

	//Jaque de la torre negra al rey blanco
	if ((pos_torreN.x == pos_reyBlanco.x && pos_torreN.y != pos_reyBlanco.y)||
		(pos_torreN.x != pos_reyBlanco.x && pos_torreN.y == pos_reyBlanco.y))
	{
		cout << "EQUIPO NEGRO: JAQUE " << endl;	
	}

	//Jaque de la torre blanca al rey negro
	if ((pos_torreB.x == pos_reyNegro.x && pos_torreB.y != pos_reyNegro.y) ||
		(pos_torreB.x != pos_reyNegro.x && pos_torreB.y == pos_reyNegro.y))
	{
		cout << "EQUIPO BLANCO: JAQUE " << endl;

	}

	//Jaque del caballo negro al rey blanco
	if ((delta_filasN == 1 && delta_columnasN == 2) || (delta_filasN == 2 && delta_columnasN == 1)) {
		cout << "EQUIPO NEGRO: JAQUE " << endl;
	}

	//Jaque del caballo blanco al rey negro
	if ((delta_filasB == 1 && delta_columnasB == 2) || (delta_filasB == 2 && delta_columnasB == 1)) {
		cout << "EQUIPO BLANCO: JAQUE " << endl;
	}

	/*
	//Jaque del alfil negro al rey blanco
	if (diffFilaN == diffColumnaN )
	{
		cout << "EQUIPO NEGRO: JAQUE MAL " << endl;
	}

	//Jaque del alfil blanco al rey negro
	if (diffFilaB == diffColumnaB)
	{
		cout << "EQUIPO BLANCO: JAQUE MAL " << endl;
	}
	*/


}


bool Movimientos::turnos()
{
	if (t == true) { return false;}
	else { return true;  }
}


bool Movimientos::aux_ExisteCeldaConEnemigo(int i, int indice, float xx, float yy) {
	xx = tablero.getCasilla_Ind(indice).getPos().x;
	yy = tablero.getCasilla_Ind(indice).getPos().y;
	if (tablero.estaDentroTablero(xx, yy) == true)
		if (listapiezas.piezas[indice].getColor() != listapiezas.piezas[i].getColor())
			return true;
}
void Movimientos::aux_DiscriminaAmenaza(int i, int indice) {
	if (listapiezas.piezas[i].getColor() == 1)
		casillas_amenazadas_por_blancas[indice] = true;
	else if (listapiezas.piezas[i].getColor() == 2)
		casillas_amenazadas_por_negras[indice] = true;
}


//******************************************************************************************************************
void Movimientos::piezaAmenaza(int i) {
	for (int j = 0; j < 64; j++) {
		int indice;
		float xx=0, yy=0;
		//cuando la posición de la pieza elegida coincida con la posición de la casilla:
		if ((listapiezas.piezas[i].getPos().x == tablero.getCasilla_Ind(j).getPos().x)
			&& (listapiezas.piezas[i].getPos().y == tablero.getCasilla_Ind(j).getPos().y))
		{
			//peones blancos*************************************************************************************************
			if (i >= 0 && i < 8)
			{

				if (j < 56) {  //solo hasta penúltima línea
					//amenaza sup izq
					indice = j + 7;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
						casillas_amenazadas_por_blancas[indice] = true;

					//amenaza sup der
					indice = j + 9;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
						casillas_amenazadas_por_blancas[indice] = true;
				
					//amenaza lateral a peones que con salto doble se han puesto en cualquier lado
					if (32 <= j <= 39) {
						
							// *****
							//TO-DO
							//******
					}
				}
			}

			//peones negros
			if (i >= 8 && i < 16)
			{
				if (j > 7) { //solo hasta penúltima linea
					
					//amenaza inf izq
					indice = j - 9; 
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
						casillas_amenazadas_por_negras[indice] = true;

					//amenaza inf der
					indice = j - 7;  
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
						casillas_amenazadas_por_negras[indice] = true;

					//amenaza lateral a peones que con salto doble se han puesto en cualquier lado
					if (24 <= j <= 31) {
						// *****
						// TO-DO
						// *****
					}
				}
			}

			//torres
			if (i >= 16 && i < 20) {
				//hacia la derecha
				for (int xder = 1; xder < 8; xder++) {
					indice = j + 1 * xder;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
						aux_DiscriminaAmenaza(i, indice);
				}
				//hacia la izquierda
				for (int xizq = 1; xizq < 8; xizq++) {
					indice = j - 1 * xizq;
					if ( aux_ExisteCeldaConEnemigo(i, indice, xx, yy) )
						aux_DiscriminaAmenaza(i, indice);
				}
				//hacia arriba
				for (int y_arr = 1; y_arr < 8; y_arr++) {
					indice = j +8 * y_arr;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
						aux_DiscriminaAmenaza(i, indice);
					
				}
				//hacia abajo
				for (int y_aba = 1; y_aba < 8; y_aba++) {
					indice = j - 8 * y_aba;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy)) 
						aux_DiscriminaAmenaza(i, indice);
				
				}
			}
			
			//caballos
			if (i >= 20 && i < 24) {
				indice = j + 6;		//Salto a la posición de las ~10:00
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy)) 
					aux_DiscriminaAmenaza(i, indice);
				indice = j + 15;	//Salto a la posición de las ~11:00
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);
				indice = j + 17;	//Salto a la posición de la ~01:00
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);
				indice = j + 10;	//Salto a la posición de las ~02:00
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);
				indice = j - 6;		//Salto a la posición de las ~04:00
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);
				indice = j - 15;	//Salto a la posición de las ~05:00
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);
				indice = j - 17;	//Salto a la posición de las ~07:00
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);
				indice = j - 10;	//Salto a la posición de las ~08:00
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);

			}

			//alfiles
			if (i >= 24 && i < 28) {
				//hacia nor-este
				for (int NE = 1; NE < 8; NE++) {
					indice = j + 18 * NE;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy)) {
						aux_DiscriminaAmenaza(i, indice);
					}
				}
				//hacia nor-oeste
				for (int NO = 1; NO < 8; NO++) {
					indice = j + 18 * NO;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy)) {
						aux_DiscriminaAmenaza(i, indice);
					}
				}
				//hacia sur-este
				for (int SE = 1; SE < 8; SE++) {
					indice = j + 18 * SE;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy)) {
						aux_DiscriminaAmenaza(i, indice);
					}
				}
				//hacia sur-oeste
				for (int SO = 1; SO < 8; SO++) {
					indice = j + 18 * SO;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy)) {
						aux_DiscriminaAmenaza(i, indice);
					}
				}
			}

			//reyes
			if (i >= 28 && i < 30) {
				//amenaza sup izq
				indice = j + 7;
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);

				//amenaza sup der
				indice = j + 9;
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);

				//amenaza inf izq
				indice = j - 9;
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);

				//amenaza inf der
				indice = j - 7;
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);
				
				//amenaza derecha
				indice = j + 1;
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);

				//amenaza izquierda
				indice = j - 1;
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);

				//amenaza arriba
				indice = j + 8;
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);

				//amenaza abajo
				indice = j - 8;
				if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
					aux_DiscriminaAmenaza(i, indice);
			}

			//reinas
			if (i >= 30 && i < 32) {

				//amenaza sup izq
				for (int NO = 1; NO < 8; NO++) {
					indice = j + 7 * NO;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
						aux_DiscriminaAmenaza(i, indice);
				}

				//amenaza sup der
				for (int NE = 1; NE < 8; NE++) {
					indice = j + 9 * NE;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
						aux_DiscriminaAmenaza(i, indice);
				}

				//amenaza inf izq
				for (int SO = 1; SO < 8; SO++) {
					indice = j - 9 * SO;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
						aux_DiscriminaAmenaza(i, indice);
				}
				
				//amenaza inf der
				for (int SE = 1; SE < 8; SE++) {
					indice = j - 7 * SE;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
						aux_DiscriminaAmenaza(i, indice);
				}

				//amenaza derecha
				for (int EE = 1; EE < 8; EE++) {
					indice = j + 1 * EE;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
						aux_DiscriminaAmenaza(i, indice);
				}

				//amenaza izquierda
				for (int OO = 1; OO < 8; OO++) {
					indice = j - 1 * OO;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
						aux_DiscriminaAmenaza(i, indice);
				}

				//amenaza arriba
				for (int NN = 1; NN < 8; NN++) {
					indice = j + 8 * NN;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
						aux_DiscriminaAmenaza(i, indice);
				}
				//amenaza abajo
				for (int SS = 1; SS < 8; SS++) {
					indice = j - 8 * SS;
					if (aux_ExisteCeldaConEnemigo(i, indice, xx, yy))
						aux_DiscriminaAmenaza(i, indice);
				}
			
			}	

		}

	}
}
bool Movimientos::celdaAmenazada(int i){

	//en el turno de las blancas, nos interesa saber las celdas amenazadas por las negras
	if (t)
		if (casillas_amenazadas_por_negras) {
			cout << "La Casilla " << tablero.getCasilla_Ind(i).getCodigo() << " está siendo amenazada " << endl;
			return true;
		}
		else return false;
	//en el turno de las negras, nos interesa saber las celdas amenazadas por las blancas
	else if (t == 0)
		if (casillas_amenazadas_por_blancas) {
			cout << "La Casilla " << tablero.getCasilla_Ind(i).getCodigo() << " está siendo amenazada " << endl;
			return true;
		}
		else return false;
}

////float  PosX, PosY; //coordenadas de la celda que va a evaluar las casillas que se amenazan desde ahí
	//for (int i = 0; i < 8; i++) {  //peones blancos
	//	
	//}
	//for (int i = 8; i < 16; i++) {  //peones negros


	//}
	//for (int i = 16; i < 20; i++) {  //torres 


	//}
	//for (int i = 20; i < 24; i++) {  //caballos 
	//
	//}
	//for (int i = 24; i < 28; i++) {  //alfiles

	//}

	//for (int i = 28; i < 30; i++) {  //reyes

	//}
	//for (int i = 30; i < 32; i++) {  //reinas

	//}
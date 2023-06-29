#include "Movimientos.h"

//void Movimientos::set_casillaOcupada() {
//	casilla_ocupada = false;
//}
//void Movimientos::reset_casillaOcupada() {
//	casilla_ocupada = true;
//}

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
			listapiezas.reinicia();
			fin_de_partida = false;
			t = false;
			opcion[0] = true;
			opcion[1] = false;
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/sonidos/flores.mp3", true);
			

		}

		//seleccionar opcion 2
		if (posX >= 16.8984 + 5 && posX <= 24.1805 + 5 && posY <= 21.5664 && posY >= 14.5947) {
			cout << "Opcion 2" << endl;
			listapiezas.reinicia();
			fin_de_partida = false;
			t = false;
			opcion[0] = false;
			opcion[1] = true;
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/sonidos/normal.mp3", true);

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
					bool casilla_blanca_ocupada = false;
					bool casilla_negra_ocupada = false;
					for (int j = 0; j < 16; j++) {
						if (raton.pieza_seleccionada != j &&
							raton.destino.x == listapiezas.piezas[j].getPos().x &&
							raton.destino.y == listapiezas.piezas[j].getPos().y && turnos()) {
							//set_casillaOcupada();
							casilla_blanca_ocupada = true;
							raton.origen = { tablero.getPos_Casilla(i).x, tablero.getPos_Casilla(i).y };
							//cout << "Origen:" << raton.origen.x << "," << raton.origen.y << endl;
							break;
						}

					}
					for (int j = 16; j < 32; j++) {
						if (raton.pieza_seleccionada != j &&
							raton.destino.x == listapiezas.piezas[j].getPos().x &&
							raton.destino.y == listapiezas.piezas[j].getPos().y && !turnos()) {
							//set_casillaOcupada();
							casilla_negra_ocupada = true;
							raton.origen = { tablero.getPos_Casilla(i).x, tablero.getPos_Casilla(i).y };
							//cout << "Origen:" << raton.origen.x << "," << raton.origen.y << endl;
							break;
						}

					}
					for (int j = 32; j < 40; j++) {
						if (raton.pieza_seleccionada != j &&
							raton.destino.x == listapiezas.piezas[j].getPos().x &&
							raton.destino.y == listapiezas.piezas[j].getPos().y) {
							//set_casillaOcupada();
							casilla_blanca_ocupada = true;
							raton.origen = { tablero.getPos_Casilla(i).x, tablero.getPos_Casilla(i).y };
							//cout << "Origen:" << raton.origen.x << "," << raton.origen.y << endl;
							break;
						}

					}
					for (int j = 40; j < 48; j++) {
						if (raton.pieza_seleccionada != j &&
							raton.destino.x == listapiezas.piezas[j].getPos().x &&
							raton.destino.y == listapiezas.piezas[j].getPos().y) {
							//set_casillaOcupada();
							casilla_blanca_ocupada = true;
							raton.origen = { tablero.getPos_Casilla(i).x, tablero.getPos_Casilla(i).y };
							//cout << "Origen:" << raton.origen.x << "," << raton.origen.y << endl;
							break;
						}

					}
					//// Verificar si la casilla seleccionada está ocupada por otra pieza
					//bool casilla_ocupada = false;
					//for (int j = 0; j < 32; j++) {
					//	if (raton.pieza_seleccionada != j &&
					//		raton.destino.x == listapiezas.piezas[j].getPos().x &&
					//		raton.destino.y == listapiezas.piezas[j].getPos().y) {
					//		//set_casillaOcupada();
					//		casilla_ocupada = true;
					//		raton.origen= { tablero.getPos_Casilla(i).x, tablero.getPos_Casilla(i).y };
					//		//cout << "Origen:" << raton.origen.x << "," << raton.origen.y << endl;
					//		break;
					//	}
					//	
					//}


					//PIEZAS BLANCAS//


					Casilla casilla_destino = tablero.getCasilla_Pos(raton.destino.x, raton.destino.y);
					int casilla_ind = tablero.getIndexCasilla(casilla_destino);

					// Realizar el movimiento del peón si la casilla no está ocupada
					if (!casilla_blanca_ocupada && raton.peon_blanco_seleccionado != -1 && movimiento_peon_blanco()) {
						//if (!casilla_ocupada && raton.peon_blanco_seleccionado != -1 && movimiento_peon_blanco()&& turnos()) {
						pos_peonB = { raton.destino };
						jaque();
						t = true;
						sonido();
						ResetDobles();
						listapiezas.peones_blancos[raton.peon_blanco_seleccionado].setPos(raton.destino.x, raton.destino.y);
						comer();
						promocionAReina();
						cout << "Movimiento realizado: Peón blanco " << raton.peon_blanco_seleccionado << " a la casilla " << (tablero.getCasilla_Ind(i)).getCodigo() << endl;
						cout << "****Turno Negras****" << endl;
					}

					// Realizar el movimiento de la torre si la casilla no está ocupada
					if (!casilla_blanca_ocupada && raton.torre_blanca_seleccionada != -1 && movimiento_torre()) {
						//if (!casilla_ocupada && raton.torre_blanca_seleccionada != -1 && movimiento_torre()&& turnos()) {
						pos_torreB = { raton.destino };
						jaque();
						t = true;
						sonido();
						ResetDobles();
						listapiezas.torres_blancas[raton.torre_blanca_seleccionada].setPos(raton.destino.x, raton.destino.y);
						comer();
						cout << "Movimiento realizado: Torre blanca " << raton.torre_blanca_seleccionada << " a la casilla " << (tablero.getCasilla_Ind(i)).getCodigo() << endl;
						cout << "****Turno Negras****" << endl;

					}

					// Realizar el movimiento del caballo blanco si la casilla no está ocupada
					if (!casilla_blanca_ocupada && raton.caballo_blanco_seleccionado != -1 && movimiento_caballo()) {
						//if (!casilla_ocupada && raton.caballo_blanco_seleccionado != -1 && movimiento_caballo() && turnos()) {
						pos_caballoB = { raton.destino };
						jaque();
						t = true;
						sonido();
						ResetDobles();
						listapiezas.caballos_blancos[raton.caballo_blanco_seleccionado].setPos(raton.destino.x, raton.destino.y);
						comer();
						cout << "Movimiento realizado: Caballo blanco " << raton.caballo_blanco_seleccionado << " a la casilla " << (tablero.getCasilla_Ind(i)).getCodigo() << endl;
						cout << "****Turno Negras****" << endl;
					}

					// Realizar el movimiento del alfil blanco si la casilla no está ocupada
					if (!casilla_blanca_ocupada && raton.alfil_blanco_seleccionado != -1 && movimiento_alfil()) {
						//if (!casilla_ocupada && raton.alfil_blanco_seleccionado != -1 && movimiento_alfil() && turnos()) {
						pos_alfilB = { raton.destino };
						jaque();
						sonido();
						t = true;
						ResetDobles();
						listapiezas.alfiles_blancos[raton.alfil_blanco_seleccionado].setPos(raton.destino.x, raton.destino.y);
						comer();
						cout << "Movimiento realizado: Alfil blanco " << raton.alfil_blanco_seleccionado << " a la casilla " << (tablero.getCasilla_Ind(i)).getCodigo() << endl;
						cout << "****Turno Negras****" << endl;
					}

					// Realizar el movimiento del rey blanco si la casilla no está ocupada
					if (!casilla_blanca_ocupada && raton.rey_blanco_seleccionado != -1 && movimiento_rey() && !checkCasillaAmenazada(casilla_ind)) {
						//if (!casilla_ocupada && raton.rey_blanco_seleccionado != -1 && movimiento_rey() && turnos()) {
						pos_reyBlanco = { raton.destino };
						t = true;
						sonido();
						ResetDobles();
						
						

						if (quiero_enrocar) {
							if (enroqueCortoPosible(14) && (raton.destino.x - raton.origen.x) == 8) {
								enroqueCorto(14);
							}
							if (enroqueLargoPosible(14) && (raton.destino.x - raton.origen.x) == -8) {
								enroqueLargo(14);
							}
							quiero_enrocar = false;
						}
						else if (!quiero_enrocar)
							listapiezas.rey_blanco.setPos(raton.destino.x, raton.destino.y);

						listapiezas.rey_blanco.setPos(raton.destino.x, raton.destino.y);
						comer();
						cout << "Movimiento realizado: Rey blanco a la casilla " << (tablero.getCasilla_Ind(i)).getCodigo() << endl;
						cout << "****Turno Negras****" << endl;
					}

					// Realizar el movimiento de la reina blanca si la casilla no está ocupada
					if (!casilla_blanca_ocupada && raton.reina_blanca_seleccionada != -1 && (movimiento_alfil() || movimiento_torre())) {
						//if (!casilla_ocupada && raton.reina_blanca_seleccionada != -1 && (movimiento_alfil() || movimiento_torre()) && turnos()) {
						t = true;
						ResetDobles();
						sonido();
						listapiezas.reina_blanca[raton.reina_blanca_seleccionada].setPos(raton.destino.x, raton.destino.y);
						comer();
						cout << "Movimiento realizado: Reina blanca a la casilla " << (tablero.getCasilla_Ind(i)).getCodigo() << endl;
						cout << "****Turno Negras****" << endl;
					}

					//PIEZAS NEGRAS//

					// Realizar el movimiento del peón negro si la casilla no está ocupada
					if (!casilla_negra_ocupada && raton.peon_negro_seleccionado != -1 && movimiento_peon_negro()) {
						//if (!casilla_ocupada && raton.peon_negro_seleccionado != -1 && movimiento_peon_negro() && !turnos()) {
						pos_peonN = { raton.destino };
						jaque();
						t = false;
						ResetDobles();
						listapiezas.peones_negros[raton.peon_negro_seleccionado].setPos(raton.destino.x, raton.destino.y);
						comer();
						sonido();
						promocionAReina();
						cout << "Movimiento realizado: Peón negro " << raton.peon_negro_seleccionado << " a la casilla " << tablero.getCasilla_Ind(i).getCodigo() << endl;
						cout << "***Turno Blancas****" << endl;
					}

					// Realizar el movimiento de la torre negra si la casilla no está ocupada
					if (!casilla_negra_ocupada && raton.torre_negra_seleccionada != -1 && movimiento_torre()) {
						//if (!casilla_ocupada && raton.torre_negra_seleccionada != -1 && movimiento_torre()&&!turnos()) {
						pos_torreN = { raton.destino };
						jaque();
						t = false;
						sonido();
						ResetDobles();
						listapiezas.torres_negras[raton.torre_negra_seleccionada].setPos(raton.destino.x, raton.destino.y);
						comer();
						cout << "Movimiento realizado: Torre negra " << raton.torre_negra_seleccionada << " a la casilla " << tablero.getCasilla_Ind(i).getCodigo() << endl;
						cout << "***Turno Blancas****" << endl;
					}

					// Realizar el movimiento del caballo negro si la casilla no está ocupada
					if (!casilla_negra_ocupada && raton.caballo_negro_seleccionado != -1 && movimiento_caballo()) {
						//if (!casilla_ocupada && raton.caballo_negro_seleccionado != -1 && movimiento_caballo()&&!turnos()) {
						pos_caballoN = { raton.destino };
						jaque();
						t = false;
						sonido();
						ResetDobles();
						listapiezas.caballos_negros[raton.caballo_negro_seleccionado].setPos(raton.destino.x, raton.destino.y);
						comer();
						cout << "Movimiento realizado: Caballo negro " << raton.caballo_negro_seleccionado << " a la casilla " << tablero.getCasilla_Ind(i).getCodigo() << endl;
						cout << "***Turno Blancas****" << endl;
					}

					// Realizar el movimiento del alfil negro si la casilla no está ocupada
					if (!casilla_negra_ocupada && raton.alfil_negro_seleccionado != -1 && movimiento_alfil()) {
						//if (!casilla_ocupada && raton.alfil_negro_seleccionado != -1 && movimiento_alfil()&&!turnos()) {
						pos_alfilN = { raton.destino };
						jaque();
						sonido();
						t = false;
						ResetDobles();
						listapiezas.alfiles_negros[raton.alfil_negro_seleccionado].setPos(raton.destino.x, raton.destino.y);
						comer();
						cout << "Movimiento realizado: Alfil negro " << raton.alfil_negro_seleccionado << " a la casilla " << tablero.getCasilla_Ind(i).getCodigo() << endl;
						cout << "***Turno Blancas****" << endl;
					}

					// Realizar el movimiento del rey negro si la casilla no está ocupada
					if (!casilla_negra_ocupada && raton.rey_negro_seleccionado != -1 && movimiento_rey() && !checkCasillaAmenazada(casilla_ind)) {
						//if (!casilla_ocupada && raton.rey_negro_seleccionado != -1 && movimiento_rey() && !turnos()) {
						pos_reyNegro = { raton.destino };
						t = false;
						ResetDobles();
						sonido();

						if (quiero_enrocar) {
							if (enroqueCortoPosible(30) && (raton.destino.x - raton.origen.x) == 8) {
								enroqueCorto(30);
							}
							if (enroqueLargoPosible(30) && (raton.destino.x - raton.origen.x) == -8) {
								enroqueLargo(30);
							}
							quiero_enrocar = false;
						}
						else if (!quiero_enrocar)
							listapiezas.rey_negro.setPos(raton.destino.x, raton.destino.y);

						comer();
						cout << "Movimiento realizado: Rey negro a la casilla " << tablero.getCasilla_Ind(i).getCodigo() << endl;
						cout << "***Turno Blancas****" << endl;
					}

					// Realizar el movimiento de la reina negra si la casilla no está ocupada
					if (!casilla_negra_ocupada && raton.reina_negra_seleccionada != -1 && (movimiento_alfil() || movimiento_torre())) {
						//if (!casilla_ocupada && raton.reina_negra_seleccionada != -1 && ( movimiento_alfil()|| movimiento_torre() ) && !turnos()) {
						t = false;
						ResetDobles();
						sonido();
						listapiezas.reina_negra[raton.reina_negra_seleccionada].setPos(raton.destino.x, raton.destino.y);
						comer();
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
					posY < listapiezas.peones_blancos[i].getPos().y + tolerancia && turnos()) {
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
					posY < listapiezas.torres_blancas[i].getPos().y + tolerancia && turnos()) {
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
					posY < listapiezas.caballos_blancos[i].getPos().y + tolerancia && turnos()) {
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
					posY < listapiezas.alfiles_blancos[i].getPos().y + tolerancia && turnos()) {
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
				posY < listapiezas.rey_blanco.getPos().y + tolerancia && turnos()) {
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

			// Solo hay una reina blanca!!!!!!!!!! NO!! Puedeb haber hasta 9 , aunque normalmente no se conseguirán más de 2 - 3
			for (int i = 0; i < 9; i++) {
				if (posX > listapiezas.reina_blanca[i].getPos().x - tolerancia &&
					posX < listapiezas.reina_blanca[i].getPos().x + tolerancia &&
					posY > listapiezas.reina_blanca[i].getPos().y - tolerancia &&
					posY < listapiezas.reina_blanca[i].getPos().y + tolerancia && turnos()) {
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
					posY < listapiezas.peones_negros[i].getPos().y + tolerancia && !turnos()) {
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
					posY < listapiezas.torres_negras[i].getPos().y + tolerancia && !turnos()) {
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
					posY < listapiezas.caballos_negros[i].getPos().y + tolerancia && !turnos()) {
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
					posY < listapiezas.alfiles_negros[i].getPos().y + tolerancia && !turnos()) {
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
				posY < listapiezas.rey_negro.getPos().y + tolerancia && !turnos()) {
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

			// Solo hay una reina negra? FALSO, Pueden haber hasta 8 adicionales
			for (int i = 0; i < 9; i++) {
				if (posX > listapiezas.reina_negra[i].getPos().x - tolerancia &&
					posX < listapiezas.reina_negra[i].getPos().x + tolerancia &&
					posY > listapiezas.reina_negra[i].getPos().y - tolerancia &&
					posY < listapiezas.reina_negra[i].getPos().y + tolerancia && !turnos()) {
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


bool Movimientos::movimiento_peon_blanco() {
	// Verificar movimiento hacia adelante sin captura
	if (raton.destino.x == raton.origen.x && raton.destino.y == raton.origen.y + 4) {
		// Verificar si hay alguna pieza en la casilla de destino
		for (int i = 0; i < 48; i++) {
			if (listapiezas.piezas[i].getPos().x == raton.destino.x &&
				listapiezas.piezas[i].getPos().y == raton.destino.y) {
				// Hay una pieza en la casilla de destino, movimiento no válido
				return false;
			}
		}

		return true;
	}

	// Verificar movimiento hacia adelante
	if (raton.destino.x == raton.origen.x && raton.destino.y == raton.origen.y + 4) {
		return true;
	}

	// Resto de las comprobaciones de movimiento
	if ((raton.destino.x == raton.origen.x) && ((raton.destino.y == raton.origen.y + 8)
		&& (raton.origen.y < -8.0f) && (raton.origen.y > -12.0f))) {
		// Activar la bandera de salto doble en el peón movido y..
		for (int i = 0; i < 8; i++) {
			if (listapiezas.piezas[i].getPos().x == tablero.getCasilla_Pos(raton.destino.x, raton.destino.y).getPos().x
				&& listapiezas.piezas[i].getPos().y == tablero.getCasilla_Pos(raton.destino.x, raton.destino.y).getPos().y)
				listapiezas.piezas[i].setDoble();
		}
		return true;
	}

	for (int i = 0; i < 48; i++) {
		for (int j = 0; j < 8; j++) {
			if ((listapiezas.piezas[i].getPos().x == raton.origen.x + 4 &&
				listapiezas.piezas[i].getPos().y == raton.origen.y + 4) ||
				(listapiezas.piezas[i].getPos().x == raton.origen.x - 4 &&
					listapiezas.piezas[i].getPos().y == raton.origen.y + 4)) {
				return true;

			}
		}
	}

	return false;
}



bool Movimientos::movimiento_peon_negro() {
	// Verificar movimiento hacia adelante sin captura
	if (raton.destino.x == raton.origen.x && raton.destino.y == raton.origen.y - 4) {
		// Verificar si hay alguna pieza en la casilla de destino
		for (int i = 0; i < 48; i++) {
			if (listapiezas.piezas[i].getPos().x == raton.destino.x &&
				listapiezas.piezas[i].getPos().y == raton.destino.y) {
				// Hay una pieza en la casilla de destino, movimiento no válido
				return false;
			}
		}

		return true;
	}

	// Verificar movimiento hacia adelante
	if (raton.destino.x == raton.origen.x && raton.destino.y == raton.origen.y - 4) {
		return true;
	}

	// Resto de las comprobaciones de movimiento
	if ((raton.destino.x == raton.origen.x) && ((raton.destino.y == raton.origen.y - 8)
		&& (raton.origen.y < 12.0f) && (raton.origen.y > 8.0f))) {
		// Activar la bandera de salto doble en el peón movido y..
		for (int i = 8; i < 16; i++) {
			if (listapiezas.piezas[i].getPos().x == tablero.getCasilla_Pos(raton.destino.x, raton.destino.y).getPos().x
				&& listapiezas.piezas[i].getPos().y == tablero.getCasilla_Pos(raton.destino.x, raton.destino.y).getPos().y)
				listapiezas.piezas[i].setDoble();
		}
		return true;
	}

	for (int i = 0; i < 48; i++) {
		if ((raton.origen.x + 4 == listapiezas.piezas[i].getPos().x &&
			raton.origen.y - 4 == listapiezas.piezas[i].getPos().y) ||
			(raton.origen.x - 4 == listapiezas.piezas[i].getPos().x &&
				raton.origen.y - 4 == listapiezas.piezas[i].getPos().y)) {
			return true;
		}
	}

	return false;
}


bool Movimientos::movimiento_torre() {
	// Verificar si hay obstáculos en la trayectoria horizontal
	if (raton.destino.x == raton.origen.x && raton.destino.y != raton.origen.y) {
		int deltaY = (raton.destino.y > raton.origen.y) ? 1 : -1;
		int y = raton.origen.y + deltaY;

		while (y != raton.destino.y) {
			for (int i = 0; i < 48; i++) {
				if (listapiezas.piezas[i].getPos().x == raton.origen.x &&
					listapiezas.piezas[i].getPos().y == y) {
					// Hay un obstáculo en la trayectoria, movimiento no válido
					return false;
				}
			}
			y += deltaY;
		}

		return true;
	}

	// Verificar si hay obstáculos en la trayectoria vertical
	if (raton.destino.x != raton.origen.x && raton.destino.y == raton.origen.y) {
		int deltaX = (raton.destino.x > raton.origen.x) ? 1 : -1;
		int x = raton.origen.x + deltaX;

		while (x != raton.destino.x) {
			for (int i = 0; i < 48; i++) {
				if (listapiezas.piezas[i].getPos().x == x &&
					listapiezas.piezas[i].getPos().y == raton.origen.y) {
					// Hay un obstáculo en la trayectoria, movimiento no válido
					return false;
				}
			}
			x += deltaX;
		}

		return true;
	}

	return false;
}


bool Movimientos::movimiento_alfil()
{
	int deltaX = raton.destino.x - raton.origen.x;
	int deltaY = raton.destino.y - raton.origen.y;

	// Verificar si el movimiento es en diagonal
	if (abs(deltaX) == abs(deltaY)) {
		int stepX = (deltaX > 0) ? 1 : -1;
		int stepY = (deltaY > 0) ? 1 : -1;

		int x = raton.origen.x + stepX;
		int y = raton.origen.y + stepY;

		while (x != raton.destino.x) {
			for (int i = 0; i < 48; i++) {
				if (listapiezas.piezas[i].getPos().x == x &&
					listapiezas.piezas[i].getPos().y == y) {
					// Hay un obstáculo en la trayectoria, movimiento no válido
					return false;
				}
			}
			x += stepX;
			y += stepY;
		}

		return true;
	}

	return false;
}


bool Movimientos::movimiento_rey()
{
	int diferencia_x = abs(raton.destino.x - raton.origen.x);
	int diferencia_y = abs(raton.destino.y - raton.origen.y);

	if ((diferencia_x == 4 && diferencia_y == 0) ||
		(diferencia_x == 0 && diferencia_y == 4) ||
		(diferencia_x == 4 && diferencia_y == 4)) {
		return true;
	}
	//Implementación del Enroque
	if (((raton.destino.x - raton.origen.x) == 8 && diferencia_y == 0))//solo aplicable en la primera y última fila
	{
		quiero_enrocar = true;
		return true;
	}


	return false;
}

bool Movimientos::movimiento_caballo()
{
	int delta_filas = std::abs((raton.destino.x - raton.origen.x) / 4);
	int delta_columnas = std::abs((raton.destino.y - raton.origen.y) / 4);

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
		(pos_peonN.x - 4 == pos_reyBlanco.x && pos_peonN.y - 4 == pos_reyBlanco.y))
	{
		cout << "EQUIPO NEGRO: JAQUE " << endl;
	}

	//Jaque del peon blanco al rey negro
	if ((pos_peonB.x + 4 == pos_reyNegro.x && pos_peonB.y + 4 == pos_reyNegro.y) ||
		(pos_peonB.x + 4 == pos_reyNegro.x && pos_peonB.y - 4 == pos_reyNegro.y))
	{
		cout << "EQUIPO BLANCO: JAQUE " << endl;
	}

	//Jaque de la torre negra al rey blanco
	if ((pos_torreN.x == pos_reyBlanco.x && pos_torreN.y != pos_reyBlanco.y) ||
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

	
	//Jaque del alfil negro al rey blanco
	/*if (diffFilaN == diffColumnaN )
	{
		cout << "EQUIPO NEGRO: JAQUE MAL " << endl;
	}*/
	/*piezaAmenazaACasillas(28);
	piezaAmenazaACasillas(29);*/

	//Jaque del alfil blanco al rey negro
	/*if (diffFilaB == diffColumnaB)
	{
		cout << "EQUIPO BLANCO: JAQUE MAL " << endl;
	}*/
	/*piezaAmenazaACasillas(12);
	piezaAmenazaACasillas(13);*/


}


bool Movimientos::turnos()
{
	if (!fin_de_partida)
	{
		if (t == true) { return false; }  //turno() == false -> turno de negras
		else { return true; }  //turno() == true  -> turno de blancas
	}
	
}


bool Movimientos::aux_ExisteCeldaSinAliado(int i, int indice, float xx, float yy) {
	xx = tablero.getCasilla_Ind(indice).getPos().x;
	yy = tablero.getCasilla_Ind(indice).getPos().y;
	if (tablero.estaDentroTablero(xx, yy) == true)
		if (listapiezas.piezas[indice].getColor() != listapiezas.piezas[i].getColor())  //Si el color es de oponente o no hay color...
			return true;
}
void Movimientos::aux_DiscriminaQuienAmenaza(int i, int indice) {
	if (listapiezas.piezas[i].getColor() == 1)
		casillas_amenazadas_por_blancas[indice] = true;
	else if (listapiezas.piezas[i].getColor() == 2)
		casillas_amenazadas_por_negras[indice] = true;
}


//******************************************************************************************************************


void Movimientos::piezaAmenazaACasillas(int i) {
	for (int j = 0; j < 64; j++) {  //Se recorren todas las casillas del tablero
		int indice;
		float xx = 0, yy = 0;
		//cuando la posición de la pieza elegida coincida con la posición de la casilla, se ubica  en el tablero la pieza que queremos estudiar...
		if ((listapiezas.piezas[i].getPos().x == tablero.getCasilla_Ind(j).getPos().x)
			&& (listapiezas.piezas[i].getPos().y == tablero.getCasilla_Ind(j).getPos().y)
			&& listapiezas.piezas[i].checkViviente()) {
			// se procede, en función de qué pieza sea, a activar como amenazadas las casillas de influencia


				//peones blancos
			if (i >= 0 && i < 8)
			{

				if (j < 56) {  //solo hasta penúltima línea
					//amenaza sup izq
					indice = j + 7;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
						casillas_amenazadas_por_blancas[indice] = true;

					//amenaza sup der
					indice = j + 9;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
						casillas_amenazadas_por_blancas[indice] = true;

					//amenaza lateral a peones que con salto doble se han puesto en cualquiera de sus laterales
					if (32 <= j <= 39) {
						for (int pB = 16; pB < 24; pB++) {//indice del peón oponente

							//amenaza a peón izquierdo
							indice = j - 1;

							if (aux_ExisteCeldaSinAliado(i, indice, xx, yy) && (listapiezas.piezas[pB].getDoble()) &&
								(listapiezas.piezas[pB].getPos().x == tablero.getCasilla_Ind(indice).getPos().x) &&
								(listapiezas.piezas[pB].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								casillas_amenazadas_por_blancas[indice] = true;

							//amenaza a peón derecho
							indice = j + 1;

							if (aux_ExisteCeldaSinAliado(i, indice, xx, yy) && (listapiezas.piezas[pB].getDoble()) &&
								(listapiezas.piezas[pB].getPos().x == tablero.getCasilla_Ind(indice).getPos().x) &&
								(listapiezas.piezas[pB].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								casillas_amenazadas_por_blancas[indice] = true;

						}

					}
				}
			}

			//peones negros
			if (i >= 16 && i < 24)
			{
				if (j > 7) { //solo hasta penúltima linea

					//amenaza inf izq
					indice = j - 9;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
						casillas_amenazadas_por_negras[indice] = true;

					//amenaza inf der
					indice = j - 7;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
						casillas_amenazadas_por_negras[indice] = true;

					////amenaza lateral a peones que con salto doble se han puesto en cualquiera de sus laterales
					if (24 <= j <= 31) {

						for (int pN = 0; pN < 8; pN++) {//indice del peón oponente (blanco)

							//amenaza a peón izquierdo
							indice = j - 1;

							if (aux_ExisteCeldaSinAliado(i, indice, xx, yy) && (listapiezas.piezas[pN].getDoble()) &&
								(listapiezas.piezas[pN].getPos().x == tablero.getCasilla_Ind(indice).getPos().x) &&
								(listapiezas.piezas[pN].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								casillas_amenazadas_por_blancas[indice] = true;

							//amenaza a peón derecho
							indice = j + 1;

							if (aux_ExisteCeldaSinAliado(i, indice, xx, yy) && (listapiezas.piezas[pN].getDoble()) &&
								(listapiezas.piezas[pN].getPos().x == tablero.getCasilla_Ind(indice).getPos().x) &&
								(listapiezas.piezas[pN].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								casillas_amenazadas_por_blancas[indice] = true;

						}
					}
				}
			}

			//torres
			if (i == 8 || i == 9 || i == 24 || i == 25) {
				//hacia la derecha
				for (int xder = 1; xder < 8; xder++) {
					indice = j + 1 * xder;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}
				//hacia la izquierda
				for (int xizq = 1; xizq < 8; xizq++) {
					indice = j - 1 * xizq;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}
				//hacia arriba
				for (int y_arr = 1; y_arr < 8; y_arr++) {
					indice = j + 8 * y_arr;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}
				//hacia abajo
				for (int y_aba = 1; y_aba < 8; y_aba++) {
					indice = j - 8 * y_aba;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}
			}

			//caballos
			if (i == 10 || i == 11 || i == 26 || i == 27) {
				indice = j + 6;		//Salto a la posición de las ~10:00
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);
				indice = j + 15;	//Salto a la posición de las ~11:00
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);
				indice = j + 17;	//Salto a la posición de la ~01:00
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);
				indice = j + 10;	//Salto a la posición de las ~02:00
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);
				indice = j - 6;		//Salto a la posición de las ~04:00
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);
				indice = j - 15;	//Salto a la posición de las ~05:00
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);
				indice = j - 17;	//Salto a la posición de las ~07:00
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);
				indice = j - 10;	//Salto a la posición de las ~08:00
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);

			}

			//alfiles
			if (i == 12 || i == 13 || i == 28 || i == 29) {
				//hacia nor-este
				for (int NE = 1; NE < 8; NE++) {
					indice = j + 18 * NE;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}
				//hacia nor-oeste
				for (int NO = 1; NO < 8; NO++) {
					indice = j + 18 * NO;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
							//*************************************************************************************************************************************************************************************
							//if (listapiezas.getIndexPieza(listapiezas.piezas[obj]) == listapiezas.getIndexPieza(listapiezas.piezas[14]) 
							//	&&  ( (listapiezas.getIndexPieza(listapiezas.piezas[28])==28) || (listapiezas.getIndexPieza(listapiezas.piezas[29]) == 29) ) )
							//	cout << "EQUIPO Negro: JAQUE MAL " << endl;
							//if (listapiezas.getIndexPieza(listapiezas.piezas[obj]) == listapiezas.getIndexPieza(listapiezas.piezas[30])
							//	&& ((listapiezas.getIndexPieza(listapiezas.piezas[12]) == 12) || (listapiezas.getIndexPieza(listapiezas.piezas[13]) == 13)))
							//	cout << "EQUIPO Negro: JAQUE MAL " << endl;
							//*************************************************************************************************************************************************************************************
						}
					}
					if (salto) break;
				}
				//hacia sur-este
				for (int SE = 1; SE < 8; SE++) {
					indice = j + 18 * SE;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}
				//hacia sur-oeste
				for (int SO = 1; SO < 8; SO++) {
					indice = j + 18 * SO;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}
			}

			//reyes
			if (i == 14 || i == 30) {
				//amenaza sup izq
				indice = j + 7;
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);

				//amenaza sup der
				indice = j + 9;
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);

				//amenaza inf izq
				indice = j - 9;
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);

				//amenaza inf der
				indice = j - 7;
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);

				//amenaza derecha
				indice = j + 1;
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);

				//amenaza izquierda
				indice = j - 1;
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);

				//amenaza arriba
				indice = j + 8;
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);

				//amenaza abajo
				indice = j - 8;
				if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					aux_DiscriminaQuienAmenaza(i, indice);
			}

			//reinas
			if ((i == 15) || (i >= 31 && i < 47)) {

				//amenaza sup izq
				for (int NO = 1; NO < 8; NO++) {
					indice = j + 7 * NO;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}

				//amenaza sup der
				for (int NE = 1; NE < 8; NE++) {
					indice = j + 9 * NE;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}

				//amenaza inf izq
				for (int SO = 1; SO < 8; SO++) {
					indice = j - 9 * SO;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}

				//amenaza inf der
				for (int SE = 1; SE < 8; SE++) {
					indice = j - 7 * SE;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}

				//amenaza derecha
				for (int EE = 1; EE < 8; EE++) {
					indice = j + 1 * EE;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}

				//amenaza izquierda
				for (int OO = 1; OO < 8; OO++) {
					indice = j - 1 * OO;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}

				//amenaza arriba
				for (int NN = 1; NN < 8; NN++) {
					indice = j + 8 * NN;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}
				//amenaza abajo
				for (int SS = 1; SS < 8; SS++) {
					indice = j - 8 * SS;
					bool salto = 0;
					if (aux_ExisteCeldaSinAliado(i, indice, xx, yy))
					{
						aux_DiscriminaQuienAmenaza(i, indice);
						for (int obj = 0; obj < 48; obj++) {
							if ((listapiezas.piezas[obj].getPos().x == tablero.getCasilla_Ind(indice).getPos().x)
								&& (listapiezas.piezas[obj].getPos().y == tablero.getCasilla_Ind(indice).getPos().y))
								//Si se ha llegado aquí, es porque hay una pieza del oponente en la casilla objetivo
								salto = true;
						}
					}
					if (salto) break;
				}

			}

		}

	}
}

bool Movimientos::checkCasillaAmenazada(int n) {

	//en el turno de las blancas, nos interesa saber si nuestra celda está amenazada por las negras
	if (turnos())
		if (casillas_amenazadas_por_negras[n]) {
			cout << "La Casilla " << tablero.getCasilla_Ind(n).getCodigo() << " está siendo amenazada " << endl;
			return true;
		}
		else return false;
	//en el turno de las negras, nos interesa saber si nuestra celda está amenazada por las blancas
	else if (!turnos())
		if (casillas_amenazadas_por_blancas[n]) {
			cout << "La Casilla " << tablero.getCasilla_Ind(n).getCodigo() << " está siendo amenazada " << endl;
			return true;
		}
		else return false;
}

//Codigo para activar la bandera de pieza movida, para evaluar enroques

void Movimientos::BanderasMovimiento() {

	for (int i = 0; i < 48; i++) {
		if ((i == 8) && (listapiezas.piezas[i].getPos().x != tablero.getCasilla_Ind(0).getPos().x
			|| listapiezas.piezas[i].getPos().y != tablero.getCasilla_Ind(0).getPos().y))
			listapiezas.piezas[i].setMovido();//torreBlancaIzq

		if ((i == 9) && (listapiezas.piezas[i].getPos().x != tablero.getCasilla_Ind(7).getPos().x
			|| listapiezas.piezas[i].getPos().y != tablero.getCasilla_Ind(7).getPos().y))
			listapiezas.piezas[i].setMovido();//TorreBlancaDer

		if ((i == 14) && (listapiezas.piezas[i].getPos().x != tablero.getCasilla_Ind(4).getPos().x
			|| listapiezas.piezas[i].getPos().y != tablero.getCasilla_Ind(4).getPos().y))
			listapiezas.piezas[i].setMovido();//ReyBlanco

		if ((i == 24) && (listapiezas.piezas[i].getPos().x != tablero.getCasilla_Ind(56).getPos().x
			|| listapiezas.piezas[i].getPos().y != tablero.getCasilla_Ind(56).getPos().y))
			listapiezas.piezas[i].setMovido();//TorreNegraIzq

		if ((i == 25) && (listapiezas.piezas[i].getPos().x != tablero.getCasilla_Ind(63).getPos().x
			|| listapiezas.piezas[i].getPos().y != tablero.getCasilla_Ind(63).getPos().y))
			listapiezas.piezas[i].setMovido();//TorreNegraDer

		if ((i == 30) && (listapiezas.piezas[i].getPos().x != tablero.getCasilla_Ind(60).getPos().x
			|| listapiezas.piezas[i].getPos().y != tablero.getCasilla_Ind(60).getPos().y))
			listapiezas.piezas[i].setMovido();//ReyNegro

	}
}

void Movimientos::ResetDobles() {
	if (turnos()) { //Resetea la bandera del último movivimiento de salida doble de peón BLANCO
		for (int i = 0; i < 8; i++) {
			listapiezas.piezas[i].resetDoble();
		}
	}
	else { //Resetea la bandera del último movivimiento de salida doble de peón NEGRO
		for (int i = 16; i < 24; i++) {
			listapiezas.piezas[i].resetDoble();
		}
	}

	// Hay que cerciorarse que la llamada a la función se llama en el lugar adecuado
}



//void Movimientos::enroqueCorto(int i) {
//	if (i == 14) { //Rey Blanco
//		if (listapiezas.piezas[i].checkMovido() == false && listapiezas.piezas[9].checkMovido() == false //si no se han movido
//			&& checkCasillaAmenazada(4) == checkCasillaAmenazada(5) == checkCasillaAmenazada(6) == false) { //ni el rey se pone en peligro
//			listapiezas.piezas[i].setPos(tablero.getCasilla_Ind(6).getPos().x, tablero.getCasilla_Ind(6).getPos().y);
//			listapiezas.piezas[9].setPos(tablero.getCasilla_Ind(5).getPos().x, tablero.getCasilla_Ind(6).getPos().y);
//		}
//	}
//	if (i == 30) { //Rey Negro
//		if (listapiezas.piezas[i].checkMovido() == false && listapiezas.piezas[25].checkMovido() == false
//			&& checkCasillaAmenazada(60) == checkCasillaAmenazada(61) == checkCasillaAmenazada(62) == false) {
//			listapiezas.piezas[i].setPos(tablero.getCasilla_Ind(62).getPos().x, tablero.getCasilla_Ind(6).getPos().y);
//			listapiezas.piezas[9].setPos(tablero.getCasilla_Ind(61).getPos().x, tablero.getCasilla_Ind(6).getPos().y);
//		}
//	}
//}
//void Movimientos::enroqueLargo(int i) {
//	if (i == 14) { //Rey Blanco
//		if (listapiezas.piezas[i].checkMovido() == false && listapiezas.piezas[8].checkMovido() == false
//			&& checkCasillaAmenazada(4) == checkCasillaAmenazada(3) == checkCasillaAmenazada(2) == false) {
//			listapiezas.piezas[i].setPos(tablero.getCasilla_Ind(2).getPos().x, tablero.getCasilla_Ind(2).getPos().y);
//			listapiezas.piezas[9].setPos(tablero.getCasilla_Ind(3).getPos().x, tablero.getCasilla_Ind(3).getPos().y);
//		}
//	}
//	if (i == 30) { //Rey Negro
//		if (listapiezas.piezas[i].checkMovido() == false && listapiezas.piezas[24].checkMovido() == false
//			&& checkCasillaAmenazada(60) == checkCasillaAmenazada(59) == checkCasillaAmenazada(58) == false) {
//			listapiezas.piezas[i].setPos(tablero.getCasilla_Ind(58).getPos().x, tablero.getCasilla_Ind(58).getPos().y);
//			listapiezas.piezas[9].setPos(tablero.getCasilla_Ind(59).getPos().x, tablero.getCasilla_Ind(59).getPos().y);
//		}
//	}
//}
bool Movimientos::enroqueCortoPosible(int i)
{
	if (i == 14)
	{
		if (listapiezas.piezas[i].checkMovido() == false && listapiezas.piezas[9].checkMovido() == false //si no se han movido
			&& checkCasillaAmenazada(4) == checkCasillaAmenazada(5) == checkCasillaAmenazada(6) == false) //ni el rey se pone en peligro
		{
			return true;
		}
		else return false;
	}
	if (i == 30)
	{
		if (listapiezas.piezas[i].checkMovido() == false && listapiezas.piezas[25].checkMovido() == false
			&& checkCasillaAmenazada(60) == checkCasillaAmenazada(61) == checkCasillaAmenazada(62) == false)
		{
			return true;
		}
		else return false;
	}

}



bool Movimientos::enroqueLargoPosible(int i) {
	if (i == 14) { //Rey Blanco
		if (listapiezas.piezas[i].checkMovido() == false && listapiezas.piezas[8].checkMovido() == false
			&& checkCasillaAmenazada(4) == checkCasillaAmenazada(3) == checkCasillaAmenazada(2) == false)
		{
			return true;
		}
		else return false;
	}
	if (i == 30) { //Rey Negro
		if (listapiezas.piezas[i].checkMovido() == false && listapiezas.piezas[24].checkMovido() == false
			&& checkCasillaAmenazada(60) == checkCasillaAmenazada(59) == checkCasillaAmenazada(58) == false)
		{
			return true;
		}
		else return false;
	}

}



void Movimientos::enroqueCorto(int i) {
	if (i == 14) { //Rey Blanco
		if (enroqueCortoPosible(14))
		{
			listapiezas.piezas[i].setPos(tablero.getCasilla_Ind(6).getPos().x, tablero.getCasilla_Ind(6).getPos().y);
			listapiezas.piezas[9].setPos(tablero.getCasilla_Ind(5).getPos().x, tablero.getCasilla_Ind(6).getPos().y);
		}
	}
	if (i == 30) { //Rey Negro
		if (enroqueCortoPosible(30))
		{
			listapiezas.piezas[i].setPos(tablero.getCasilla_Ind(62).getPos().x, tablero.getCasilla_Ind(6).getPos().y);
			listapiezas.piezas[9].setPos(tablero.getCasilla_Ind(61).getPos().x, tablero.getCasilla_Ind(6).getPos().y);
		}
	}
}



void Movimientos::enroqueLargo(int i) {
	if (i == 14) { //Rey Blanco
		if (enroqueLargoPosible(i))
		{
			listapiezas.piezas[i].setPos(tablero.getCasilla_Ind(2).getPos().x, tablero.getCasilla_Ind(2).getPos().y);
			listapiezas.piezas[9].setPos(tablero.getCasilla_Ind(3).getPos().x, tablero.getCasilla_Ind(3).getPos().y);
		}
	}
	if (i == 30) { //Rey Negro
		if (enroqueLargoPosible(i))
		{
			listapiezas.piezas[i].setPos(tablero.getCasilla_Ind(58).getPos().x, tablero.getCasilla_Ind(58).getPos().y);
			listapiezas.piezas[9].setPos(tablero.getCasilla_Ind(59).getPos().x, tablero.getCasilla_Ind(59).getPos().y);
		}
	}
}




void Movimientos::aux_alCementerio(int iv) {

	listapiezas.piezas[iv].resetViviente();

	//Destinos en función de la pieza en cuestión
	if (iv == 0)		listapiezas.piezas[iv].setPos(22, 8);
	else if (iv == 1)		listapiezas.piezas[iv].setPos(22, 4);
	else if (iv == 2)		listapiezas.piezas[iv].setPos(22, 0);
	else if (iv == 3)		listapiezas.piezas[iv].setPos(22, -4);
	else if (iv == 4)		listapiezas.piezas[iv].setPos(22, -8);
	else if (iv == 5)		listapiezas.piezas[iv].setPos(22, -12);
	else if (iv == 6)		listapiezas.piezas[iv].setPos(22, -16);
	else if (iv == 7)		listapiezas.piezas[iv].setPos(22, -20);
	else if (iv == 8)		listapiezas.piezas[iv].setPos(26, -16);
	else if (iv == 9)		listapiezas.piezas[iv].setPos(26, -12);
	else if (iv == 10)		listapiezas.piezas[iv].setPos(26, 0);
	else if (iv == 11)		listapiezas.piezas[iv].setPos(26, 4);
	else if (iv == 12)		listapiezas.piezas[iv].setPos(26, -8);
	else if (iv == 13)		listapiezas.piezas[iv].setPos(26, -4);
	//else if (iv == 14)		listapiezas.piezas[iv].setPos(, );
	else if (iv == 15)		listapiezas.piezas[iv].setPos(26, -20);
	else if (iv == 16)		listapiezas.piezas[iv].setPos(-22, 8);
	else if (iv == 17)		listapiezas.piezas[iv].setPos(-22, 4);
	else if (iv == 18)		listapiezas.piezas[iv].setPos(-22, 0);
	else if (iv == 19)		listapiezas.piezas[iv].setPos(-22, -4);
	else if (iv == 20)		listapiezas.piezas[iv].setPos(-22, -8);
	else if (iv == 21)		listapiezas.piezas[iv].setPos(-22, -12);
	else if (iv == 22)		listapiezas.piezas[iv].setPos(-22, -16);
	else if (iv == 23)		listapiezas.piezas[iv].setPos(-22, -20);
	else if (iv == 24)		listapiezas.piezas[iv].setPos(-26, -16);
	else if (iv == 25)		listapiezas.piezas[iv].setPos(-26, -12);
	else if (iv == 26)		listapiezas.piezas[iv].setPos(-26, 0);
	else if (iv == 27)		listapiezas.piezas[iv].setPos(-26, 4);
	else if (iv == 28)		listapiezas.piezas[iv].setPos(-26, -8);
	else if (iv == 29)		listapiezas.piezas[iv].setPos(-26, -4);
	//else if (iv == 30)		listapiezas.piezas[iv].setPos(, );
	else if (iv == 31)		listapiezas.piezas[iv].setPos(-26, -20);
	else if (iv == 32)		listapiezas.piezas[iv].setPos(30, 8);
	else if (iv == 33)		listapiezas.piezas[iv].setPos(30, 4);
	else if (iv == 34)		listapiezas.piezas[iv].setPos(30, 0);
	else if (iv == 35)		listapiezas.piezas[iv].setPos(30, -4);
	else if (iv == 36)		listapiezas.piezas[iv].setPos(30, -8);
	else if (iv == 37)		listapiezas.piezas[iv].setPos(30, -12);
	else if (iv == 38)		listapiezas.piezas[iv].setPos(30, -16);
	else if (iv == 39)		listapiezas.piezas[iv].setPos(30, -20);
	else if (iv == 40)		listapiezas.piezas[iv].setPos(-30, 8);
	else if (iv == 41)		listapiezas.piezas[iv].setPos(-30, 4);
	else if (iv == 42)		listapiezas.piezas[iv].setPos(-30, 0);
	else if (iv == 43)		listapiezas.piezas[iv].setPos(-30, -4);
	else if (iv == 44)		listapiezas.piezas[iv].setPos(-30, -8);
	else if (iv == 45)		listapiezas.piezas[iv].setPos(-30, -12);
	else if (iv == 46)		listapiezas.piezas[iv].setPos(-30, -16);
	else if (iv == 47)		listapiezas.piezas[iv].setPos(-30, -20);

	else if (iv == 14) {
		cout << "Fin del Juego!" << endl;
		cout << "Ganan las Negras!" << endl;
		fin_de_partida = true;
	}
	else if (iv == 30) {
		cout << "Fin del Juego!" << endl;
		cout << "Ganan las Blancas!" << endl;
		fin_de_partida = true;
	}
	
}

void Movimientos::captura(int indice, float destino_x, float destino_y) {
	if (listapiezas.piezas[indice].getColor() == 1) {
		for (int victima = 0; victima < 48; victima++) {
			if ((listapiezas.piezas[victima].getPos().x == tablero.getCasilla_Pos(destino_x, destino_y).getPos().x)
				&& (listapiezas.piezas[victima].getPos().y == tablero.getCasilla_Pos(destino_x, destino_y).getPos().y)
				&& listapiezas.piezas[victima].getColor() == 2) {

				aux_alCementerio(victima);
				cout << "Pieza Negra Eliminada!" << endl;
			}

		}
	}
	if (listapiezas.piezas[indice].getColor() == 2) {
		for (int victima = 0; victima < 48; victima++) {
			if ((listapiezas.piezas[victima].getPos().x == tablero.getCasilla_Pos(destino_x, destino_y).getPos().x)
				&& (listapiezas.piezas[victima].getPos().y == tablero.getCasilla_Pos(destino_x, destino_y).getPos().y)
				&& listapiezas.piezas[victima].getColor() == 1) {

				aux_alCementerio(victima);
				cout << "Pieza Blanca Eliminada!" << endl;
			}

		}
	}

}



void Movimientos::comer() {


	//**************************************PIEZAS BLANCAS**************************************//
	//PEONES BLANCOS//
	// Peones blancos comer peones negros
	for (int i = 0; i < 8; i++) {
		if (listapiezas.peones_blancos[raton.peon_blanco_seleccionado].getPos().x == listapiezas.peones_negros[i].getPos().x &&
			listapiezas.peones_blancos[raton.peon_blanco_seleccionado].getPos().y == listapiezas.peones_negros[i].getPos().y) {
			listapiezas.peones_negros[i].setPos(-20, i);
			listapiezas.peones_negros[i].resetViviente();
		}
			
	}

	// Peones blancos comer torres negras
	for (int i = 0; i < 2; i++) {
		if (listapiezas.peones_blancos[raton.peon_blanco_seleccionado].getPos().x == listapiezas.torres_negras[i].getPos().x &&
			listapiezas.peones_blancos[raton.peon_blanco_seleccionado].getPos().y == listapiezas.torres_negras[i].getPos().y && !turnos()) {
			listapiezas.torres_negras[i].setPos(-24, i + 4);
			listapiezas.torres_negras[i].resetViviente();
		}
			
	}

	// Peones blancos comer caballos negros
	for (int i = 0; i < 2; i++) {
		if (listapiezas.peones_blancos[raton.peon_blanco_seleccionado].getPos().x == listapiezas.caballos_negros[i].getPos().x &&
			listapiezas.peones_blancos[raton.peon_blanco_seleccionado].getPos().y == listapiezas.caballos_negros[i].getPos().y){
			listapiezas.caballos_negros[i].setPos(-28, i + 8);
			listapiezas.caballos_negros[i].resetViviente();
		}
	}

	// Peones blancos comer alfiles negros
	for (int i = 0; i < 2; i++) {
		if (listapiezas.peones_blancos[raton.peon_blanco_seleccionado].getPos().x == listapiezas.alfiles_negros[i].getPos().x &&
			listapiezas.peones_blancos[raton.peon_blanco_seleccionado].getPos().y == listapiezas.alfiles_negros[i].getPos().y) {
			listapiezas.alfiles_negros[i].setPos(-32, i + 12);
			listapiezas.alfiles_negros[i].resetViviente();
		}
	}

	// Peones blancos comer reina negra
	for (int i = 0; i < 9; i++) {
		if (listapiezas.peones_blancos[raton.peon_blanco_seleccionado].getPos().x == listapiezas.reina_negra[i].getPos().x &&
			listapiezas.peones_blancos[raton.peon_blanco_seleccionado].getPos().y == listapiezas.reina_negra[i].getPos().y) {
			listapiezas.reina_negra[i].setPos(-30, i);
			listapiezas.reina_negra[i].resetViviente();
		}
	}
	//  Peones blancos comer rey negro
	if (listapiezas.peones_blancos[raton.peon_blanco_seleccionado].getPos().x == listapiezas.rey_negro.getPos().x &&
		listapiezas.peones_blancos[raton.peon_blanco_seleccionado].getPos().y == listapiezas.rey_negro.getPos().y) {
		/*listapiezas.rey_negro.setPos(26, 0);
		listapiezas.rey_negro.resetViviente();*/
		cout << "FIN DEL JUEGO. GANAN NEGRAS" << endl;
		listapiezas.reinicia();
		t = 0;
	}




	//TORRES BLANCAS//

	// Torres blancas comer peones negros
	for (int i = 0; i < 8; i++) {
		if (listapiezas.torres_blancas[0].getPos().x == listapiezas.peones_negros[i].getPos().x &&
			listapiezas.torres_blancas[0].getPos().y == listapiezas.peones_negros[i].getPos().y && !turnos()){
			listapiezas.peones_negros[i].setPos(-20, i);
			listapiezas.peones_negros[i].resetViviente();
		}

		if (listapiezas.torres_blancas[1].getPos().x == listapiezas.peones_negros[i].getPos().x &&
			listapiezas.torres_blancas[1].getPos().y == listapiezas.peones_negros[i].getPos().y && !turnos()) {
			listapiezas.peones_negros[i].setPos(-20, i);
			listapiezas.peones_negros[i].resetViviente();
		}
	}

	// Torres blancas comer torres negras
	for (int i = 0; i < 2; i++) {
		if (listapiezas.torres_blancas[raton.torre_blanca_seleccionada].getPos().x == listapiezas.torres_negras[i].getPos().x &&
			listapiezas.torres_blancas[raton.torre_blanca_seleccionada].getPos().y == listapiezas.torres_negras[i].getPos().y) {
			listapiezas.torres_negras[i].setPos(-24, i + 4);
			listapiezas.torres_negras[i].resetViviente();
		}
	}

	// Torres blancas comer caballos negros
	for (int i = 0; i < 2; i++) {
		if (listapiezas.torres_blancas[raton.torre_blanca_seleccionada].getPos().x == listapiezas.caballos_negros[i].getPos().x &&
			listapiezas.torres_blancas[raton.torre_blanca_seleccionada].getPos().y == listapiezas.caballos_negros[i].getPos().y) {
			listapiezas.caballos_negros[i].setPos(-28, i + 8);
			listapiezas.caballos_negros[i].resetViviente();
		}
	}

	// Torres blancas comer alfiles negros
	for (int i = 0; i < 2; i++) {
		if (listapiezas.torres_blancas[raton.torre_blanca_seleccionada].getPos().x == listapiezas.alfiles_negros[i].getPos().x &&
			listapiezas.torres_blancas[raton.torre_blanca_seleccionada].getPos().y == listapiezas.alfiles_negros[i].getPos().y) {
			listapiezas.alfiles_negros[i].setPos(-32, i + 12);
			listapiezas.alfiles_negros[i].resetViviente();
		}
	}

	// Torres blancas comer reina negra
	for (int i = 0; i < 9; i++) {
		if (listapiezas.torres_blancas[raton.torre_blanca_seleccionada].getPos().x == listapiezas.reina_negra[i].getPos().x &&
			listapiezas.torres_blancas[raton.torre_blanca_seleccionada].getPos().y == listapiezas.reina_negra[i].getPos().y) {
			listapiezas.reina_negra[i].setPos(-30, i);
			listapiezas.reina_negra[i].resetViviente();
		}
	}

	// Torres blancos comer rey negro
	if (listapiezas.torres_blancas[raton.torre_blanca_seleccionada].getPos().x == listapiezas.rey_negro.getPos().x &&
		listapiezas.torres_blancas[raton.torre_blanca_seleccionada].getPos().y == listapiezas.rey_negro.getPos().y) {
		/*listapiezas.rey_negro.setPos(26, 0);
		listapiezas.rey_negro.resetViviente();*/
		cout << "FIN DEL JUEGO. GANAN BLANCAS" << endl;
		listapiezas.reinicia();
		t = 0;

	}


	//CABALLOS BLANCOS

	// Caballos blancos comer peones negros
	for (int i = 0; i < 8; i++) {
		if (listapiezas.caballos_blancos[raton.caballo_blanco_seleccionado].getPos().x == listapiezas.peones_negros[i].getPos().x &&
			listapiezas.caballos_blancos[raton.caballo_blanco_seleccionado].getPos().y == listapiezas.peones_negros[i].getPos().y) {
			listapiezas.peones_negros[i].setPos(-20, i);
			listapiezas.peones_negros[i].resetViviente();
		}
	}

	// Caballos blancos comer torres negras
	for (int i = 0; i < 2; i++) {
		if (listapiezas.caballos_blancos[0].getPos().x == listapiezas.torres_negras[i].getPos().x &&
			listapiezas.caballos_blancos[0].getPos().y == listapiezas.torres_negras[i].getPos().y) {
			listapiezas.torres_negras[i].setPos(-24, i + 4);
			listapiezas.torres_negras[i].resetViviente();
		}

		if (listapiezas.caballos_blancos[1].getPos().x == listapiezas.torres_negras[i].getPos().x &&
			listapiezas.caballos_blancos[1].getPos().y == listapiezas.torres_negras[i].getPos().y) {
			listapiezas.torres_negras[i].setPos(-24, i + 4);
			listapiezas.torres_negras[i].resetViviente();
		}
	}

	// Caballos blancos comer caballos negros
	for (int i = 0; i < 2; i++) {
		if (listapiezas.caballos_blancos[raton.caballo_blanco_seleccionado].getPos().x == listapiezas.caballos_negros[i].getPos().x &&
			listapiezas.caballos_blancos[raton.caballo_blanco_seleccionado].getPos().y == listapiezas.caballos_negros[i].getPos().y) {
			listapiezas.caballos_negros[i].setPos(-28, i + 8);
			listapiezas.caballos_negros[i].resetViviente();
		}
	}

	// Caballos blancos comer alfiles negros
	for (int i = 0; i < 2; i++) {
		if (listapiezas.caballos_blancos[raton.caballo_blanco_seleccionado].getPos().x == listapiezas.alfiles_negros[i].getPos().x &&
			listapiezas.caballos_blancos[raton.caballo_blanco_seleccionado].getPos().y == listapiezas.alfiles_negros[i].getPos().y) {
			listapiezas.alfiles_negros[i].setPos(-32, i + 12);
			listapiezas.alfiles_negros[i].resetViviente();
		}
	}

	// Caballos blancos comer reina negra
	for (int i = 0; i < 9; i++) {
		if (listapiezas.caballos_blancos[raton.caballo_blanco_seleccionado].getPos().x == listapiezas.reina_negra[i].getPos().x &&
			listapiezas.caballos_blancos[raton.caballo_blanco_seleccionado].getPos().y == listapiezas.reina_negra[i].getPos().y) {
			listapiezas.reina_negra[i].setPos(-30, i);
			listapiezas.reina_negra[i].resetViviente();
		}
	}

	// Caballos blancos comer rey negro
	if (listapiezas.caballos_blancos[raton.caballo_blanco_seleccionado].getPos().x == listapiezas.rey_negro.getPos().x &&
		listapiezas.caballos_blancos[raton.caballo_blanco_seleccionado].getPos().y == listapiezas.rey_negro.getPos().y) {
		/*listapiezas.rey_negro.setPos(26, 0);
		listapiezas.rey_negro.resetViviente();*/
		cout << "FIN DEL JUEGO. GANAN BLANCAS" << endl;
		listapiezas.reinicia();
		t = 0;
	}



	//ALFILES BLANCOS

	// Alfiles blancos comer peones negros
	for (int i = 0; i < 8; i++) {
		if (listapiezas.alfiles_blancos[raton.alfil_blanco_seleccionado].getPos().x == listapiezas.peones_negros[i].getPos().x &&
			listapiezas.alfiles_blancos[raton.alfil_blanco_seleccionado].getPos().y == listapiezas.peones_negros[i].getPos().y) {
			listapiezas.peones_negros[i].setPos(-20, i);
			listapiezas.peones_negros[i].resetViviente();
		}
	}

	// Alfiles blancos comer torres negras
	for (int i = 0; i < 2; i++) {
		if (listapiezas.alfiles_blancos[raton.alfil_blanco_seleccionado].getPos().x == listapiezas.torres_negras[i].getPos().x &&
			listapiezas.alfiles_blancos[raton.alfil_blanco_seleccionado].getPos().y == listapiezas.torres_negras[i].getPos().y && !turnos()) {
			listapiezas.torres_negras[i].setPos(-24, i + 4);
			listapiezas.torres_negras[i].resetViviente();
		}
	}

	// Alfiles blancos comer caballos negros
	for (int i = 0; i < 2; i++) {
		if (listapiezas.alfiles_blancos[0].getPos().x == listapiezas.caballos_negros[i].getPos().x &&
			listapiezas.alfiles_blancos[0].getPos().y == listapiezas.caballos_negros[i].getPos().y && !turnos()) {
			listapiezas.caballos_negros[i].setPos(-28, i + 8);
			listapiezas.caballos_negros[i].resetViviente();
		}

		if (listapiezas.alfiles_blancos[1].getPos().x == listapiezas.caballos_negros[i].getPos().x &&
			listapiezas.alfiles_blancos[1].getPos().y == listapiezas.caballos_negros[i].getPos().y && !turnos()){
			listapiezas.caballos_negros[i].setPos(-28, i + 8);
			listapiezas.caballos_negros[i].resetViviente();
		}
	}

	// Alfiles blancos comer alfiles negros
	for (int i = 0; i < 2; i++) {
		if (listapiezas.alfiles_blancos[raton.alfil_blanco_seleccionado].getPos().x == listapiezas.alfiles_negros[i].getPos().x &&
			listapiezas.alfiles_blancos[raton.alfil_blanco_seleccionado].getPos().y == listapiezas.alfiles_negros[i].getPos().y) {
			listapiezas.alfiles_negros[i].setPos(-32, i + 12);
			listapiezas.alfiles_negros[i].resetViviente();
		}
	}

	// Alfiles blancos comer reina negra
	for (int i = 0; i < 9; i++) {
		if (listapiezas.alfiles_blancos[raton.alfil_blanco_seleccionado].getPos().x == listapiezas.reina_negra[i].getPos().x &&
			listapiezas.alfiles_blancos[raton.alfil_blanco_seleccionado].getPos().y == listapiezas.reina_negra[i].getPos().y) {
			listapiezas.reina_negra[i].setPos(-30, i);
			listapiezas.reina_negra[i].resetViviente();
		}
	}
	// Alfiles blancos comer rey negro
	if (listapiezas.alfiles_blancos[raton.alfil_blanco_seleccionado].getPos().x == listapiezas.rey_negro.getPos().x &&
		listapiezas.alfiles_blancos[raton.alfil_blanco_seleccionado].getPos().y == listapiezas.rey_negro.getPos().y) {
		/*listapiezas.rey_negro.setPos(26, 0);
		listapiezas.rey_negro.resetViviente();*/
		cout << "FIN DEL JUEGO. GANAN BLANCAS" << endl;
		listapiezas.reinicia();
		t = 0;
	}


	//REY BLANCO///

	// Rey blanco comer peones negros
	for (int i = 0; i < 8; i++) {
		if (listapiezas.rey_blanco.getPos().x == listapiezas.peones_negros[i].getPos().x &&
			listapiezas.rey_blanco.getPos().y == listapiezas.peones_negros[i].getPos().y) {
			listapiezas.peones_negros[i].setPos(-20, i);
			listapiezas.peones_negros[i].resetViviente();
		}
	}

	// Rey blanco comer torres negras
	for (int i = 0; i < 2; i++) {
		if (listapiezas.rey_blanco.getPos().x == listapiezas.torres_negras[i].getPos().x &&
			listapiezas.rey_blanco.getPos().y == listapiezas.torres_negras[i].getPos().y) {
			listapiezas.torres_negras[i].setPos(-24, i + 4);
			listapiezas.torres_negras[i].resetViviente();
		}
	}

	// Rey blanco comer caballos negros
	for (int i = 0; i < 2; i++) {
		if (listapiezas.rey_blanco.getPos().x == listapiezas.caballos_negros[i].getPos().x &&
			listapiezas.rey_blanco.getPos().y == listapiezas.caballos_negros[i].getPos().y) {
			listapiezas.caballos_negros[i].setPos(-28, i + 8);
			listapiezas.caballos_negros[i].resetViviente();
		}
	}

	// Rey blanco comer alfiles negros
	for (int i = 0; i < 2; i++) {
		if (listapiezas.rey_blanco.getPos().x == listapiezas.alfiles_negros[i].getPos().x &&
			listapiezas.rey_blanco.getPos().y == listapiezas.alfiles_negros[i].getPos().y) {
			listapiezas.alfiles_negros[i].setPos(-32, i + 12);
			listapiezas.alfiles_negros[i].resetViviente();
		}
	}

	// Rey blanco comer reina negra
	for (int i = 0; i < 9; i++) {
		if (listapiezas.rey_blanco.getPos().x == listapiezas.reina_negra[i].getPos().x &&
			listapiezas.rey_blanco.getPos().y == listapiezas.reina_negra[i].getPos().y) {
			listapiezas.reina_negra[i].setPos(-30, i);
			listapiezas.reina_negra[i].resetViviente();
		}
	}
		
	//Rey no puede comer a Rey

	
	//REINA BLANCA//

	// Reina blanca comer peones negros
	
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 8; i++) {
			if (listapiezas.reina_blanca[j].getPos().x == listapiezas.peones_negros[i].getPos().x &&
				listapiezas.reina_blanca[j].getPos().y == listapiezas.peones_negros[i].getPos().y && !turnos()) {
				listapiezas.peones_negros[i].setPos(-20, i);
				listapiezas.peones_negros[i].resetViviente();
			}
		}
	}

	// Reina blanca comer torres negras
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 2; i++) {
			if (listapiezas.reina_blanca[j].getPos().x == listapiezas.torres_negras[i].getPos().x &&
				listapiezas.reina_blanca[j].getPos().y == listapiezas.torres_negras[i].getPos().y && !turnos()) {
				listapiezas.torres_negras[i].setPos(-24, i + 4);
				listapiezas.torres_negras[i].resetViviente();
			}
		}
	}

	// Reina blanca comer caballos negros
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 2; i++) {
			if (listapiezas.reina_blanca[j].getPos().x == listapiezas.caballos_negros[i].getPos().x &&
				listapiezas.reina_blanca[j].getPos().y == listapiezas.caballos_negros[i].getPos().y && !turnos()) {
				listapiezas.caballos_negros[i].setPos(-28, i + 8);
				listapiezas.caballos_negros[i].resetViviente();
			}
		}
	}

	// Reina blanca comer alfiles negros
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 2; i++) {
			if (listapiezas.reina_blanca[j].getPos().x == listapiezas.alfiles_negros[i].getPos().x &&
				listapiezas.reina_blanca[j].getPos().y == listapiezas.alfiles_negros[i].getPos().y) {
				listapiezas.alfiles_negros[i].setPos(-32, i + 12);
				listapiezas.alfiles_negros[i].resetViviente();
			}
		}
	}

	// Reina blanca comer reina negra
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9; i++) {
			if (listapiezas.reina_blanca[j].getPos().x == listapiezas.reina_negra[i].getPos().x &&
				listapiezas.reina_blanca[j].getPos().y == listapiezas.reina_negra[i].getPos().y && !turnos()) {
				listapiezas.reina_negra[i].setPos(-30, i);
				listapiezas.reina_negra[i].resetViviente();
			}
		}
	}

	//  Reina blanca comer rey negro
	for (int j = 0; j < 9; j++) {
		if (listapiezas.reina_blanca[j].getPos().x == listapiezas.rey_negro.getPos().x &&
			listapiezas.reina_blanca[j].getPos().y == listapiezas.rey_negro.getPos().y) {
			/*listapiezas.rey_negro.setPos(26, 0);
			listapiezas.rey_negro.resetViviente();*/
			cout << "FIN DEL JUEGO. GANAN BLANCAS" << endl;
			listapiezas.reinicia();
			t = 0;
		}
	}

	//**************************************PIEZAS NEGRAS**************************************//


	//PEONES NEGROS
// Peones negros comer peones blancos
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (listapiezas.peones_negros[i].getPos().x == listapiezas.peones_blancos[j].getPos().x &&
				listapiezas.peones_negros[i].getPos().y == listapiezas.peones_blancos[j].getPos().y){
				listapiezas.peones_blancos[j].setPos(20, j);
				listapiezas.peones_blancos[j].resetViviente();
			}
		}
	}


	// Peones negros comer torres blancas
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 2; j++) {
			if (listapiezas.peones_negros[i].getPos().x == listapiezas.torres_blancas[j].getPos().x &&
				listapiezas.peones_negros[i].getPos().y == listapiezas.torres_blancas[j].getPos().y) {
				listapiezas.torres_blancas[j].setPos(24, i + 4);
				listapiezas.torres_blancas[j].resetViviente();
			}
		}
	}

	// Peones negros comer caballos blancos
	for (int i = 0; i < 2; i++) {
		if (listapiezas.peones_negros[raton.peon_negro_seleccionado].getPos().x == listapiezas.caballos_blancos[i].getPos().x &&
			listapiezas.peones_negros[raton.peon_negro_seleccionado].getPos().y == listapiezas.caballos_blancos[i].getPos().y) {
			listapiezas.caballos_blancos[i].setPos(28, i + 8);
			listapiezas.caballos_blancos[i].resetViviente();
		}
	}

	// Peones negros comer alfiles blancos
	for (int i = 0; i < 2; i++) {
		if (listapiezas.peones_negros[raton.peon_negro_seleccionado].getPos().x == listapiezas.alfiles_blancos[i].getPos().x &&
			listapiezas.peones_negros[raton.peon_negro_seleccionado].getPos().y == listapiezas.alfiles_blancos[i].getPos().y) {
			listapiezas.alfiles_blancos[i].setPos(32, i + 12);
			listapiezas.alfiles_blancos[i].resetViviente();
		}
	}

	// Peones negros comer reina blanca
	for (int i = 0; i < 9; i++) {
		if (listapiezas.peones_negros[raton.peon_negro_seleccionado].getPos().x == listapiezas.reina_blanca[i].getPos().x &&
			listapiezas.peones_negros[raton.peon_negro_seleccionado].getPos().y == listapiezas.reina_blanca[i].getPos().y) {
			listapiezas.reina_blanca[i].setPos(30, i);
			listapiezas.reina_blanca[i].resetViviente();
		}
	}
	

	// Peones negros comer rey blanco
	if (listapiezas.peones_negros[raton.peon_negro_seleccionado].getPos().x == listapiezas.rey_blanco.getPos().x &&
		listapiezas.peones_negros[raton.peon_negro_seleccionado].getPos().y == listapiezas.rey_blanco.getPos().y) {
		/*listapiezas.rey_blanco.setPos(26, 0);
		listapiezas.rey_blanco.resetViviente();*/
		cout << "FIN DEL JUEGO. GANAN NEGRAS" << endl;
		listapiezas.reinicia();
		t = 0;
	}
		


	//TORRES NEGRAS//

	// Torres negras comer peones blancos
	for (int i = 0; i < 8; i++) {
		if (listapiezas.torres_negras[raton.torre_negra_seleccionada].getPos().x == listapiezas.peones_blancos[i].getPos().x &&
			listapiezas.torres_negras[raton.torre_negra_seleccionada].getPos().y == listapiezas.peones_blancos[i].getPos().y) {
			listapiezas.peones_blancos[i].setPos(20, i);
			listapiezas.peones_blancos[i].resetViviente();
		}
			
	}

	// Torres negras comer torres blancas
	for (int i = 0; i < 2; i++) {
		if (listapiezas.torres_negras[0].getPos().x == listapiezas.torres_blancas[i].getPos().x &&
			listapiezas.torres_negras[0].getPos().y == listapiezas.torres_blancas[i].getPos().y) {
			listapiezas.torres_blancas[i].setPos(24, i + 4);
			listapiezas.torres_blancas[i].resetViviente();
		}

		if (listapiezas.torres_negras[1].getPos().x == listapiezas.torres_blancas[i].getPos().x &&
			listapiezas.torres_negras[1].getPos().y == listapiezas.torres_blancas[i].getPos().y) {
			listapiezas.torres_blancas[i].setPos(24, i + 4);
			listapiezas.torres_blancas[i].resetViviente();
		}
			
	}

	// Torres negras comer caballos blancos
	for (int i = 0; i < 2; i++) {
		if (listapiezas.torres_negras[raton.torre_negra_seleccionada].getPos().x == listapiezas.caballos_blancos[i].getPos().x &&
			listapiezas.torres_negras[raton.torre_negra_seleccionada].getPos().y == listapiezas.caballos_blancos[i].getPos().y) {
			listapiezas.caballos_blancos[i].setPos(28, i + 8);
			listapiezas.caballos_blancos[i].resetViviente();
		}
	}

	// Torres negras comer alfiles blancos
	for (int i = 0; i < 2; i++) {
		if (listapiezas.torres_negras[raton.torre_negra_seleccionada].getPos().x == listapiezas.alfiles_blancos[i].getPos().x &&
			listapiezas.torres_negras[raton.torre_negra_seleccionada].getPos().y == listapiezas.alfiles_blancos[i].getPos().y) {
			listapiezas.alfiles_blancos[i].setPos(32, i + 12);
			listapiezas.alfiles_blancos[i].resetViviente();
		}
			
	}

	// Torres negras comer reina blanca
	for (int i = 0; i < 9; i++) {
		if (listapiezas.torres_negras[raton.torre_negra_seleccionada].getPos().x == listapiezas.reina_blanca[i].getPos().x &&
			listapiezas.torres_negras[raton.torre_negra_seleccionada].getPos().y == listapiezas.reina_blanca[i].getPos().y) {
			listapiezas.reina_blanca[i].setPos(30, i);
			listapiezas.reina_blanca[i].resetViviente();
		}
	}
		

	// torres negros comer rey blanco
	if (listapiezas.torres_negras[raton.torre_negra_seleccionada].getPos().x == listapiezas.rey_blanco.getPos().x &&
		listapiezas.torres_negras[raton.torre_negra_seleccionada].getPos().y == listapiezas.rey_blanco.getPos().y){
		/*listapiezas.rey_blanco.setPos(26, 0);
		listapiezas.rey_blanco.resetViviente();*/
		cout << "FIN DEL JUEGO. GANAN NEGRAS" << endl;
		listapiezas.reinicia();
		t = 0;
	}
		



	//CABALLOS NEGROS

	// Caballos negros comer peones blancos
	for (int i = 0; i < 8; i++) {
		if (listapiezas.caballos_negros[raton.caballo_negro_seleccionado].getPos().x == listapiezas.peones_blancos[i].getPos().x &&
			listapiezas.caballos_negros[raton.caballo_negro_seleccionado].getPos().y == listapiezas.peones_blancos[i].getPos().y) {
			listapiezas.peones_blancos[i].setPos(20, i);
			listapiezas.peones_blancos[i].resetViviente();
		}
	}

	// Caballos negros comer torres blancas
	for (int i = 0; i < 2; i++) {
		if (listapiezas.caballos_negros[raton.caballo_negro_seleccionado].getPos().x == listapiezas.torres_blancas[i].getPos().x &&
			listapiezas.caballos_negros[raton.caballo_negro_seleccionado].getPos().y == listapiezas.torres_blancas[i].getPos().y) {
			listapiezas.torres_blancas[i].setPos(24, i + 4);
			listapiezas.torres_blancas[i].resetViviente();
		}
	}

	// Caballos negros comer caballos blancos
	for (int i = 0; i < 2; i++) {
		if (listapiezas.caballos_negros[0].getPos().x == listapiezas.caballos_blancos[i].getPos().x &&
			listapiezas.caballos_negros[0].getPos().y == listapiezas.caballos_blancos[i].getPos().y) {
			listapiezas.caballos_blancos[i].setPos(28, i + 8);
			listapiezas.caballos_blancos[i].resetViviente();
		}

		if (listapiezas.caballos_negros[1].getPos().x == listapiezas.caballos_blancos[i].getPos().x &&
			listapiezas.caballos_negros[1].getPos().y == listapiezas.caballos_blancos[i].getPos().y) {
			listapiezas.caballos_blancos[i].setPos(28, i + 8);
			listapiezas.caballos_blancos[i].resetViviente();
		}
	}

	// Caballos negros comer alfiles blancos
	for (int i = 0; i < 2; i++) {
		if (listapiezas.caballos_negros[raton.caballo_negro_seleccionado].getPos().x == listapiezas.alfiles_blancos[i].getPos().x &&
			listapiezas.caballos_negros[raton.caballo_negro_seleccionado].getPos().y == listapiezas.alfiles_blancos[i].getPos().y) {
			listapiezas.alfiles_blancos[i].setPos(32, i + 12);
			listapiezas.alfiles_blancos[i].resetViviente();
		}
	}

	// Caballos negros comer reina blanca
	for (int i = 0; i < 9; i++) {
		if (listapiezas.caballos_negros[raton.caballo_negro_seleccionado].getPos().x == listapiezas.reina_blanca[i].getPos().x &&
			listapiezas.caballos_negros[raton.caballo_negro_seleccionado].getPos().y == listapiezas.reina_blanca[i].getPos().y) {
			listapiezas.reina_blanca[i].setPos(30, i);
			listapiezas.reina_blanca[i].resetViviente();
		}
	}

	// Caballos negros comer rey blanco
	if (listapiezas.caballos_negros[raton.caballo_negro_seleccionado].getPos().x == listapiezas.rey_blanco.getPos().x &&
		listapiezas.caballos_negros[raton.caballo_negro_seleccionado].getPos().y == listapiezas.rey_blanco.getPos().y) {
		/*listapiezas.rey_blanco.setPos(26, 0);
		listapiezas.rey_blanco.resetViviente();*/
		cout << "FIN DEL JUEGO. GANAN NEGRAS" << endl;
		listapiezas.reinicia();
		t = 0;
	}

	//ALFILES NEGROS

	// Alfiles negros comer peones blancos
	for (int i = 0; i < 8; i++) {
		if (listapiezas.alfiles_negros[raton.alfil_negro_seleccionado].getPos().x == listapiezas.peones_blancos[i].getPos().x &&
			listapiezas.alfiles_negros[raton.alfil_negro_seleccionado].getPos().y == listapiezas.peones_blancos[i].getPos().y) {
			listapiezas.peones_blancos[i].setPos(20, i);
			listapiezas.peones_blancos[i].resetViviente();
		}
	}

	// Alfiles negros comer torres blancas
	for (int i = 0; i < 2; i++) {
		if (listapiezas.alfiles_negros[raton.alfil_negro_seleccionado].getPos().x == listapiezas.torres_blancas[i].getPos().x &&
			listapiezas.alfiles_negros[raton.alfil_negro_seleccionado].getPos().y == listapiezas.torres_blancas[i].getPos().y) {
			listapiezas.torres_blancas[i].setPos(24, i + 4);
			listapiezas.torres_blancas[i].resetViviente();
		}
	}

	// Alfiles negros comer caballos blancos
	for (int i = 0; i < 2; i++) {
		if (listapiezas.alfiles_negros[raton.alfil_negro_seleccionado].getPos().x == listapiezas.caballos_blancos[i].getPos().x &&
			listapiezas.alfiles_negros[raton.alfil_negro_seleccionado].getPos().y == listapiezas.caballos_blancos[i].getPos().y) {
			listapiezas.caballos_blancos[i].setPos(28, i + 8);
			listapiezas.caballos_blancos[i].resetViviente();
		}
	}

	// Alfiles negros comer alfiles blancos
	for (int i = 0; i < 2; i++) {
		if (listapiezas.alfiles_negros[0].getPos().x == listapiezas.alfiles_blancos[i].getPos().x &&
			listapiezas.alfiles_negros[0].getPos().y == listapiezas.alfiles_blancos[i].getPos().y) {
			listapiezas.alfiles_blancos[i].setPos(32, i + 12);
			listapiezas.alfiles_blancos[i].resetViviente();
		}

		if (listapiezas.alfiles_negros[1].getPos().x == listapiezas.alfiles_blancos[i].getPos().x &&
			listapiezas.alfiles_negros[1].getPos().y == listapiezas.alfiles_blancos[i].getPos().y) {
			listapiezas.alfiles_blancos[i].setPos(32, i + 12);
			listapiezas.alfiles_blancos[i].resetViviente();
		}
	}

	// Alfiles negros comer reina blanca
	for (int i = 0; i < 9; i++) {
		if (listapiezas.alfiles_negros[raton.alfil_negro_seleccionado].getPos().x == listapiezas.reina_blanca[i].getPos().x &&
			listapiezas.alfiles_negros[raton.alfil_negro_seleccionado].getPos().y == listapiezas.reina_blanca[i].getPos().y) {
			listapiezas.reina_blanca[i].setPos(30, i);
			listapiezas.reina_blanca[i].resetViviente();
		}
	}

	// Alfines negros comer rey blanco
	if (listapiezas.alfiles_negros[raton.alfil_negro_seleccionado].getPos().x == listapiezas.rey_blanco.getPos().x &&
		listapiezas.alfiles_negros[raton.alfil_negro_seleccionado].getPos().y == listapiezas.rey_blanco.getPos().y) {
		/*listapiezas.rey_blanco.setPos(26, 0);
		listapiezas.rey_blanco.resetViviente();*/
		cout << "FIN DEL JUEGO. GANAN NEGRAS" << endl;
		listapiezas.reinicia();
		t = 0;
	}

	//REINA NEGRA//

	// Reina negra comer peones blancos
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 8; i++) {
			if (listapiezas.reina_negra[j].getPos().x == listapiezas.peones_blancos[i].getPos().x &&
				listapiezas.reina_negra[j].getPos().y == listapiezas.peones_blancos[i].getPos().y) {
				listapiezas.peones_blancos[i].setPos(20, i);
				listapiezas.peones_blancos[i].resetViviente();
			}
		}
	}

	// Reina negra comer torres blancas
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 2; i++) {
			if (listapiezas.reina_negra[j].getPos().x == listapiezas.torres_blancas[i].getPos().x &&
				listapiezas.reina_negra[j].getPos().y == listapiezas.torres_blancas[i].getPos().y) {
				listapiezas.torres_blancas[i].setPos(24, i + 4);
				listapiezas.torres_blancas[i].resetViviente();
			}
		}
	}

	// Reina negra comer caballos blancos
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 2; i++) {
			if (listapiezas.reina_negra[j].getPos().x == listapiezas.caballos_blancos[i].getPos().x &&
				listapiezas.reina_negra[j].getPos().y == listapiezas.caballos_blancos[i].getPos().y) {
				listapiezas.caballos_blancos[i].setPos(28, i + 8);
				listapiezas.caballos_blancos[i].resetViviente();
			}
		}
	}

	// Reina negra comer alfiles blancos
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 2; i++) {
			if (listapiezas.reina_negra[j].getPos().x == listapiezas.alfiles_blancos[i].getPos().x &&
				listapiezas.reina_negra[j].getPos().y == listapiezas.alfiles_blancos[i].getPos().y) {
				listapiezas.alfiles_blancos[i].setPos(32, i + 12);
				listapiezas.alfiles_blancos[i].resetViviente();
			}
		}
	}
	// Reina negra comer reina blanca
	for (int j = 0; j < 9; j++) {
		for (int i = 1; i < 9; i++) {
			if (listapiezas.reina_negra[j].getPos().x == listapiezas.reina_blanca[i].getPos().x &&
				listapiezas.reina_negra[j].getPos().y == listapiezas.reina_blanca[i].getPos().y) {
				listapiezas.reina_blanca[i].setPos(30, i);
				listapiezas.reina_blanca[i].resetViviente();
			}
		}
	}
	// Reinas negras comer rey blanco
	for (int j = 0; j < 9; j++) {
		if (listapiezas.reina_negra[j].getPos().x == listapiezas.rey_blanco.getPos().x &&
			listapiezas.reina_negra[j].getPos().y == listapiezas.rey_blanco.getPos().y) {
			/*listapiezas.rey_blanco.setPos(26, 0);
			listapiezas.rey_blanco.resetViviente();*/
			cout << "FIN DEL JUEGO. GANAN NEGRAS" << endl;
			listapiezas.reinicia();
			t = 0;
		}
	}


	//REY NEGRO//

	// Rey negro comer peones blancos
	for (int i = 0; i < 8; i++) {
		if (listapiezas.rey_negro.getPos().x == listapiezas.peones_blancos[i].getPos().x &&
			listapiezas.rey_negro.getPos().y == listapiezas.peones_blancos[i].getPos().y) {
			listapiezas.peones_blancos[i].setPos(20, i);
			listapiezas.peones_blancos[i].resetViviente();
		}
	}

	// Rey negro comer torres blancas
	for (int i = 0; i < 2; i++) {
		if (listapiezas.rey_negro.getPos().x == listapiezas.torres_blancas[i].getPos().x &&
			listapiezas.rey_negro.getPos().y == listapiezas.torres_blancas[i].getPos().y) {
			listapiezas.torres_blancas[i].setPos(24, i + 4);
			listapiezas.torres_blancas[i].resetViviente();
		}
	}

	// Rey negro comer caballos blancos
	for (int i = 0; i < 2; i++) {
		if (listapiezas.rey_negro.getPos().x == listapiezas.caballos_blancos[i].getPos().x &&
			listapiezas.rey_negro.getPos().y == listapiezas.caballos_blancos[i].getPos().y){
			listapiezas.caballos_blancos[i].setPos(28, i + 8);
			listapiezas.caballos_blancos[i].resetViviente();
		}
			
	}

	// Rey negro comer alfiles blancos
	for (int i = 0; i < 2; i++) {
		if (listapiezas.rey_negro.getPos().x == listapiezas.alfiles_blancos[i].getPos().x &&
			listapiezas.rey_negro.getPos().y == listapiezas.alfiles_blancos[i].getPos().y){
			listapiezas.alfiles_blancos[i].setPos(32, i + 12);
			listapiezas.alfiles_blancos[i].resetViviente();
		}
			
	}

	// Rey negro comer reina blanca
	for (int i = 0; i < 9; i++) {
		if (listapiezas.rey_negro.getPos().x == listapiezas.reina_blanca[i].getPos().x &&
			listapiezas.rey_negro.getPos().y == listapiezas.reina_blanca[i].getPos().y) {
			listapiezas.reina_blanca[i].setPos(30, i);
			listapiezas.reina_blanca[i].resetViviente();
		}
	}

	//Rey no puede comer a Rey
}



//*****************************************************************************************************

void Movimientos::promocionAReina() {
	// Peones blancos promocionan a reinas blancas
	for (int i = 0; i < 8; i++) {
		if (listapiezas.peones_blancos[i].getPos().y > 12 && listapiezas.peones_blancos[i].getPos().y < 16) //cuando un peón negro llega a la casilla de abajo
		{
			Pieza aux;
			aux.setPos(listapiezas.peones_blancos[i].getPos().x, listapiezas.peones_blancos[i].getPos().y);//se guardan las coordenadas del peón
			listapiezas.peones_blancos[i].setPos(20, i);
			listapiezas.peones_blancos[i].resetViviente();
			listapiezas.reina_blanca[i + 1].setPos(aux.getPos().x, aux.getPos().y);
			listapiezas.reina_blanca[i + 1].setViviente();
		}

	}

	// Peones negros Promocionan a reinas negras
	for (int i = 0; i < 8; i++) {
			if (listapiezas.peones_negros[i].getPos().y <- 12 && listapiezas.peones_negros[i].getPos().y > -16 ) //cuando un peón negro llega a la casilla de abajo
			{
				Pieza aux;
				aux.setPos(listapiezas.peones_negros[i].getPos().x, listapiezas.peones_negros[i].getPos().y);//se guardan las coordenadas del peón
				listapiezas.peones_negros[i].setPos(20, i);
				listapiezas.peones_blancos[i].resetViviente();
				listapiezas.reina_negra[i + 1].setPos(aux.getPos().x,aux.getPos().y);
				listapiezas.reina_negra[i + 1].setViviente();
			}
				
	}



}

void Movimientos::setFinDePartida() {
	if (listapiezas.rey_blanco.checkViviente() == false || listapiezas.rey_negro.checkViviente() == false || tablas()) {
		fin_de_partida == 1;
		listapiezas.reinicia();
	}
}

bool Movimientos::tablas() {
	bool aux1, aux2, aux3;
	for (int i = 0; i < 14; i++) {
		if (listapiezas.piezas[i].checkViviente())
			aux1 = true;
	}
	for (int i = 15; i < 30; i++) {
		if (listapiezas.piezas[i].checkViviente())
			aux2 = true;
	}
	for (int i = 31; i < 48; i++) {
		if (listapiezas.piezas[i].checkViviente())
			aux3 = true;
	}
	if (aux1 = aux2 = aux3 = 0)  //si todas las piezas, excepto los reyes, están muertas:
		return true;
}


void Movimientos::sonido()
{
	ETSIDI::play("bin/sonidos/movimiento.wav");
}
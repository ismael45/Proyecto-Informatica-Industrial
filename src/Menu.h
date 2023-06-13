#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

class Menu {

private:

	float tamaño;
	Vector2D posicion;
	ETSIDI::Sprite sprite{ "bin/imagenes/fondo.png", 0.0, 0.0, 3, 3.5 };

public:

	Menu() {
		tamaño = 2.0f;
		posicion = { 0.0f, 0.0f };
		dibuja_Fondo();
		dibuja_opcion_1();
		dibuja_opcion_2();
		dibuja_texto();
	}
	void dibuja_Fondo(); 
	void dibuja_opcion_1();
	void dibuja_opcion_2();
	void dibuja_texto();

};

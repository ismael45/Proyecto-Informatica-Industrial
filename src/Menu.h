#pragma once
#include <freeglut.h>
#include <iostream>
#include "Pieza.h"
#include <Windows.h>
#include <WinUser.h>
#include "Vector2D.h"


class Menu :public Pieza{
public:

	Menu(): Pieza() {}
	void dibuja_Fondo(); 
	void dibuja_opcion_1();
	void dibuja_opcion_2();
	void dibuja_texto();

};

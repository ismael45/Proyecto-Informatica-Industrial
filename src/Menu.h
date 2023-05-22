#pragma once
#include <freeglut.h>
#include <iostream>
#include "Pieza.h"
#include <Windows.h>
#include <WinUser.h>
class Menu :public Pieza{
private:
	int clicX;
	int clicY;
public:
	Menu(): Pieza() {}
	void dibuja_Fondo(); 
	void dibuja_opcion_1();
	void dibuja_opcion_2();
	void dibuja_texto();
	int detectarClic(int x, int y);
};

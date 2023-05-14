#include "Casilla.h"
#include "freeglut.h"

Casilla::Casilla() {
	color_tab.r = 255;
	color_tab.g = 250;
	color_tab.b = 250;
	tamano = 4.0f;
	posicion = { 0.0f, 0.0f };
}

Casilla::~Casilla() {};

void Casilla::setColor(Byte r, Byte g, Byte b) {
	color_tab.r = r;
	color_tab.g = g;
	color_tab.b = b;
}

void Casilla::setPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

void Casilla::dibuja() {
	{
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y, 0);
		glColor3f(color_tab.r, color_tab.g, color_tab.b);
		glutSolidCube(tamano);
		glPopMatrix();
	}
}

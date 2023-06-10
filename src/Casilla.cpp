#include "Casilla.h"


Casilla::Casilla() {

	tamaño = 4.0f;
	posicion = { 0.0f, 0.0f };

}

Casilla::~Casilla() {

};

void Casilla::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

void Casilla::setPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

Vector2D Casilla::getPos() {
	return posicion;
}

void Casilla::dibuja() {
	{
		glColor3ub(color.r, color.g, color.b);
		//glPushMatrix();
		glTranslatef(posicion.x, posicion.y, 0);
		//glColor3f(color_tab.r, color_tab.g, color_tab.b);
		glutSolidCube(tamaño);
		glTranslatef(-posicion.x, -posicion.y, 0);
		//glPopMatrix();
	}
}

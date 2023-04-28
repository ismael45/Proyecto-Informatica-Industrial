#include "Casilla.h"
#include "freeglut.h"

Casilla::Casilla() {
	tamano = 4.0f;
};

Casilla::~Casilla() {};

void Casilla::setColor(Byte r, Byte g, Byte b) {
	color.r=r;
	color.g=g;
	color.b = b;
}

void Casilla::setPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

void Casilla::dibuja() {
	{
		glColor3ub(color.r, color.g, color.b);
		glTranslatef(posicion.x, posicion.y, 0);
		glutSolidCube(tamano);
		glTranslatef(-posicion.x, -posicion.y, 0);
	}
}


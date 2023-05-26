#include "Caballo.h"


void Caballo::dibuja_caballoBlanco()
{
	sprite = { "bin/imagenes/Caballo_blanco.png", posicion.x + 0.07f, posicion.y - 0.03f, 3.5, 4};

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();

}

void Caballo::dibuja_caballoNegro()
{
	sprite = { "bin/imagenes/Caballo_negro.png", posicion.x + 0.07f, posicion.y - 0.03f, 3.5, 4 };

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();

}

void Caballo::dibuja_caballoFlor()
{
	sprite = { "bin/imagenes/Caballo_flor.png", posicion.x + 0.07f, posicion.y - 0.03f, 3, 3};

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();
}

void Caballo::dibuja_caballoBosque()
{
	sprite = { "bin/imagenes/Caballo_bosque.png", posicion.x + 0.07f, posicion.y - 0.03f, 3.5, 4 };

	glPushMatrix();
	glTranslatef(0, 0, 2);
	sprite.draw();
	glPopMatrix();
}

void Caballo::mover()
{
	//dar una vuelta sobre cómo debe ser el movimiento en L
	/*Movimiento::moverDiagDrcha(getPos());
	Movimiento::moverDiagIzq(getPos());
	Movimiento::moverArriba(getPos());
	Movimiento::moverAbajo(getPos());
	Movimiento::moverDerecha(getPos());
	Movimiento::moverIzquierda(getPos());*/
}

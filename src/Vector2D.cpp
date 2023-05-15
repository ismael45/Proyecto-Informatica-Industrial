#include "Vector2D.h"
#include "math.h"

Vector2D::Vector2D(float xv, float yv) {  //(1) CONSTRUCTOR NUEVO
	x = xv;
	y = yv;
}

float Vector2D::modulo() {  //(2) MODULO DEL VECTOR
	return (float)sqrt(x * x + y * y);  //conversion forzosa de tipo de datos para evitar warnings
}

float Vector2D::argumento() {  //(3) ARGUMENTO DEL VECTOR
	return (float)atan2(y, x); //nota: recoge todas las excepciones de cuadrantes e infinitos
}

Vector2D Vector2D::unitario() {  //(4) DEVUELVE UN VECTOR UNITARIO
	Vector2D retorno(x, y);
	float mod = modulo();
	if (mod > 0.00001) {
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}

Vector2D Vector2D::operator - (Vector2D v) {  //(5) RESTA DE VECTORES
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}

Vector2D Vector2D::operator + (Vector2D v) {  //(6) SUMA DE VECTORES
	Vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}

float Vector2D:: operator * (Vector2D v) {  //(7) PRODUCTO ESCALAR DE DOS VECTORES
	float res;
	res = (x * v.x) + (y * v.y);
	return res;
}

Vector2D Vector2D::operator * (float esc) {  //(8) PRODUCTO POR UN ESCALAR 
	Vector2D res;
	res.x = x * esc;
	res.y = y * esc;
	return res;
}
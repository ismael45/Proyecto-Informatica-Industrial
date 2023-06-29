#include "Pieza.h"

Pieza::Pieza() {

    tamaño = 2.0f;
    posicion = { 0.0f, 0.0f };
    tipo = NOTIPO;
    color = NOCOLOR;
    valor = 0;          // Solo en Caso del Rey no cambiará
}


Pieza::~Pieza() {}

//Setters

void Pieza::setColor(Color c) {
    color = c;
}

void Pieza::setTipo(Tipo t) {
    tipo = t;
}

void Pieza::setPos(float x, float y){
    posicion.x = x;
    posicion.y = y; 
}

void Pieza::setValor(float v) {
    valor = v;
}

//Getters

Color Pieza::getColor() {
    return color;
}

Vector2D Pieza::getPos() const {
    return posicion;
}

float Pieza::getValor() {
    if (checkViviente()) return valor;
    else return 0.0;
}


bool Pieza::checkViviente() {
    return viviente;
}
void Pieza::resetViviente() {
    viviente=false;
}
void Pieza::setViviente() {
    viviente = true;
}

//Movimientos unitarios de casillas

void Pieza::mover_arriba() {
    float x = getPos().x;
    float y = getPos().y + 4;
    setPos(x, y);
 }

void Pieza::mover_abajo() {
    float x = getPos().x;
    float y = getPos().y - 4;
    setPos(x, y);
 }

void Pieza::mover_izquierda() {
    float x = getPos().x - 4;
    float y = getPos().y;
    setPos(x, y);
}

void Pieza::mover_derecha() {
    float x = getPos().x + 4;
    float y = getPos().y;
    setPos(x, y);
}

//Metodos para la captura "En Passant"

void Pieza::setDoble() {
	SalidaDobleReciente = true;
}
void Pieza::resetDoble() {
	SalidaDobleReciente = false;
}
bool Pieza::getDoble() {
	if (SalidaDobleReciente)
        return true;
}

//Métodos para el enroque y jaque

bool Pieza::checkJaque() {
    if (enJaque) return true;
}
void Pieza::setJaque() {
    enJaque = true;
}
void Pieza::resetJaque() {
    enJaque = false;
}
    
    
bool Pieza::checkMovido() {
    if (movido) return true;
}
    
void Pieza::setMovido() {
    movido = true;
}

bool Pieza::operator==(Pieza& rhs) {
    if ((this->getColor() == rhs.getColor()) && (this->getPos() == rhs.getPos()))
        return 1;
    else return 0;
}

//bool operator==(const Pieza& lhs, const Pieza& rhs) {
//  return lhs.getColor() == rhs.getColor() &&
//         lhs.getPos() == rhs.getPos();
//}
﻿#include "Pieza.h"

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
    return valor;
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


#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

//ETSIDI_API Sprite(const char *texturePath, float x=0, float y=0, float width=-1, float height=-1);

class Pieza
{
protected:
	Vector2D pos;
	bool color;
	ETSIDI::Sprite sprite{ "bin/imagenes/rey_negras.png", 0.0, 0.0, 0.0, 0.0 };

public:
	virtual ~Pieza() {}
	virtual void dibuja() {}
	virtual void mueve() {}
	void setpos(Vector2D _pos) { pos = _pos; }
	void setcolor(bool _color) { color = _color; }
	Vector2D getpos() { return pos; }
	bool getcolor() { return color; }
	void inicializa( Vector2D , bool);
	virtual void destruyeficha();
};


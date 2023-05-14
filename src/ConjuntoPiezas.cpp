#include "ConjuntoPiezas.h"

void ConjuntoPiezas::agregar(Pieza* _pieza)
{
	if (numero < NumMax) {
		conjuntoPiezas[numero++] = _pieza;
	}
}

void ConjuntoPiezas::inicializa()
{
	float j = 1;
	for (int i = 0; i < NumMax; i++)
	{
		if (i < 8) conjuntoPiezas[i]->inicializa(Vector2D{ j,1 }, false);
		if (i == 8)j = 1;
		if (i > 7 && i < 16)conjuntoPiezas[i]->inicializa(Vector2D{ j,3 }, false);
		if (i == 16)j = 1;
		if (i > 15 && i < 24)conjuntoPiezas[i]->inicializa(Vector2D{ j,13 }, true);
		if (i == 24)j = 1;
		if (i > 23)conjuntoPiezas[i]->inicializa(Vector2D{ j,15 }, true);
		j += 2;
	}

}

void ConjuntoPiezas::dibuja()
{
	for (int i = 0; i < NumMax; i++)
	{
		conjuntoPiezas[i]->dibuja();
	}
}


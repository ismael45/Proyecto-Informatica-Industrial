#include "Tablero.h"
#include "Casilla.h"
#include "Texto.h"

class Mundo
{
public:
	Mundo();
	virtual~Mundo();
private:
	Tablero tablero;

public: 
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;

	Texto texto(); // Crear un objeto Texto con las coordenadas (0, 0) del tablero


};

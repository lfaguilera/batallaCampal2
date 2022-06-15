#ifndef TABLERO_H_
#define TABLERO_H_

#include "lista.h"
#include "casilla.h"

class Tablero
{
	private:
		Lista<Lista<Lista<Casilla*>*>*> *tableroJuego;
		int limiteX;
		int limiteY;
		int limiteZ;

	public:
		Tablero(int x,int y, int z);
		~Tablero();
		void getLimites(int &limiteEnX,int &limiteEnY,int &limiteEnZ);
		Casilla* encontrarCasilla(int x, int y, int z);
		void exportarTablero();
		void emitirConsola();
};


#endif

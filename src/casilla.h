#ifndef CASILLA_H_
#define CASILLA_H_

#ifndef NULL
#define NULL 0
#endif /* NULL */

#include "ficha.h"


typedef enum
{
	AGUA,
	AIRE,
  TIERRA
}TipoDeTerreno;

typedef enum{
	INACTIVA,
	VACIA,
	OCUPADA
}EstadoDeCasilla;

class Casilla
{
	private:
		EstadoDeCasilla estado;
		int x;
		int y;
		int z;
		Ficha *fichaCasilla;
		TipoDeTerreno terreno;

	public:
		Casilla(int posicionX, int posicionY, int posicionZ,EstadoDeCasilla estadoInicio, TipoDeTerreno terreno);
		~Casilla();
		void getPosicionCasilla(int &posixionX,int &posicionY, int &posicionZ);
		EstadoDeCasilla getEstadoCasilla();
		void setEstadoCasilla(EstadoDeCasilla estadoNuevo);
		Ficha* getFichaCasilla();
		void setFicha(Ficha *ficha);
		void vaciarCasilla();
		TipoDeTerreno getTerrenoCasilla();
   		void setTerrenoCasilla(TipoDeTerreno nuevoTipoDeTerreno);
};

#endif

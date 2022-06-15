#ifndef CARTA_H_
#define CARTA_H_

#include "tablero.h"

enum TipoAccion {
  CARTA_MISIL, // dispara un misil
  CARTA_AVION, // ubica un avion
  CARTA_BARCO, // ubica un barco
  CARTA_LASER, // elimina todas las fichas en alguna fila o columna
  CARTA_DIQUE, // posibilita cambiar algun casillero de tierra a agua y viceversa
  CARTA_BOMBARDEO // habilita 3 disparos de misiles con area 1x1x1
};

class Carta
{
	private:
	    TipoAccion tipo;
  public:
    Carta();
    void setTipoCartaAlAzar();
    TipoAccion getTipo();
	int* pedirCoordenadas();
    void jugarCarta(TipoAccion tipo,Jugador *jugador,Tablero *tablero);
    void jugarMisil(Tablero *tablero);
    void jugarAvion(Tablero *tablero, Jugador * jugador);
    void jugarBarco(Tablero *tablero, Jugador * jugador);
    void jugarLaser(Tablero *tablero);
    void jugarDique(Tablero *tablero);
    void jugarBombardeo(Tablero *tablero);
    ~Carta();
};

#endif

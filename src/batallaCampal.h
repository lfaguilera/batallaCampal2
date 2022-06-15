#ifndef BATALLACAMPAL_H_
#define BATALLACAMPAL_H_

#include "lista.h"
#include "tablero.h"
#include "jugador.h"
#include "ficha.h"
#include "carta.h"


class BatallaCampal
{
	private:
		Lista<Jugador*> *jugadores;
		Tablero *tableroJuego;
		int cantidadJugadores;
		int jugadoresRestantes;

	public:
		BatallaCampal(int x, int y ,int z, int jugadores,int soldados);
		~BatallaCampal();
		/*Funciones de inicio*/
		void setSoldadosInicio();
		/*Funciones de juego*/
		void jugarBatallaCampal();
		void atacar(Jugador *jugador);
		void moverFicha(Jugador *jugador);
		void jugarCarta(Jugador *jugador);
		bool posicionesAtaqueCorrecta(Jugador *jugador,int x,int y,int z);
		bool posicionSoldadoCorrecta(Jugador *jugador,int x,int y,int z);
		bool posicionAMoverSoldadoCorrecta(int xAnterior, int yAnterior, int zAnterior, int xNuevo, int yNuevo, int zNuevo);
		bool getJugadorVivo(Jugador *jugador);
		void setJugadorVivo(Jugador *jugador);
};


#endif

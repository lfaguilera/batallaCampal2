#ifndef FICHA_H_
#define FICHA_H_

#ifndef NULL
#define NULL 0
#endif /* NULL */
	
#include "jugador.h"

typedef enum{
    SOLDADO, //
    AVION, // 
    BARCO, //
	NINGUNA
}TipoFicha;

class Ficha
{
	private:
	    Jugador *jugador = NULL;
	    TipoFicha ficha;

	public:
		Ficha(TipoFicha tipo, Jugador *jugador);
	    Jugador* getJugador();
	    void setJugador(Jugador *jugador);
	    TipoFicha getTipo();
	    void setTipo(TipoFicha tipo);
	    ~Ficha();
};

#endif


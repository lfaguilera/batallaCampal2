#ifndef JUGADOR_H_
#define JUGADOR_H_


class Jugador
{
	private:
    bool vivo;
		int soldadosRestantes;
		int identificador;
	public:
		Jugador(int soldadosInicial,int identificadorNuevo);
		~Jugador();
		int getSoldadosRestantes();
		void setSoldadosRestantes(int soldados);
		bool getJugadorVivo();
		void setJugadorVivo(bool estado);
		int getIdentificador();
};


#endif


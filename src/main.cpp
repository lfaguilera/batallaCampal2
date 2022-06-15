#include "batallaCampal.h"
#include <iostream>
using namespace std;

void jugar(BatallaCampal * juego)
{
	int x,y,z,jugadores,soldados;
	cout<<"Elegir limite X del tablero"<<endl;
	cin>>x;
	cout<<"Elegir limite Y del tablero"<<endl;
	cin>>y;
	cout<<"Elegir limite Z del tablero"<<endl;
	cin>>z;
	cout<<"Elegir cantidad de jugadores"<<endl;
	cin>>jugadores;
  cout<<"Elegir cantidad de soldados por jugador"<<endl;
	cin>>soldados;
	
	BatallaCampal * juegoAux = new BatallaCampal(x,y,z,jugadores,soldados);
	juego = juegoAux;
	juego->setSoldadosInicio();
	juego->jugarBatallaCampal();	
}

int main() {
  BatallaCampal *juego;

  jugar(juego);

  return 0;
}
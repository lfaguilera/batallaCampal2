#include "carta.h"
#include <cstdlib>
#include <iostream>

Carta::Carta()
{
}
void Carta::setTipoCartaAlAzar() {
	//La siguiente l�nea sirve para cambiar la semilla de numeros aleatorios
  //y que de esta forma, cada vez que se ejecuta el programa, arroje diferentes n�meros.
  srand(time(0));
  int numeroEntreUnoYSeis = rand() % (6) + 1;
  switch(numeroEntreUnoYSeis) {
    case 1:
      this->tipo = CARTA_MISIL;
      break;
    case 2:
      this->tipo = CARTA_AVION;
      break;
    case 3:
      this->tipo = CARTA_BARCO;
      break;
    case 4:
      this->tipo = CARTA_LASER;
      break;
    case 5:
      this->tipo = CARTA_DIQUE;
      break;
    case 6:
      this->tipo = CARTA_BOMBARDEO;
      break;
    default:
      this->tipo = CARTA_MISIL;
  }
}
TipoAccion Carta::getTipo() {
  return (this->tipo);
}

int* Carta::pedirCoordenadas(){
  int *coordenadas = new int [3];
  std::cout<<"\nIngrese coordenada X: ";
  std::cin>>coordenadas[0];
  std::cout<<"\nIngrese coordenada Y: ";
  std::cin>>coordenadas[1];
  std::cout<<"\nIngrese coordenada Z: ";
  std::cin>>coordenadas[2];
  return coordenadas;
}

void Carta::jugarMisil(Tablero *tablero){
  std::cout<<"\nCarta Misil. \n";
  int* coordenadas = this->pedirCoordenadas();
  
  for(int i = coordenadas[0]-1; i < coordenadas[0]+1; i++) {
    for(int j = coordenadas[1]-1; j < coordenadas[1]+1; j++) {
      for(int k = coordenadas[2]-1; k < coordenadas[2]+1; k++) {
        tablero->Tablero::encontrarCasilla(i,j,k)->Casilla::setEstadoCasilla(INACTIVA);
      }
    }
  }
  std::cout<<"\nFin jugada carta Misil. \n";
}
void Carta::jugarAvion(Tablero *tablero, Jugador *jugador){
  std::cout<<"\nCarta Bombardeo. \n";
  int *coordenadas = pedirCoordenadas();
  Casilla *casilla;
  casilla = tablero->encontrarCasilla(coordenadas[0],coordenadas[1],coordenadas[2]);
  casilla->setEstadoCasilla(OCUPADA);
  casilla->getFichaCasilla()->setTipo(AVION);
  casilla->getFichaCasilla()->setJugador(jugador);
  std::cout<<"\nFin jugada carta Bombardeo. \n";
}
void Carta::jugarBarco(Tablero *tablero, Jugador *jugador){
  std::cout<<"\nCarta Barco. \n";
  int *coordenadas = pedirCoordenadas();
  Casilla *casilla;
  casilla = tablero->encontrarCasilla(coordenadas[0],coordenadas[1],coordenadas[2]);
  casilla->setEstadoCasilla(OCUPADA);
  casilla->getFichaCasilla()->setTipo(BARCO);
  casilla->getFichaCasilla()->setJugador(jugador);
  std::cout<<"\nFin jugada carta Barco. \n";
}
void Carta::jugarLaser(Tablero *tablero){
  std::cout<<"\nCarta Laser. \n";
  int xIngreso,zIngreso;
  std::cout<<"\nIngrese coordenada X para disparar laser (toda esa columna sera atacada): \n";
  std::cin>>xIngreso;
  std::cout<<"\nIngrese coordenada Z(altura) para disparar laser (toda esa columna sera atacada): \n";
  std::cin>>zIngreso;
	
  int x, y, z;
  tablero->getLimites(x,y,z);
  for(int i=0; i < y; i++) {
	  Casilla *casilla;
	  casilla = tablero->encontrarCasilla(xIngreso,i ,zIngreso);
	  casilla->setEstadoCasilla(INACTIVA);
	  casilla->vaciarCasilla();
  }
  std::cout<<"\nFin jugada carta Laser. \n";
}

void Carta::jugarDique(Tablero *tablero){
  std::cout<<"\nCarta Dique. \n";
  int *coordenadas = pedirCoordenadas();
  Casilla *casilla = tablero->Tablero::encontrarCasilla(coordenadas[0], coordenadas[1], coordenadas[2]);
  if(casilla->getTerrenoCasilla() == AGUA) {
    casilla->setTerrenoCasilla(TIERRA);
  }
  std::cout<<"\nFin jugada carta Dique. \n";
}

void Carta::jugarBombardeo(Tablero *tablero){
  std::cout<<"\nCarta Bombardeo. \n";
  for(int i = 0; i < 3; i++) {
    std::cout<<"\nDisparando bomba #" << i << "\n";
    int* coordenadas = this->pedirCoordenadas();
	Casilla *casilla;
    casilla = tablero->encontrarCasilla(coordenadas[0],coordenadas[1],coordenadas[2]);
	casilla->setEstadoCasilla(INACTIVA);
	casilla->vaciarCasilla();
  }
  std::cout<<"\nFin jugada carta Bombardeo. \n";
}

void Carta::jugarCarta(TipoAccion tipo,Jugador *jugador,Tablero *tablero) {
  switch(tipo) {
    case CARTA_MISIL:
      jugarMisil(tablero);
      break;
    case CARTA_AVION:
      jugarAvion(tablero,jugador);
      break;
    case CARTA_BARCO:
      jugarBarco(tablero,jugador);
      break;
    case CARTA_LASER:
      jugarLaser(tablero);
      break;
    case CARTA_DIQUE:
      jugarDique(tablero);
      break;
    case CARTA_BOMBARDEO:
      jugarBombardeo(tablero);
      break;
  }
}
Carta::~Carta(){}

#include "ficha.h"
#include <cstdlib>
#include <iostream>

Ficha::Ficha(TipoFicha tipoInicial,Jugador *jugadorInicial){
  
  this->ficha=tipoInicial;
  this->jugador=jugadorInicial;
  
  
}
Jugador *Ficha::getJugador(){
  return (this->jugador);
}
void Ficha::setJugador(Jugador * jugadorNew){
  this->jugador=jugadorNew;
}
TipoFicha Ficha::getTipo(){
  return(this->ficha);
}
void Ficha::setTipo(TipoFicha tipo){
  this->ficha=tipo;
}
Ficha::~Ficha(){
  
}

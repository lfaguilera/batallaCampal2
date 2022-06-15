#include "casilla.h"
#include <iostream>

Casilla::Casilla(int posicionX, int posicionY, int posicionZ,EstadoDeCasilla estadoInicio, TipoDeTerreno terrenoInicial)
{
	this->x = posicionX;
	this->y = posicionY;
	this->z = posicionZ;
	this->estado = estadoInicio;
	this->terreno = terrenoInicial;
	this->fichaCasilla = NULL;
}
Casilla::~Casilla()
{
	
}
void Casilla::getPosicionCasilla(int &posixionX,int &posicionY, int &posicionZ)
{
	posixionX = this->x;
	posicionY = this->y;
	posicionZ = this->z;
}
EstadoDeCasilla Casilla::getEstadoCasilla()
{
	return (this->estado);
}
void Casilla::setEstadoCasilla(EstadoDeCasilla estadoNuevo)
{
	this->estado = estadoNuevo;
}
Ficha* Casilla::getFichaCasilla()
{
	return (this->fichaCasilla);
}
void Casilla::setFicha(Ficha *ficha)
{
	(this->fichaCasilla = ficha);
}
void Casilla::vaciarCasilla()
{
	delete fichaCasilla;
	this->fichaCasilla = NULL;
}
TipoDeTerreno Casilla::getTerrenoCasilla()
{
	return (this->terreno);
}
void Casilla::setTerrenoCasilla(TipoDeTerreno nuevoTipoDeTerreno)
{
  this->terreno = nuevoTipoDeTerreno;
}

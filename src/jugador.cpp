#include "jugador.h"
#include <iostream>

Jugador::Jugador(int soldadosInicial,int identificadorNuevo)
{
	this->vivo=true;
	this->soldadosRestantes = soldadosInicial;
	this->identificador = identificadorNuevo;
}
Jugador::~Jugador()
{
}
int Jugador::getSoldadosRestantes()
{
	return (this->soldadosRestantes);
}
void Jugador::setSoldadosRestantes(int soldados)
{
	this->soldadosRestantes = this->soldadosRestantes + soldados;
}
bool Jugador::getJugadorVivo()
{
	return (this->vivo);
}
void Jugador::setJugadorVivo(bool estado)
{
	this->vivo = estado;
}
int Jugador::getIdentificador()
{
	return this->identificador;
}


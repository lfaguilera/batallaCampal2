#include "batallaCampal.h"
#include "lista.cpp"
#include <iostream>
#include <cstdlib>

using namespace std;

BatallaCampal::BatallaCampal(int x, int y ,int z, int cantJugadores,int cantSoldados)
{
	int n = 1;
	this->jugadores = new Lista<Jugador*>;
	while(n<=cantJugadores)
		{
			Jugador * jugador = new Jugador(cantSoldados,n);
			this->jugadores->add(jugador,n);
			n++;
		}
	this->tableroJuego = new Tablero(x,y,z);
	this->cantidadJugadores = cantJugadores;
	this->jugadoresRestantes = cantJugadores;
}

BatallaCampal::~BatallaCampal()
{
	this->jugadores->reiniciarCursor();
	while(this->jugadores->avanzarCursor())
		{
			delete this->jugadores->getCursor();
		}
	this->tableroJuego->~Tablero();
}

void BatallaCampal::setSoldadosInicio()
{
	int x,y,z;
	int maxPosX,maxPosY,maxPosZ;
	Jugador *jugador;
	Casilla *casilla;

	this->tableroJuego->getLimites(maxPosX,maxPosY,maxPosZ);
	
	this->jugadores->reiniciarCursor();
	while(this->jugadores->avanzarCursor())
	{
		jugador = this->jugadores->getCursor();
		for(int i=1;i<=jugador->getSoldadosRestantes();i++)
		{
			x=1 + rand() % maxPosX;
			y=1 + rand() % maxPosY;
			z=1 + rand() % maxPosZ;
			casilla = this->tableroJuego->encontrarCasilla(x,y,z);
			casilla->setEstadoCasilla(OCUPADA);
			Ficha *ficha = new Ficha(SOLDADO,jugador);
			casilla->setFicha(ficha);
		}	
	}
}
void BatallaCampal::jugarBatallaCampal()
{
	Jugador *jugador;
	
	this->jugadores->reiniciarCursor();
	while(this->jugadoresRestantes > 1)
		{
			while(this->jugadores->avanzarCursor())
			{
				jugador = this->jugadores->getCursor();
				if(jugador->getJugadorVivo() == true)
				{
					this->tableroJuego->emitirConsola();
					this->atacar(jugador);
					this->tableroJuego->emitirConsola();
					this->moverFicha(jugador);
					this->tableroJuego->emitirConsola();
					this->jugarCarta(jugador);
					this->tableroJuego->emitirConsola();
					this->setJugadorVivo(jugador);
					this->tableroJuego->emitirConsola();
				}
			}
			this->jugadores->reiniciarCursor();
		}
}
void BatallaCampal::atacar(Jugador *jugador)//NICE
{
  //precondicion : el jugador va a atacar dentro del tablero ni se va a atacar a si mismo
	int x,y,z;
	Jugador *jugadorAtacado;
	Casilla *casilla;
	
	
	//mensaje para seleccionar casilla
	cout<<"Seleccione eje x del casillero para atacar"<<endl;
	cin>>x;
	cout<<"Seleccione eje y del casillero para atacar"<<endl;
	cin>>y;
	cout<<"Seleccione eje z del casillero para atacar"<<endl;
	cin>>z;

	/*comprobar casilla es valida para jugar
		(que este dentro del casillero, que no sea una casilla propia)
	*/
	while(!this->posicionesAtaqueCorrecta(jugador,x,y,z))
		{
			cout<<"Seleccione eje x casillero para atacar valido"<<endl;
			cin>>x;
			cout<<"Seleccione eje y casillero para atacar valido"<<endl;
			cin>>y;
			cout<<"Seleccione eje z casillero para atacar valido"<<endl;
			cin>>z;
		}
	/*
	ELIMINAR SOLDADO ENEMIGO SI LO HABIA*/
	
    casilla = this->tableroJuego->encontrarCasilla(x,y,z);
    if   (casilla->getEstadoCasilla() == OCUPADA)
	{
		jugadorAtacado = casilla->getFichaCasilla()->getJugador();
		jugadorAtacado->setSoldadosRestantes(-1);
    	casilla->vaciarCasilla();
    }
	else
	{
      cout<<"No habia objetivos en las coordenadas"<<endl;
    }
    casilla->setEstadoCasilla(INACTIVA);

}

void BatallaCampal::moverFicha(Jugador *jugador)//NICE
{
	Casilla *actual, *nueva; 
	int xAnterior,yAnterior,zAnterior,xNuevo,yNuevo,zNuevo;
	Jugador *jugadorAtacado;
	
	//mensaje para seleccionar casilla de soldado a mover
	cout<<"Seleccione el casillero de la ficha que desea mover en el eje x"<<endl;
	cin>>xAnterior;
	cout<<"Seleccione el casillero de la ficha que desea mover en el eje y"<<endl;
	cin>>yAnterior;
	cout<<"Seleccione el casillero de la ficha que desea mover en el eje z"<<endl;
	cin>>zAnterior;

	/*comprobar casilla es valida para jugar
		(que este dentro del casillero, que haya un soldado de su jugador)
	*/
  
	while(!(this->posicionSoldadoCorrecta(jugador,xAnterior,yAnterior,zAnterior)) == false)
		{
			cout<<"Ingreso un casillero incorrecto"<<endl;
			cout<<"Seleccione el casillero de la ficha que desea mover en el eje x"<<endl;
			cin>>xAnterior;
			cout<<"Seleccione el casillero de la ficha que desea mover en el eje x"<<endl;
			cin>>yAnterior;
			cout<<"Seleccione el casillero de la ficha que desea mover en el eje x"<<endl;
			cin>>zAnterior;
		}
  actual = this->tableroJuego->encontrarCasilla(xAnterior,yAnterior,zAnterior);

	//mensaje para que seleccione casilla donde mover el soldado
	cout<<"Seleccione el casillero nuevo del soldado que desea mover, en el eje x"<<endl;
	cin>>xNuevo;
	cout<<"Seleccione el casillero nuevo del soldado que desea mover, en el eje y"<<endl;
	cin>>yNuevo;
	cout<<"Seleccione el casillero nuevo del soldado que desea mover, en el eje z"<<endl;
	cin>>zNuevo;

 while((this->tableroJuego->encontrarCasilla(xNuevo,yNuevo,zNuevo)->getEstadoCasilla() == INACTIVA))
	//while(!(this->posicionAMoverSoldadoCorrecta(xAnterior,yAnterior,zAnterior,xNuevo,yNuevo,zNuevo)))//revisar nombre
		{
			cout<<"Selecciono un casillero fuera de rango"<<endl;
			cout<<"Seleccione el casillero nuevo de la ficha que desea mover, en el eje x"<<endl;
			cin>>xNuevo;
			cout<<"Seleccione el casillero nuevo de la ficha que desea mover, en el eje y"<<endl;
			cin>>yNuevo;
			cout<<"Seleccione el casillero nuevo de la ficha que desea mover, en el eje z"<<endl;
			cin>>zNuevo;		
		}
  
    nueva = this->tableroJuego->encontrarCasilla(xNuevo,yNuevo,zNuevo);
    
	  if (nueva->getEstadoCasilla() == OCUPADA)
	  {
		nueva->setEstadoCasilla(INACTIVA);
		jugadorAtacado = nueva->getFichaCasilla()->getJugador();
		jugadorAtacado->setSoldadosRestantes(-1);
		 
    	actual->setEstadoCasilla(VACIA);
    	jugador = actual->getFichaCasilla()->getJugador();
    	jugador->setSoldadosRestantes(-1);
    	actual->vaciarCasilla();
    }
	else 
	{
      nueva->setEstadoCasilla(OCUPADA);
	    Ficha * ficha = actual->getFichaCasilla();
      nueva->setFicha(ficha);
    
      actual->setEstadoCasilla(VACIA);
      actual->vaciarCasilla();
    }
			
}

void BatallaCampal::jugarCarta(Jugador *jugador)
{
	Carta *cartaEnJuego = new Carta;
	cartaEnJuego->setTipoCartaAlAzar();
	TipoAccion accionCarta = cartaEnJuego->getTipo();

	cartaEnJuego->jugarCarta(accionCarta,jugador,this->tableroJuego);
	
}

bool BatallaCampal::posicionesAtaqueCorrecta(Jugador *jugador,int x,int y,int z)//NICE
{
	//x,y,z tienen que estar dentro de los limites del tablero y que no sea del propio jugador
	int limiteX,limiteY,limiteZ;
	this->tableroJuego->getLimites(limiteX,limiteY,limiteZ);
  
	if((x<=limiteX && x >= 1) && (y<=limiteY && y>=1) && (z<=limiteZ && z>=1))
	{
    Casilla* casilla= this->tableroJuego->encontrarCasilla(x,y,z);

    	Ficha *ficha = casilla->getFichaCasilla();
		if(ficha !=NULL)
		{
			Jugador *jugadorAux = casilla->getFichaCasilla()->getJugador();
			if((casilla->getEstadoCasilla() == OCUPADA)&&(!(jugador == jugadorAux)))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		} 
	}
    
	else
	{
		return false;
	} 
}

bool BatallaCampal::posicionSoldadoCorrecta(Jugador *jugador,int x,int y,int z)//NICE
{
	//dentro de los limites del tablero, tengo que tener soldado
	int limiteX,limiteY,limiteZ;
	this->tableroJuego->getLimites(limiteX,limiteY,limiteZ);
	if((x<limiteX && x >= 0) && (y<limiteY && y>=0) && (z<limiteZ && z>=0))
	{
	Casilla* casilla= this->tableroJuego->encontrarCasilla(x,y,z);
		Ficha *ficha = casilla->getFichaCasilla();
		if(ficha !=NULL)
		{
			Jugador *jugadorAux = casilla->getFichaCasilla()->getJugador();
			if(jugador == jugadorAux)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
    
	}
	else
	{
		return false;
	} 
	
}
bool BatallaCampal::posicionAMoverSoldadoCorrecta(int xAnterior, int yAnterior, int zAnterior, int xNuevo, int yNuevo, int zNuevo)
{
	//dentro de los limites del tablero, y que es un movimiento posible
	int limiteX,limiteY,limiteZ;
	this->tableroJuego->getLimites(limiteX,limiteY,limiteZ);
	if((xNuevo<limiteX && xNuevo >= 0) && (yNuevo<limiteY && yNuevo>=0) && (zNuevo<limiteZ && zNuevo>=0))
	{
		if(  (  (xAnterior-xNuevo)*(xAnterior-xNuevo)  )+(  (yAnterior-yNuevo)*(yAnterior-yNuevo)  )+(  (zAnterior-zNuevo)*(zAnterior-zNuevo)  )  <=1)
      //La funcion maestra  
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	} 
}
void BatallaCampal::setJugadorVivo(Jugador *jugador)
{
	if(jugador->getSoldadosRestantes() == 0)
	{
		jugador->setJugadorVivo(false);
		(this->jugadoresRestantes) --;
	}
}


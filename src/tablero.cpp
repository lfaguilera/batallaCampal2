#include "tablero.h"
#include "lista.cpp"
#include <iostream>

Tablero::Tablero(int x, int y, int z)
{
	if(x > 0 && y >0 && z > 0)
	{
		int i,j,k;

		limiteX = x;
		limiteY = y;
		limiteZ = z;

		this->tableroJuego = new Lista<Lista<Lista<Casilla*>*>*>();
			
		for(i=1;i<=this->limiteX;i++)
		{
			Lista<Lista<Casilla*>*> *listaEnY = new Lista<Lista<Casilla*>*>;
			for(j=1;j<=this->limiteY;j++)
			{
				Lista<Casilla*> *listaEnZ = new Lista<Casilla*>;
				for(k=1;k<=this->limiteZ;k++)
				{
					if(k == 1)
					{
						Casilla *casillero = new Casilla(i,j,k,VACIA,AGUA);
						listaEnZ->add(casillero,k);
					}
					else
					{
						Casilla *casillero = new Casilla(i,j,k,VACIA,AIRE);
						listaEnZ->add(casillero,k);
					}
				}
				listaEnY->add(listaEnZ,j);
			}
			this->tableroJuego->add(listaEnY,i);
		}
	}
}
Tablero::~Tablero()
{
	
}
void Tablero::getLimites(int &limiteEnX,int &limiteEnY,int &limiteEnZ)
{
	limiteEnX = this->limiteX;
	limiteEnY = this->limiteY;
	limiteEnZ = this->limiteZ;
}
Casilla* Tablero::encontrarCasilla(int x, int y, int z)
{
	int cont = 1;
	Lista<Lista<Casilla*>*>  *listaEnY;
	Lista<Casilla*> *listaEnZ;

	this->tableroJuego->reiniciarCursor();
	this->tableroJuego->avanzarCursor();
	while(cont != x){
			this->tableroJuego->avanzarCursor();
		cont++;
	}
	listaEnY = this->tableroJuego->getCursor();
	
	listaEnY->reiniciarCursor();
	listaEnY->avanzarCursor();
	cont = 1;
	while(cont != y){
		listaEnY->avanzarCursor();
	cont++;
	}
	listaEnZ = listaEnY->getCursor();

	listaEnZ->reiniciarCursor();
	listaEnZ->avanzarCursor();
	cont = 1;
	while(cont != z){
		listaEnZ->avanzarCursor();
		cont++;
	}
	
	return listaEnZ->getCursor();
}
void Tablero::exportarTablero()
{
	
}
void Tablero::emitirConsola()
{
	Casilla * casillero;
  
	for(int i=1;i<=this->limiteZ;i++)
		{
			std::cout<<"Region Z = "<<i<<std::endl;//modificado
			std::cout<<"Y"<<std::endl;
			for(int j=1;j<=this->limiteY;j++)
				{  std::cout<<j<<" |";//agregado
					for(int k=1;k<=this->limiteX;k++)
						{  //std::cout<<k<<" ";//agregado
							casillero = this->encontrarCasilla(k,j,i);
							if(casillero->getEstadoCasilla() == OCUPADA)
							{
								Ficha *ficha =casillero->getFichaCasilla();
								int identificador =ficha->getJugador()->getIdentificador();
								std::cout<<identificador<<"|";
							}
							else if(casillero->getEstadoCasilla()==INACTIVA)
							{
								std::cout<<"X"<<"|";
							}
							else if(casillero->getEstadoCasilla()==VACIA)
							{
								std::cout<<" "<<"|";
							}
						}
					std::cout<<std::endl;
				}
			//std::cout<<std::endl<<std::endl;
      std::cout<<"   ";
      for(int k=1;k<=this->limiteX;k++){
        std::cout<<k<<" ";
      }
      std::cout<<" X"<<std::endl;
      std::cout<<std::endl<<std::endl;
		}
}
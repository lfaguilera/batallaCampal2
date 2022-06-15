#ifndef LISTA_H_
#define LISTA_H_

#ifndef NULL
#define NULL 0
#endif /* NULL */

#include "nodo.h"

template<class T> class Lista{
private:
	Nodo<T>* primero;
	unsigned int tamanio;
	Nodo<T>* cursor;
public:
	Lista();
	Lista(Lista<T> &otraLista);
	bool vacia()const;
	unsigned int contarElementos()const;
	void add(T elemento);
	void add(T elemento, unsigned int posicion);
	void add(Lista<T> &otraLista);
	T get(unsigned int posicion);
	void asignar(T elemento, unsigned int posicion);
	void remover(unsigned int posicion);
	void reiniciarCursor();
	bool avanzarCursor();
	T getCursor()const;
	~Lista();
private:
	Nodo<T>* getNodo(unsigned int posicion)const;
};

#endif
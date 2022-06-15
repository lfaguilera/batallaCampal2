#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif /* NULL */

template<class T> class Nodo{
private:
	T dato;
	Nodo<T>* siguiente;
public:
	Nodo(T valor);
	bool haySiguiente();
	Nodo<T>* getSiguiente();
	void setSiguiente(Nodo<T>* nuevoSig);
	T getValor();
	void setValor(T nuevoValor);
	~Nodo();
};

#endif
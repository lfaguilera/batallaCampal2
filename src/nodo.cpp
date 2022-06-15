#include "nodo.h"
#include <iostream>

template<class T> Nodo<T>::Nodo(T valor){
	this->dato = valor;
	this->siguiente = NULL;
}

template<class T> bool Nodo<T>::haySiguiente(){
	return (this->siguiente != NULL);
}

template<class T> Nodo<T>* Nodo<T>::getSiguiente(){
	return (this->siguiente);
}

template<class T> void Nodo<T>::setSiguiente(Nodo<T>* nuevoSig){
	this->siguiente = nuevoSig;
}

template<class T> T Nodo<T>::getValor(){
	return (this->dato);
}

template<class T> void Nodo<T>::setValor(T nuevoValor){
	this->dato = nuevoValor;
}

template<class T> Nodo<T>::~Nodo(){

}

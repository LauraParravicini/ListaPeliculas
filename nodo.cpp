#include "nodo.h"
#include "pelicula.h"

template class Nodo<std::string>;
template class Nodo<Pelicula>;


template<typename Tipo>
Nodo<Tipo>::Nodo(){
    asignar_siguiente(NULL);
}

template<typename Tipo>
Nodo<Tipo>::Nodo(Tipo dato){
    this->dato = dato;
    asignar_siguiente(NULL);
}

template<typename Tipo>
void Nodo<Tipo>::asignar_dato(Tipo dato){
    this->dato = dato;
}

template<typename Tipo>
Tipo Nodo<Tipo>::obtener_dato(){
    return dato;
}

template<typename Tipo>
void Nodo<Tipo>::asignar_siguiente(Nodo* siguiente){
    this->siguiente = siguiente;
}

template<typename Tipo>
Nodo<Tipo>* Nodo<Tipo>::obtener_siguiente(){
    return siguiente;
}

#ifndef LISTA_H
#define LISTA_H

#include "pelicula.h"
#include "nodo.h"

template<typename Tipo>
class Lista{
  //Atributos
  private:
    Nodo<Tipo>* primero;
    unsigned int tam;

  //Métodos
  public:
    //Cosntructor
    Lista();

    //Lista está vacía
    //Post: Función que devuelve un dato booleano verificando si la lista está vacía o no
    bool esta_vacia();

    //Agregar dato
    //Descripción: Procedimiento que recibe una dirección de memoria de un dato y la agrega a la lista
    //Pre: Procedimiento que recibe un puntero a un dato
    //Post: Agrega el dato a la lista
    void agregar_dato(Tipo* dato);

    //Eliminar un dato
    //Descripción: Procedimiento que elimina el primer dato de la lista
    //Post: El primer dato es eliminado de la lista
    void eliminar_dato();

    //Destructor
    ~Lista();
};

template class Lista<std::string>;
template class Lista<std::string*>;
template class Lista<Pelicula>;
template class Lista<Pelicula*>;

#endif

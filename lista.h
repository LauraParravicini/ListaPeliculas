#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

const int INICIO = 1;

template<typename Tipo>
class Lista{
  //Atributos
  private:
    Nodo<Tipo>* primero;
    Nodo<Tipo>* ultimo;
    int tam;

  //Métodos
  public:
    //Cosntructor
    Lista();

    //Lista está vacía
    //Post: Función que devuelve un dato booleano verificando si la lista está vacía o no
    bool esta_vacia();

    Nodo<Tipo>* obtener_primero();

    Nodo<Tipo>* obtener_ultimo();

    //Obtener tamaño
    //Post: Devuelve el valor del atributo tam de la clase
    int obtener_tam();

    //Agregar dato
    //Descripción: Procedimiento que recibe una dirección de memoria de un dato y la agrega a la lista
    //Pre: Procedimiento que recibe un puntero a un dato
    //Post: Agrega el dato a la lista
    void agregar_dato(Tipo dato);

    //Obtener dato
    //Descripción: Función que recibe un valor representativo a una posición menor o igual que el tamaño de la lista y devuelve el dato alojado en
    //             dicha posición
    //Pre: Función que recibe un entero representativo a una posición de la lista (posicion <= tam)
    //Post: Devuelve el dato alojado en el nodo de dicha posición recibida
    Tipo obtener_dato(int posicion);

    //Eliminar un dato
    //Descripción: Procedimiento que elimina el primer dato de la lista
    //Post: El primer dato es eliminado de la lista
    void eliminar_dato();

    void copiar(Lista<Tipo> lista);

    //Destructor
    //~Lista();

    //Liberar memoria (reemplazo de destructor)
    void liberar();
};

#endif

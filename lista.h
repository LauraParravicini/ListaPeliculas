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

    //Obtener primer elemento
    //Post: Devuelve un puntero a la direccion del primer nodo de la lista
    Nodo<Tipo>* obtener_primero();

    //Obtener ultimo elemento
    //Post: Devuelve un puntero a la direccion del ultimo nodo de la lista
    Nodo<Tipo>* obtener_ultimo();

    //Obtener tamaño
    //Post: Devuelve el valor del atributo tam de la clase
    int obtener_tam();

    //Agregar dato
    //Descripción: Procedimiento que recibe un dato y la agrega a la lista
    //Pre: Procedimiento que recibe un dato
    //Post: Agrega el dato a la lista
    void agregar_dato(Tipo dato);

    //Obtener dato
    //Descripción: Metodo que recibe un valor representativo a una posición menor o igual
    //             que el tamaño de la lista y mayor a 0, devolviendo el dato alojado en dicha posición
    //Pre: Función que recibe un entero representativo a una posición de la lista (posicion <= tam y posicion > 0)
    //Post: Devuelve el dato alojado en el nodo de dicha posición recibida
    Tipo obtener_dato(int posicion);

    //Eliminar un dato
    //Descripción: Procedimiento que elimina el primer dato de la lista
    //Post: El primer dato es eliminado de la lista
    void eliminar_dato();

    //Copiar lista
    //Descripcion: Metodo que recibe una lista para copiar sus elementos para si misma.
    //Post: Guarda en la lista los elementos de la lista parametro recibida
    void copiar(Lista<Tipo> lista);

    //Liberar memoria
    void liberar();
};

#endif

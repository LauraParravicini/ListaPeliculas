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
    //Constructor
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
    //Descripción: Procedimiento que recibe una dirección de memoria de un dato y lo agrega a la lista
    //Pre: Procedimiento que recibe una dirección de memoria de un dato
    //Post: Agrega el dato a la lista
    void agregar_dato(Tipo* dato);

    //Obtener dato
    //Descripción: Metodo que recibe un valor representativo a una posición menor o igual que el tamaño de la lista y mayor a 0, devolviendo la
    //             dirección de memoria del dato alojado en dicha posición
    //Pre: Función que recibe un entero representativo a una posición de la lista (posicion <= tam y posicion > 0)
    //Post: Devuelve la dirección de memoria del dato alojado en el nodo de dicha posición recibida
    Tipo* obtener_dato(int posicion);

    //Eliminar un dato
    //Descripción: Procedimiento que elimina el primer dato de la lista
    //Post: El primer dato es eliminado de la lista
    void eliminar_dato();

    //Copiar lista
    //Descripcion: Método que recibe dos direcciones de memoria de listas y guarda los elementos de la segunda lista recibida en la primera
    //Pre: Método que recibe dos direcciones de memoria de listas
    //Post: Guarda los elementos de la segunda lista recibida en la primera
    void copiar(Lista<Tipo>* copia, Lista<Tipo>* original);

    //Destructor
    ~Lista();
};

#endif

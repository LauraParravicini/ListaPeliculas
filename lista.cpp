#include "lista.h"
#include "pelicula.h"

template class Lista<std::string>;
template class Lista<Pelicula>;

template<typename Tipo>
Lista<Tipo>::Lista(){
  primero = NULL;
  ultimo = NULL;
  tam = 0;
}

template<typename Tipo>
bool Lista<Tipo>::esta_vacia(){
    return !tam;
}

template<typename Tipo>
Nodo<Tipo>* Lista<Tipo>::obtener_primero(){
    return primero;
}

template<typename Tipo>
Nodo<Tipo>* Lista<Tipo>::obtener_ultimo(){
    return ultimo;
}

template<typename Tipo>
int Lista<Tipo>::obtener_tam(){
  return tam;
}

template<typename Tipo>
void Lista<Tipo>::agregar_dato(Tipo dato){
    Nodo<Tipo>* nuevo = new Nodo<Tipo>;
    nuevo->asignar_dato(dato);

    if(esta_vacia() )
        primero = nuevo;
    else
        ultimo->asignar_siguiente(nuevo);

    ultimo = nuevo;
    tam++;
}

template<typename Tipo>
Tipo Lista<Tipo>::obtener_dato(int posicion){
  int contador = INICIO;
  Nodo<Tipo>* aux = primero;
  Tipo dato;

  while(contador <= tam){
    if(posicion == contador){
      dato = aux->obtener_dato();
      contador = tam+1;
    }
    else{
      aux = aux->obtener_siguiente();
      contador++;
    }
  }
  return dato;
}

template<typename Tipo>
void Lista<Tipo>::eliminar_dato(){
    Nodo<Tipo>* aux = primero;
    primero = aux->obtener_siguiente();
    delete aux;
    tam--;
}

template<typename Tipo>
void Lista<Tipo>::liberar(){
    while(!esta_vacia() ){
        eliminar_dato();
    }
}

template<typename Tipo>
void Lista<Tipo>::copiar(Lista<Tipo> lista){
  primero = lista.obtener_primero();
  ultimo = lista.obtener_ultimo();
  tam = lista.obtener_tam();
}

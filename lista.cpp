#include "lista.h"

template<typename Tipo>
Lista<Tipo>::Lista(){
  primero = NULL;
  tam = 0;
}

template<typename Tipo>
bool Lista<Tipo>::esta_vacia(){
    return !tam;
}

template<typename Tipo>
void Lista<Tipo>::agregar_dato(Tipo* dato){
    Nodo<Tipo>* nuevo = new Nodo<Tipo>(dato);

    if(esta_vacia() )
        primero = nuevo;
    else{
        primero->asignar_siguiente(nuevo);
    }

    tam++;
}

template<typename Tipo>
void Lista<Tipo>::eliminar_dato(){
    Nodo<Tipo>* aux = primero;
    primero = aux->obtener_siguiente();
    delete aux;
    tam--;
}

template<typename Tipo>
Lista<Tipo>::~Lista(){
    while(!esta_vacia())
        eliminar_dato();
}

template<typename Tipo>
Nodo<Tipo>* Lista<Tipo>::obtener_nodo(unsigned pos){
    Nodo<Tipo>* aux = primero;
    unsigned i = 1;
    while (i < pos) {
        aux = aux->obtener_siguiente();
        i++;
    }
    return aux;
}

template<typename Tipo>
Tipo* Lista<Tipo>::obtener_dato(unsigned pos){
    Nodo<Tipo>* paux = obtener_nodo(pos);
    return paux->obtener_dato();
}
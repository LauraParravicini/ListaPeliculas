#ifndef _NODO_H_
#define _NODO_H_

template<typename Tipo>
class Nodo{
    //Atributos
    private:
        Tipo* dato;
        Nodo* siguiente;

    //Métodos
    public:
        //Constructor
        Nodo();

        //Constructor con parametros
        Nodo(Tipo* dato);

        //Asignar dato
        //Descripción: Procedimiento que recibe una dirección de memoria a un dato y lo asigna al atributo dato de la clase
        //Pre: Procedimiento que recibe una dirección de memoria a un dato
        //Post: Asigna el dato recibido al atributo dato de la clase
        void asignar_dato(Tipo* dato);

        //Obtener dato
        //Post: Devuelve la dirección de memoria de un dato que guarda dicho nodo
        Tipo* obtener_dato();

        //Asignar siguente
        //Descripción: Procedimiento que recibe la dirección de memoria de un nodo y la asigna al atributo siguiente de la clase
        //Pre: Procedimiento que recibe un puntero a un objeto de clase Nodo
        //Post: Asigna el puntero recibido al atributo siguiente de la clase
        void asignar_siguiente(Nodo* siguiente);

        //Obtener siguiente
        //Post: Devuelve un puntero con la dirección de memoria del siguente nodo
        Nodo* obtener_siguiente();

        ~Nodo();
};

#endif

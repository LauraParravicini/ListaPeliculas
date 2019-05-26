#ifndef MENU_H
#define MENU_H

#include "pelicula.h"
const int MAX_OPCIONES = 4;

class Menu{
  //Métodos
  public:
    //Constructor
    Menu();

    //Inicializar menu
    //Descripción: Procedimiento que recibe las listas de peliculas vistas y no vistas por el usuario. Además muestra por pantalla las
    //             opciones del menu, pide al usuario que ingrese una opción y la ejecuta
    //Pre: Procedimiento que recibe dos objetos de clase Carga_listas y dos de clase Lista
    //Post: Muestra por pantalla las opciones del menu, pide al usuario que ingrese una opción y la ejecuta
    void inicializar(std::list<Pelicula> lista_peliculas_vistas, std::list<Pelicula> lista_peliculas_no_vistas);

    private:
    //Mostrar listas de peliculas
		//Descripción: Procedimiento que recibe una lista de peliculas y las muestra por pantalla
    //Pre: Procedimiento que recibe objeto de clase Lista
    //Post: Muestra por pantalla los contenido en la lista pasada por parametro
    void mostrar_peliculas(std::list<Pelicula> g);

    //Generar recomendaciones de peliculas
		//Descripción: Función que recibe listas de peliculas vistas y no vistas y devuelve una tercera con las recomendadas
		//Pre: Función que recibe objetos de clase Lista
		//Post: Devuelve un objeto de clase Lista
		std::list<Pelicula> generar_recomendaciones(std::list<Pelicula> vistas, std::list<Pelicula> no_vistas);

    //Mostrar menu
    //Post: Imprime por pantalla las opciones del menu
    void mostrar();

    //Ejecutar opcion
    //Descripción: Procedimiento que recibe un valor representativo a la opción elegida por el usuario y las listas de peliculas vistas y no vistas por el
    //             usuario. Ejecuta la opción recibida
    //Pre: Procedimiento que recibe un entero representativo a la opción, dos de clase Carga_listas y dos de clase Lista
    //Post: Ejecuta la opción recibida
    void ejecutar_opcion(int opcion, std::list<Pelicula> lista_peliculas_vistas, std::list<Pelicula> lista_peliculas_no_vistas);
};

#endif

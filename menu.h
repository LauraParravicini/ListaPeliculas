#ifndef MENU_H
#define MENU_H

#include "carga_listas.h"

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
    void inicializar(Carga_listas lista_vistas, Lista<Pelicula> lista_peliculas_vistas, Carga_listas lista_no_vistas, Lista<Pelicula> lista_peliculas_no_vistas);

    //Generar recomendaciones de peliculas
	//Descripción: Metodo que recibe listas de peliculas vistas y no vistas y devuelve una tercera con las recomendadas
	//Pre: Metodo que recibe objetos de clase Lista
	//Post: Devuelve un objeto de clase Lista
	Lista<Pelicula> generar_recomendaciones(Lista<Pelicula> vistas, Lista<Pelicula> no_vistas);

    //Mostrar menu
    //Post: Imprime por pantalla las opciones del menu
    void mostrar();

    //Ejecutar opcion
    //Descripción: Procedimiento que recibe un valor representativo a la opción elegida por el usuario y las listas de peliculas vistas y no vistas por el
    //             usuario. Ejecuta la opción recibida
    //Pre: Procedimiento que recibe un entero representativo a la opción, dos de clase Carga_listas y dos de clase Lista
    //Post: Ejecuta la opción recibida
    void ejecutar_opcion(int opcion, Carga_listas lista_vistas, Lista<Pelicula> lista_peliculas_vistas, Carga_listas lista_no_vistas, Lista<Pelicula> lista_peliculas_no_vistas);
};

#endif

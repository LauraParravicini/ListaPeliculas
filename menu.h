#ifndef MENU_H
#define MENU_H

#include <fstream>
#include "lista.h"
#include "pelicula.h"

const int MAX_OPCIONES = 4;
const std::string RUTA_VISTAS = "películas_vistas.txt";
const std::string RUTA_NO_VISTAS = "películas_no_vistas.txt";
const std::string VACIO = "                                        ";

class Menu{
  //Métodos
  public:
    //Constructor
    Menu();

    //Inicializar menu
    //Descripción: Procedimiento que recibe las listas de peliculas vistas y no vistas por el usuario. Además muestra por pantalla las
    //             opciones del menu, pide al usuario que ingrese una opción y la ejecuta
    //Pre: Procedimiento que recibe dos objetos de clase Lista de objetos Pelicula
    //Post: Muestra por pantalla las opciones del menu, pide al usuario que ingrese una opción y la ejecuta
    void inicializar(Lista<Pelicula> vistas, Lista<Pelicula> no_vistas);

    //Generar recomendaciones de peliculas
	  //Descripción: Metodo que recibe listas de peliculas vistas y no vistas y devuelve una tercera con las recomendadas
	  //Pre: Metodo que recibe objetos de clase Lista de objetos Pelicula
	  //Post: Devuelve un objeto de clase Lista de objetos Pelicula
	  Lista<Pelicula> generar_recomendaciones(Lista<Pelicula> vistas, Lista<Pelicula> no_vistas);

    //Mostrar menu
    //Post: Imprime por pantalla las opciones del menu
    void mostrar();

    //Ejecutar opcion
    //Descripción: Procedimiento que recibe un valor representativo a la opción elegida por el usuario y las listas de peliculas vistas y no vistas por el
    //             usuario. Ejecuta la opción recibida
    //Pre: Procedimiento que recibe un entero representativo a la opción y dos objetos de clase Lista de objetos Pelicula
    //Post: Ejecuta la opción recibida
    void ejecutar_opcion(int opcion, Lista<Pelicula> vistas, Lista<Pelicula> no_vistas);

		//Cargar lista
    //Descripción: Procedimiento que recibe la ruta de un archivo de peliculas y una lista vacia y carga las peliculas encontradas en el archivo
    //             en la lista
    //Pre: Procedimiento que recibe una ruta de un archivo que contiene peliculas y un objeto de clase Lista de objetos Pelicula
    //Post: Carga las peliculas encontradas en el archivo en la el objeto recibido
    void cargar_listas(std::string ruta, Lista<Pelicula> &lista_peliculas);

		//Imprimir lista
		//Descripción: Procedimiento que recibe una lista de peliculas e imprime por pantalla los datos dentro de la misma
		//Pre: Procedimiento que recibe un objeto de clase Lista de objetos Pelicula
		//Post: Imprime por pantalla los datos dentro del objeto clase Lista
		void imprimir_lista(Lista<Pelicula> lista_peliculas);

		//Separar actores
		//Descripción: Procedimiento que recibe en una cadena de caracter todos los nombres de los actores de una pelicula y una lista, y separa los
		//             nombres de la cadena y los guarda en la lista recibida
		//Pre: Procedimiento que recibe una cadena de caracteres con todos los nombres de los actores y un objeto de clase lista
		//Post: Separa los nombres de la cadena y los guarda en el objeto clase lista recibido
		void separar_actores(std::string actores, Lista<std::string> &lista_actores);

		//Liberar memoria de la lista
		//Descripción: Procedimiento que recibe una dirección de memoria de una lista de peliculas y libera la memoria dinámica de dicha lista
		//Pre: Procedimiento que recibe una dirección de memoria a un objeto de clase Lista de objetos Pelicula
		//Post: Libera la memoria dinámica de la lista
		void liberar_lista(Lista<Pelicula>* lista_peliculas);
};

#endif

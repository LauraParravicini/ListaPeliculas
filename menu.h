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
    //Descripción: Procedimiento que recibe las listas de peliculas vistas, no vistas por el usuario, y una tercera vacía para llenar con las
    //             recomendaciones. Además muestra por pantalla las opciones del menu, pide al usuario que ingrese una opción y la ejecuta
    //Pre: Procedimiento que recibe tres direcciones de memoria de objetos de clase Lista de objetos Pelicula
    //Post: Muestra por pantalla las opciones del menu, pide al usuario que ingrese una opción y la ejecuta
    void inicializar(Lista<Pelicula>* vistas, Lista<Pelicula>* no_vistas, Lista<Pelicula>* recomendadas);

    //Generar recomendaciones de peliculas
	  //Descripción: Metodo que recibe tres direcciones de memoria de listas de peliculas vistas, no vistas y recomendadas, y aloja a la tercera las
    //             peliculas recomendadas
	  //Pre: Metodo que recibe tres direcciones de memoria de objetos de clase Lista de objetos Pelicula
	  //Post: Guarda los objetos de clase Peliculas que se generaron como recomendados en la terce lista recibida
	  void generar_recomendaciones(Lista<Pelicula>* vistas, Lista<Pelicula>* no_vistas, Lista<Pelicula>* recomendadas);

    //Mostrar menu
    //Post: Imprime por pantalla las opciones del menu
    void mostrar();

    //Ejecutar opcion
    //Descripción: Procedimiento que recibe un valor representativo a la opción elegida por el usuario y las listas de peliculas vistas, no vistas
    //             por el usuario y una tercera vacía para las recomendadas. Ejecuta la opción recibida
    //Pre: Procedimiento que recibe un entero representativo a la opción y tres direcciones de memoria de objetos de clase Lista de objetos Pelicula
    //Post: Ejecuta la opción recibida
    void ejecutar_opcion(int opcion, Lista<Pelicula>* vistas, Lista<Pelicula>* no_vistas, Lista<Pelicula>* recomendadas);

		//Cargar lista
    //Descripción: Procedimiento que recibe la ruta de un archivo de peliculas y una dirección de memoria a una lista vacia y carga las peliculas
    //             encontradas en el archivo en la lista
    //Pre: Procedimiento que recibe una ruta de un archivo que contiene peliculas y una dirección de memoria a un objeto de clase Lista de objetos
    //     Pelicula
    //Post: Carga las peliculas encontradas en el archivo en la el objeto recibido
    void cargar_listas(std::string ruta, Lista<Pelicula>* lista_peliculas);

		//Imprimir lista
		//Descripción: Procedimiento que recibe una dirección de memoria a una lista de peliculas e imprime por pantalla los datos dentro de la misma
		//Pre: Procedimiento que recibe una dirección de memoria a un objeto de clase Lista de objetos Pelicula
		//Post: Imprime por pantalla los datos dentro del objeto clase Lista
		void imprimir_lista(Lista<Pelicula>* lista_peliculas);

		//Separar actores
		//Descripción: Procedimiento que recibe en una cadena de caracter todos los nombres de los actores de una pelicula y una dirección de memoria a
    //             una lista, y separa los nombres de la cadena y los guarda en la lista recibida
		//Pre: Procedimiento que recibe una cadena de caracteres con todos los nombres de los actores y una dirección de memoria a un objeto de clase
    //     lista
		//Post: Separa los nombres de la cadena y los guarda en el objeto clase lista recibido
		void separar_actores(std::string actores, Lista<std::string>* lista_actores);
};

#endif

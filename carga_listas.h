#ifndef CARGA_LISTAS_H
#define CARGA_LISTAS_H

#include <fstream>
#include "pelicula.h"

const std::string VACIO = "                                                  ";

class Carga_listas{
	//Métodos:
	public:
		//Constructor
		Carga_listas();

		//Constructor con parámetros
    	Carga_listas(Carga_listas lista, std::string ruta, Lista<Pelicula> &lista_peliculas);

		//Imprimir lista cargada
		//Descripción: Procedimiento que recibe una lista de peliculas e imprime por pantalla los datos dentro de la misma
		//Pre: Procedimiento que recibe un objeto de clase Lista del tipo objeto clase Pelicula
		//Post: Imprime por pantalla los datos dentro del objeto clase Lista
		void imprimir_lista_cargada(Lista<Pelicula> lista_peliculas);

		//Separar actores
		//Descripción: Procedimiento que recibe en una cadena de caracter todos los nombres de los actores de una pelicula y una lista, y separa los
		//             nombres de la cadena y los guarda en la lista recibida
		//Pre: Procedimiento que recibe una cadena de caracteres con todos los nombres de los actores y un objeto de clase lista
		//Post: Separa los nombres de la cadena y los guarda en el objeto clase lista recibido
		void separar_actores(std::string actores, Lista<std::string> &lista_actores);

		//Liberar memoria de lista cargada
		//Descripción: Procedimiento que recibe una dirección de memoria de una lista de peliculas y libera la memoria dinámica de dicha lista
		//Pre: Procedimiento que recibe una dirección de memoria a un objeto de clase Lista de objetos de clase Pelicula
		//Post: Libera la memoria dinámica de la lista
		void liberar_lista_cargada(Lista<Pelicula>* lista_peliculas);

};

#endif

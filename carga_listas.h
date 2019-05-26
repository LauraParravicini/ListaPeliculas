#ifndef CARGA_LISTAS_H
#define CARGA_LISTAS_H

#include <fstream>
#include "pelicula.h"

const std::string VACIO = "                                                  ";

class Carga_listas{
	//Métodos:
	public:
		//Constructor con parámetros
    Carga_listas(Carga_listas lista, std::string ruta, std::list<Pelicula> &lista_peliculas);

	private:
		//Separar actores
		//Descripción: Procedimiento que recibe en una cadena de caracter todos los nombres de los actores de una pelica y una lista, y separa los
		//             nombres de la cadena y los guarda la lista recibida
		//Pre: Procedimiento que recibe una cadena de caracter con todos los nombres de los actores y objeto de clase lista
		//Post: Separa los nombres de la cadena y los guarda en el objeto de clase lista recibido
		void separar_actores(std::string actores, std::list<std::string> &lista_actores);
};

#endif

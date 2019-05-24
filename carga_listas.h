#ifndef CARGA_LISTAS_H
#define CARGA_LISTAS_H

#include <fstream>
#include "pelicula.h"

class Carga_listas{
	public:
		//Carga de listas
		//Pre: lista vacia y ruta valida.
		//Post: Carga la lista pelicula con los datos del archivo de ruta
    	Carga_listas(std::string ruta, std::list<Pelicula> &lista_peliculas);

    	void mostrar_peliculas(std::list<Pelicula> g);
};

#endif
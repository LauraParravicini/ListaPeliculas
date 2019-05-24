#ifndef CARGA_LISTAS_H
#define CARGA_LISTAS_H

#include <fstream>
#include "pelicula.h"

class Carga_listas{
	public:
    	Carga_listas(std::string ruta, std::list<Pelicula> &lista_peliculas);
};

#endif
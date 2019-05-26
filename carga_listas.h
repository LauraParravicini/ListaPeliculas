#ifndef CARGA_LISTAS_H
#define CARGA_LISTAS_H

#include <fstream>
#include "pelicula.h"

class Carga_listas{
	//Métodos:
	public:
		//Constructor
		Carga_listas();

		//Constructor con parámetros
    Carga_listas(std::string ruta, std::list<Pelicula> &lista_peliculas);

    //Mostrar listas de peliculas
		//Descripción: Procedimiento que recibe una lista de peliculas y las muestra por pantalla
    //Pre: Procedimiento que recibe objeto de clase Lista
    //Post: Muestra por pantalla los contenido en la lista pasada por parametro
    void mostrar_peliculas(std::list<Pelicula> g);

		//Generar recomendaciones de peliculas
		//Descripción: Función que recibe listas de peliculas vistas y no vistas y  devuelve una tercera con las recomendadas
		//Pre: Función que recibe objetos de clase Lista
		//Post: Devuelve un objeto de clase Lista
		std::list<Pelicula> generar_recomendaciones(std::list<Pelicula> vistas, std::list<Pelicula> no_vistas);
};

#endif

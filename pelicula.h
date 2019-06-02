#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include "lista.h"

const int MINIMO_PARA_RECOMENDAR = 7;

class Pelicula{
	//Atributos
	private:
		std::string titulo;
		std::string genero;
		int puntaje;
		std::string director;
		Lista<std::string> lista_actores;

	//Métodos
	public:
		//Constructor
		Pelicula();

		//Constructor con parámetros
		Pelicula(std::string nombre, std::string genero, int puntaje, std::string director, Lista<std::string> lista_actores);

		//Obtener título
		//Post: Devuelve los datos del atributo titulo de la clase
		std::string obtener_titulo();

		//Asignar titulo
		//Post: Asigna al atributo titulo el parametro recibido
		void asignar_titulo(std::string titulo);

		//Obtener género
		//Post: Devuelve los datos del atributo genero de la clase
		std::string obtener_genero();

		//Asignar genero
		//Post: Asigna al atributo genero el parametro recibido
		void asignar_genero(std::string genero);

		//Obtener puntaje
		//Post: Devuelve el valor del atributo puntaje de la clase
		int obtener_puntaje();

		//Asignar puntaje
		//Post: Asigna al atributo puntaje el parametro recibido
		void asignar_puntaje(int puntaje);

		//Obtener director
		//Post: Devuelve los datos del atributo director de la clase
		std::string obtener_director();

		//Asignar director
		//Post: Asigna al atributo director el parametro recibido
		void asignar_director(std::string director);

		//Asignar lista de actores
		//Descripción: Recibe una lista de actores y la asigna al atributo lista_actores de la clase
		//Pre: Recibe un objeto de la clase Lista de cadena de caracteres
		//Post: Asigna el objeto recibido al objeto de clase lista del atributo lista_actores de la clase
		void asignar_lista_actores(Lista<std::string> lista_actores);

		//Obtener lista actores
		//Post: Devuelve la lista del atributo lista_actores de la clase
		Lista<std::string> obtener_lista_actores();

		//Imprimir datos de la pelicula
		//Post: Imprime por pantalla los datos de la pelicula
		void imprimir_datos_pelicula();

		//Es una pelicula recomendable?
		//Descripción: Función que recibe una pelicula no vista por el usuario y devuelve si la pelicula recibida es recomendable o no
		//Pre: Función que recibe un objeto clase Pelicula
		//Post: Devuelve como resultado de la función si la pelicula recibida es recomendable o no
		bool es_recomendable(Pelicula pelicula_no_vista);

		//Hay coincidencia de actores?
		//Descripción: Función que recibe una lista de actores de una pelicula no vista por el usuario y devuelve
		//			   		 si hay coincidencia o no de actores de alguna ya vista
		//Pre: Función que recibe un objeto clase Lista que contiene actores
		//Post: Devuelve como resultado de la función si hay coincidencia o no de actores
		bool coinciden_actores(Lista<std::string> lista_actores);
};

#endif

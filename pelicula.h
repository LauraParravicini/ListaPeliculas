#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <list>
#include <iterator>
#include <string>

class Pelicula{
	//Atributos
	private:
		std::string titulo;
		std::string genero;
		int puntaje;
		std::string director;
		std::list<std::string> lista_actores;

	//Métodos
	public:
		//Constructor
		Pelicula();

		//Constructor con parámetros
		Pelicula(std::string nombre, std::string genero, int puntaje, std::string director, std::list<std::string> lista_actores);

		//Obtener título
		//Post: Devuelve los datos del atributo titulo de la clase
		std::string obtener_titulo();

		//Asignar titulo
		void asignar_titulo(std::string titulo);

		//Obtener género
		//Post: Devuelve los datos del atributo genero de la clase
		std::string obtener_genero();

		//Asignar genero
		void asignar_genero(std::string genero);		

		//Obtener puntaje
		//Post: Devuelve el valor del atributo puntaje de la clase
		int obtener_puntaje();

		//Asignar puntaje
		void asignar_puntaje(int puntaje);

		//Obtener director
		//Post: Devuelve los datos del atributo director de la clase
		std::string obtener_director();

		//Asignar director
		void asignar_director(std::string director);

		//Asignar lista de actores
		//Descripción: Recibe una dirección de una lista de actores y la asigna al puntero del atributo lista_actores de la clase
		//Pre: Recibe un puntero de la clase Lista con la dirección de una lista de actores
		//Post: Asigna la direccón recibida al puntero de clase lista del atributo lista_actores de la clase
		void asignar_lista_actores(std::list<std::string> lista_actores);

		//Obtener lista actores
		//Post: Devuelve el valor de la dirección de memoria del atributo lista_actores de la clase
		std::list<std::string> obtener_lista_actores();

};

#endif 
#include "pelicula.h"

Pelicula::Pelicula(){}
/*
std::string titulo;
std::string genero;
int puntaje;
std::string director;
std::list<std::string> lista_actores;
*/
//Constructor con parámetros
Pelicula::Pelicula(std::string nombre, std::string genero, int puntaje, 
				   std::string director, std::list<std::string> lista_actores){
	titulo = nombre;
	this->genero = genero;
	this->puntaje = puntaje;
	this->director = director;
	this->lista_actores = lista_actores;
}

//Obtener título
//Post: Devuelve los datos del atributo titulo de la clase
std::string Pelicula::obtener_titulo(){
	return titulo;
}

void Pelicula::asignar_titulo(std::string titulo){
	this->titulo = titulo;
}

//Obtener género
//Post: Devuelve los datos del atributo genero de la clase
std::string Pelicula::obtener_genero(){
	return genero;
}


void Pelicula::asignar_genero(std::string genero){
	this->genero = genero;
}

//Obtener puntaje
//Post: Devuelve el valor del atributo puntaje de la clase
int Pelicula::obtener_puntaje(){
	return puntaje;
}


void Pelicula::asignar_puntaje(int puntaje){
	this->puntaje = puntaje;
}

//Obtener director
//Post: Devuelve los datos del atributo director de la clase
std::string Pelicula::obtener_director(){
	return director;
}


void Pelicula::asignar_director(std::string director){
	this->director = director;
}

//Asignar lista de actores
//Descripción: Recibe una dirección de una lista de actore y la asigna al puntero del atributo lista_actores de la clase
//Pre: Recibe un puntero de la clase Lista con la dirección de una lista de actores
//Post: Asigna la direccón recibida al puntero de clase lista del atributo lista_actores de la clase
void Pelicula::asignar_lista_actores(std::list<std::string> lista_actores){
	this->lista_actores = lista_actores;
}

//Obtener lista actores
//Post: Devuelve el valor de la dirección de memoria del atributo lista_actores de la clase
std::list<std::string> Pelicula::obtener_lista_actores(){
	return lista_actores;
}
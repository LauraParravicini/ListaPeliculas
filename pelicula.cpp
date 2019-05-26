#include "pelicula.h"

Pelicula::Pelicula(){}

Pelicula::Pelicula(std::string nombre, std::string genero, int puntaje, std::string director, std::list<std::string> lista_actores){
	titulo = nombre;
	this->genero = genero;
	this->puntaje = puntaje;
	this->director = director;
	this->lista_actores = lista_actores;
}

std::string Pelicula::obtener_titulo(){
	return titulo;
}

void Pelicula::asignar_titulo(std::string titulo){
	this->titulo = titulo;
}

std::string Pelicula::obtener_genero(){
	return genero;
}

void Pelicula::asignar_genero(std::string genero){
	this->genero = genero;
}

int Pelicula::obtener_puntaje(){
	return puntaje;
}

void Pelicula::asignar_puntaje(int puntaje){
	this->puntaje = puntaje;
}

std::string Pelicula::obtener_director(){
	return director;
}

void Pelicula::asignar_director(std::string director){
	this->director = director;
}

void Pelicula::asignar_lista_actores(std::list<std::string> lista_actores){
	this->lista_actores = lista_actores;
}

std::list<std::string> Pelicula::obtener_lista_actores(){
	return lista_actores;
}

bool Pelicula::es_recomendable(Pelicula no_vista){
	if(genero == no_vista.obtener_genero() )
		if( (no_vista.obtener_puntaje() >= MINIMO_PARA_RECOMENDAR) || (director == no_vista.obtener_director() ) || (coinciden_actores(no_vista.obtener_lista_actores() ) ) )
			return true;

	return false;
}

bool Pelicula::coinciden_actores(std::list<std::string> lista_actores){
	int coincidencia = 0;
	std::list <std::string> :: iterator it_uno;
	std::list <std::string> :: iterator it_dos;

	for(it_uno = this->lista_actores.begin(); it_uno != this->lista_actores.end(); ++it_uno)
		for(it_dos = lista_actores.begin(); it_dos != lista_actores.end(); ++it_dos)
			if(*it_uno == *it_dos)
				coincidencia++;

	return coincidencia;
}

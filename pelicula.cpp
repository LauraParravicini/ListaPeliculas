#include "pelicula.h"

Pelicula::Pelicula(){}

Pelicula::Pelicula(std::string nombre, std::string genero, int puntaje, std::string director, Lista<std::string> lista_actores){
	titulo = nombre;
	this->genero = genero;
	this->puntaje = puntaje;
	this->director = director;
	this->lista_actores.copiar(lista_actores);
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

void Pelicula::asignar_lista_actores(Lista<std::string> lista_actores){
	this->lista_actores.copiar(lista_actores);
}

Lista<std::string> Pelicula::obtener_lista_actores(){
	return lista_actores;
}

void Pelicula::imprimir_datos_pelicula(){
	std::cout << "Título: " << obtener_titulo() << std::endl;
	std::cout << "Género: " << obtener_genero() << std::endl;
	std::cout << "Puntaje: " << obtener_puntaje() << std::endl;
	std::cout << "Director: " << obtener_director() << std::endl;

	std::cout << "Reparto: ";
	for(int i = INICIO; i <= lista_actores.obtener_tam(); i++)
		std::cout << " " << lista_actores.obtener_dato(i) << " ";
	std::cout << std::endl << std::endl;
}

bool Pelicula::es_recomendable(Pelicula no_vista){
	if(genero == no_vista.obtener_genero() ){
		if( (no_vista.obtener_puntaje() >= MINIMO_PARA_RECOMENDAR) || ( director == no_vista.obtener_director() ) || ( coinciden_actores(no_vista.obtener_lista_actores() ) ) )
			return true;
	}

	return false;
}

bool Pelicula::coinciden_actores(Lista<std::string> lista_actores){
	int coincidencia = 0;

	for(int i = INICIO; i <= this->lista_actores.obtener_tam(); i++)
		for(int j = INICIO; j <= this->lista_actores.obtener_tam(); j++)
				if( this->lista_actores.obtener_dato(i) == lista_actores.obtener_dato(j) )
					coincidencia++;

	return coincidencia;
}

#include "carga_listas.h"

Carga_listas::Carga_listas(){}

Carga_listas::Carga_listas(Carga_listas lista, std::string ruta,Lista<Pelicula> &lista_peliculas){
	std::ifstream archivo_leer;
	archivo_leer.open(ruta);
	std::string titulo, puntaje_str, genero, director, actores, buffer;
	int puntaje;

	if(archivo_leer.is_open()){
		while(!archivo_leer.eof()){
			Lista<std::string> lista_actores;
			getline(archivo_leer,titulo);
			getline(archivo_leer,genero);
			getline(archivo_leer,puntaje_str);
			puntaje = std::stoi(puntaje_str);
			getline(archivo_leer,director);
			getline(archivo_leer, actores);
			lista.separar_actores(actores, lista_actores);

			Pelicula pelicula_leida(titulo, genero, puntaje, director, lista_actores);
			lista_peliculas.agregar_dato(pelicula_leida);

			getline(archivo_leer,buffer);
		}
	}else{
		std::cout << "- Error al abrir archivo -" << std::endl;
		return;
	}
	archivo_leer.close();
}

void Carga_listas::separar_actores(std::string actores, Lista<std::string> &lista_actores){
	std::string actor = VACIO;
	int tam = actor.length();
	int j = 0;
	int tope = actores.length();

	for(int i = 0; i < tope; i++){
		if(actores[i] != ' '){
			if(actores[i] == '_')
				actor[j] = ' ';
			else
				actor[j] = actores[i];
			j++;
		}
		else{
			actor.erase(tam-(tam-j));
			lista_actores.agregar_dato(actor);
			j=0;
			actor = VACIO;
		}
	}
	actor.erase(tam-(tam-j));
	lista_actores.agregar_dato(actor);
	j=0;
	actor = VACIO;
}

void Carga_listas::imprimir_lista_cargada(Lista<Pelicula> lista_peliculas){
  int posicion = INICIO;
  int cantidad_nodos = lista_peliculas.obtener_tam();
  Pelicula aux;

  while(posicion <= cantidad_nodos){
    aux = lista_peliculas.obtener_dato(posicion);
    aux.imprimir_datos_pelicula();
    posicion++;
  }
}

void Carga_listas::liberar_lista_cargada(Lista<Pelicula>* lista_peliculas){
	int posicion = INICIO;
  int cantidad_nodos = lista_peliculas->obtener_tam();
  Pelicula aux_pelicula;
	Lista<std::string> aux_lista_actores;


  while(posicion <= cantidad_nodos){
    aux_pelicula = (lista_peliculas->obtener_dato(posicion) );
    aux_lista_actores = aux_pelicula.obtener_lista_actores();
		aux_lista_actores.liberar();
    posicion++;
  }

	lista_peliculas->liberar();
}

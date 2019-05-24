#include "carga_listas.h"

Carga_listas::Carga_listas(std::string ruta,std::list<Pelicula> &lista_peliculas){
	std::ifstream archivo_leer;
	archivo_leer.open(ruta);
	std::string titulo,puntaje_str,genero,director,actor;
	std::list<std::string> lista_actores;
	int puntaje;
	
	if(archivo_leer.is_open()){
		while(getline(archivo_leer,titulo)){

			getline(archivo_leer,genero);
			getline(archivo_leer,puntaje_str);
			puntaje = std::stoi(puntaje_str);
			getline(archivo_leer,director);
			
			while(archivo_leer >> actor){
				lista_actores.push_back(actor);
			}
			
			Pelicula pelicula_leida(titulo,genero,puntaje,director,lista_actores);
			lista_peliculas.push_back(pelicula_leida);
			
		}
	}else{
		std::cout << "- Error al abrir archivo -" << std::endl;
		return;
	}
	archivo_leer.close();
}

void Carga_listas::mostrar_peliculas(std::list <Pelicula> g){ 
    std::list <Pelicula> :: iterator it; 
    std::list <std::string> lista_actual;

    for(it = g.begin(); it != g.end(); ++it){
        std::cout << it->obtener_titulo() << " " << it->obtener_genero() << " " << it->obtener_puntaje() << " " << it->obtener_director() << std::endl;
        lista_actual = it->obtener_lista_actores();

        std::list <std::string> :: iterator it_actor; 
	    for(it_actor = lista_actual.begin(); it_actor != lista_actual.end(); ++it_actor){
	        std::cout << *it_actor << " " << std::endl; 
	    }
	    std::cout << '\n';     
    }
    
    std::cout << '\n'; 
}
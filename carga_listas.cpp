#include "carga_listas.h"

Carga_listas::Carga_listas(){}

Carga_listas::Carga_listas(std::string ruta,std::list<Pelicula> &lista_peliculas){
	std::ifstream archivo_leer;
	archivo_leer.open(ruta);
	std::string titulo, puntaje_str, genero, director, actor, buffer;
	int puntaje;

	if(archivo_leer.is_open()){
		while(!archivo_leer.eof()){
			bool leer = true;
			std::list<std::string> lista_actores;
			getline(archivo_leer,titulo);
			getline(archivo_leer,genero);
			getline(archivo_leer,puntaje_str);
			puntaje = std::stoi(puntaje_str);
			getline(archivo_leer,director);

			//getline(archivo_leer,actor, ' ');
			archivo_leer>>actor;
			while(leer){
				lista_actores.push_back(actor);
				/*getline(archivo_leer,actor, ' ');*/archivo_leer >> actor;
				if(actor[0] == ';')
					leer = false;
			}
			//getline(archivo_leer,actor);

			Pelicula pelicula_leida(titulo, genero, puntaje, director, lista_actores);
			lista_peliculas.push_back(pelicula_leida);

			//getline(archivo_leer,buffer);
			getline(archivo_leer,buffer);
			getline(archivo_leer,buffer);

			/*std::list <Pelicula> :: iterator it;
			for(it = lista_peliculas.begin(); it != lista_peliculas.end(); ++it){
	        std::cout << it->obtener_titulo() << " " << it->obtener_genero() << " " << it->obtener_puntaje() << " " << it->obtener_director() << std::endl;
	        lista_actores = it->obtener_lista_actores();

	        std::list <std::string> :: iterator it_actor;
		    for(it_actor = lista_actores.begin(); it_actor != lista_actores.end(); ++it_actor){
		        std::cout << *it_actor << " ";
		    }
		    std::cout << '\n';
	    }*/

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
        std::cout << it->obtener_titulo() << " " <<std::endl << it->obtener_genero() << " " <<std::endl  << it->obtener_puntaje() << " " <<std::endl  << it->obtener_director() << std::endl;
        lista_actual = it->obtener_lista_actores();

        std::list <std::string> :: iterator it_actor;
	    for(it_actor = lista_actual.begin(); it_actor != lista_actual.end(); ++it_actor){
	        std::cout << *it_actor << " ";
	    }
	    std::cout << "\n\n";
    }
    std::cout << '\n';
}

std::list<Pelicula> Carga_listas::generar_recomendaciones(std::list<Pelicula> vistas, std::list<Pelicula> no_vistas){
	std::list<Pelicula> recomendadas;
	int cantidad_recomendadas = 0;
	bool ya_esta = false;

	std::list <Pelicula> :: iterator it_vistas;
	std::list <Pelicula> :: iterator it_no_vistas;
	std::list <Pelicula> :: iterator it_recomendadas;

	for(it_vistas = vistas.begin(); it_vistas != vistas.end(); ++it_vistas)
		for(it_no_vistas = no_vistas.begin(); it_no_vistas != no_vistas.end(); ++it_no_vistas)
			if(it_vistas->es_recomendable(*it_no_vistas) ){
				if(cantidad_recomendadas == 0)
					recomendadas.push_back(*it_no_vistas);
				else{
					for(it_recomendadas = recomendadas.begin(); it_recomendadas != recomendadas.end(); ++it_recomendadas)
						if(it_recomendadas->obtener_titulo() == it_no_vistas->obtener_titulo() )
							ya_esta = true;
					if(!ya_esta)
						recomendadas.push_back(*it_no_vistas);
				}
				cantidad_recomendadas++;
			}
	return recomendadas;
}

#include "menu.h"

Menu::Menu(){}

void Menu::inicializar(Lista<Pelicula> vistas, Lista<Pelicula> no_vistas){
  cargar_listas(RUTA_VISTAS, vistas);
  cargar_listas(RUTA_NO_VISTAS, no_vistas);

  int opcion = 0;

  while(opcion != 4){
    mostrar();
    std::cout << "Ingrese opción seleccionada: ";
    std::cin >> opcion;
    std::cout << std::endl << std::endl;
    ejecutar_opcion(opcion, vistas, no_vistas);
  }
}

void Menu::mostrar(){
  std::cout << "--------------------MENU--------------------" << std::endl;
  std::cout << "1- Ver listado de peliculas vistas" << std::endl;
  std::cout << "2- Ver listado de peliculas no vistas" << std::endl;
  std::cout << "3- Ver listado de peliculas recomendadas" << std::endl;
  std::cout << "4- Salir" << std::endl;
  std::cout << "--------------------------------------------" << std::endl << std::endl;
}

void Menu::ejecutar_opcion(int opcion, Lista<Pelicula> vistas, Lista<Pelicula> no_vistas){
  switch(opcion){
    case 1:
      std::cout << std::endl << "-----------------VISTAS------------------" << std::endl << std::endl;
      imprimir_lista(vistas);
    break;

    case 2:
      std::cout << std::endl << "----------------NO VISTAS----------------" << std::endl << std::endl;
      imprimir_lista(no_vistas);
    break;

    case 3:{
      Lista<Pelicula> recomendadas = generar_recomendaciones(vistas, no_vistas);
      std::cout << std::endl << "----------------RECOMENDADAS----------------" << std::endl << std::endl;
      imprimir_lista(recomendadas);
      recomendadas.liberar();
    }break;

    case 4:
      std::cout << std::endl << "Hasta luego!" << std::endl;
      liberar_lista(&vistas);
      liberar_lista(&no_vistas);
    break;

    default:
      std::cout << std::endl << "Entrada inválida" << std::endl;
    break;
  }
}

Lista<Pelicula> Menu::generar_recomendaciones(Lista<Pelicula> vistas, Lista<Pelicula> no_vistas){
	Lista<Pelicula> recomendadas;
	bool ya_esta = false;
  Pelicula aux_vistas, aux_no_vistas, aux_recomendadas;

  for(int i = INICIO; i <= vistas.obtener_tam(); i++){
    aux_vistas = vistas.obtener_dato(i);

    for(int j = INICIO; j <= no_vistas.obtener_tam(); j++){
      aux_no_vistas = no_vistas.obtener_dato(j);

      if(aux_vistas.es_recomendable(aux_no_vistas) ){

        if( !recomendadas.obtener_tam() )
          recomendadas.agregar_dato(aux_no_vistas);
        else{

          for(int k = INICIO; k <= recomendadas.obtener_tam(); k++){
            aux_recomendadas = recomendadas.obtener_dato(k);
            if(aux_recomendadas.obtener_titulo() == aux_no_vistas.obtener_titulo() )
              ya_esta = true;
          }
          if(!ya_esta)
            recomendadas.agregar_dato(aux_no_vistas);
        }
      }
    }
  }
  return recomendadas;
}

void Menu::cargar_listas(std::string ruta,Lista<Pelicula> &lista_peliculas){
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
			separar_actores(actores, lista_actores);

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

void Menu::separar_actores(std::string actores, Lista<std::string> &lista_actores){
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

void Menu::imprimir_lista(Lista<Pelicula> lista_peliculas){
  Pelicula aux;

  for(int i = INICIO; i <= lista_peliculas.obtener_tam(); i++){
    aux = lista_peliculas.obtener_dato(i);
    aux.imprimir_datos_pelicula();
  }
}

void Menu::liberar_lista(Lista<Pelicula>* lista_peliculas){
	Pelicula aux_pelicula;
	Lista<std::string> aux_lista_actores;

  for(int i = INICIO; i <= lista_peliculas->obtener_tam(); i++){
	  aux_pelicula = (lista_peliculas->obtener_dato(i) );
	  aux_lista_actores = aux_pelicula.obtener_lista_actores();
		aux_lista_actores.liberar();
	}

	lista_peliculas->liberar();
}

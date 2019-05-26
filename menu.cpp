#include "menu.h"

Menu::Menu(){}

void Menu::inicializar(Menu menu, std::list<Pelicula> lista_peliculas_vistas, std::list<Pelicula> lista_peliculas_no_vistas){
  int opcion = 0;

  while(opcion != 4){
    menu.mostrar();
    std::cin>>opcion;
    menu.opcion(menu, opcion, lista_peliculas_vistas, lista_peliculas_no_vistas);
  }
}

void Menu::mostrar(){
  std::cout<<"----------------MENU----------------"<<std::endl;
  std::cout<<"1- Ver listado de peliculas vistas"<<std::endl;
  std::cout<<"2- Ver listado de peliculas no vistas"<<std::endl;
  std::cout<<"3- Ver listado de peliculas recomendadas"<<std::endl;
  std::cout<<"4- Salir"<<std::endl<<std::endl;
}

void Menu::opcion(Menu menu, int opcion, std::list<Pelicula> lista_peliculas_vistas, std::list<Pelicula> lista_peliculas_no_vistas){
  switch(opcion){
    case 1:
      std::cout<<std::endl<<"----------------VISTAS----------------"<<std::endl<<std::endl;
      menu.mostrar_peliculas(lista_peliculas_vistas);
    break;

    case 2:
      std::cout<<std::endl<<"----------------NO VISTAS----------------"<<std::endl<<std::endl;
      menu.mostrar_peliculas(lista_peliculas_no_vistas);
    break;

    case 3:{
      std::list<Pelicula> lista_peliculas_recomendadas = menu.generar_recomendaciones(lista_peliculas_vistas, lista_peliculas_no_vistas);
      std::cout<<std::endl<<"----------------RECOMENDADAS----------------"<<std::endl<<std::endl;
      menu.mostrar_peliculas(lista_peliculas_recomendadas);
    }break;

    case 4:
      std::cout<<std::endl<<"Hasta luego!"<<std::endl;
    break;

    default:
      std::cout<<std::endl<<"Entrada inválida"<<std::endl;
    break;
  }
}

void Menu::mostrar_peliculas(std::list <Pelicula> g){
    std::list <Pelicula> :: iterator it;
    std::list <std::string> lista_actual;

    for(it = g.begin(); it != g.end(); ++it){
        std::cout<< "Título: " << it->obtener_titulo() << " " <<std::endl
        << "Género: " << it->obtener_genero() << " " <<std::endl
        << "Puntaje: " << it->obtener_puntaje() << " " <<std::endl
        << "Director: " << it->obtener_director() << std::endl;

        lista_actual = it->obtener_lista_actores();

        std::list <std::string> :: iterator it_actor;
        std::cout << "Elenco: ";
	    for(it_actor = lista_actual.begin(); it_actor != lista_actual.end(); ++it_actor){
	        std::cout << *it_actor << "  ";
	    }
	    std::cout << "\n\n";
    }
    std::cout << '\n';
}

std::list<Pelicula> Menu::generar_recomendaciones(std::list<Pelicula> vistas, std::list<Pelicula> no_vistas){
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

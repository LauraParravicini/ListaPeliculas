#include "menu.h"

Menu::Menu(){}

void Menu::inicializar(Menu menu, Carga_listas lista_vistas, std::list<Pelicula> lista_peliculas_vistas, Carga_listas lista_no_vistas, std::list<Pelicula> lista_peliculas_no_vistas){
  int opcion = 0;

  while(opcion != 4){
    menu.mostrar();
    std::cin>>opcion;
    menu.opcion(opcion, lista_vistas, lista_peliculas_vistas, lista_no_vistas, lista_peliculas_no_vistas);
  }
}

void Menu::mostrar(){
  std::cout<<"----------------MENU----------------"<<std::endl;
  std::cout<<"1- Ver listado de peliculas vistas"<<std::endl;
  std::cout<<"2- Ver listado de peliculas no vistas"<<std::endl;
  std::cout<<"3- Ver listado de peliculas recomendadas"<<std::endl;
  std::cout<<"4- Salir"<<std::endl<<std::endl;
}

void Menu::opcion(int opcion, Carga_listas lista_vistas, std::list<Pelicula> lista_peliculas_vistas, Carga_listas lista_no_vistas, std::list<Pelicula> lista_peliculas_no_vistas){
  switch(opcion){
    case 1:
      std::cout<<std::endl<<"----------------VISTAS----------------"<<std::endl<<std::endl;
      lista_vistas.mostrar_peliculas(lista_peliculas_vistas);
    break;

    case 2:
      std::cout<<std::endl<<"----------------NO VISTAS----------------"<<std::endl<<std::endl;
      lista_no_vistas.mostrar_peliculas(lista_peliculas_no_vistas);
    break;

    case 3:{
      std::list<Pelicula> lista_peliculas_recomendadas = lista_vistas.generar_recomendaciones(lista_peliculas_vistas, lista_peliculas_no_vistas);
      Carga_listas lista_recomendadas;
      std::cout<<std::endl<<"----------------RECOMENDADAS----------------"<<std::endl<<std::endl;
      lista_recomendadas.mostrar_peliculas(lista_peliculas_recomendadas);
    }break;

    case 4:
      std::cout<<std::endl<<"Hasta luego!"<<std::endl;
    break;

    default:
      std::cout<<std::endl<<"Entrada inválida"<<std::endl;
    break;
  }
}

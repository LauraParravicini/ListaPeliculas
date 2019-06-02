#include "menu.h"

Menu::Menu(){}

void Menu::inicializar(Carga_listas lista_vistas, Lista<Pelicula> lista_peliculas_vistas, Carga_listas lista_no_vistas, Lista<Pelicula> lista_peliculas_no_vistas){
  int opcion = 0;

  while(opcion != 4){
    mostrar();
    std::cout << "Ingrese opción seleccionada: ";
    std::cin >> opcion;
    std::cout << std::endl << std::endl;
    ejecutar_opcion(opcion, lista_vistas, lista_peliculas_vistas, lista_no_vistas, lista_peliculas_no_vistas);
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

void Menu::ejecutar_opcion(int opcion, Carga_listas lista_vistas, Lista<Pelicula> lista_peliculas_vistas, Carga_listas lista_no_vistas, Lista<Pelicula> lista_peliculas_no_vistas){
  switch(opcion){
    case 1:
      std::cout<<std::endl<<"-----------------VISTAS------------------"<<std::endl<<std::endl;
      lista_vistas.imprimir_lista_cargada(lista_peliculas_vistas);
    break;

    case 2:
      std::cout<<std::endl<<"----------------NO VISTAS----------------"<<std::endl<<std::endl;
      lista_no_vistas.imprimir_lista_cargada(lista_peliculas_no_vistas);
    break;

    case 3:{
      Carga_listas lista_recomendadas;
      Lista<Pelicula> lista_peliculas_recomendadas = generar_recomendaciones(lista_peliculas_vistas, lista_peliculas_no_vistas);
      std::cout<<std::endl<<"----------------RECOMENDADAS----------------"<<std::endl<<std::endl;
      lista_recomendadas.imprimir_lista_cargada(lista_peliculas_recomendadas);
      lista_peliculas_recomendadas.liberar();
    }break;

    case 4:
      std::cout<<std::endl<<"Hasta luego!"<<std::endl;
    break;

    default:
      std::cout<<std::endl<<"Entrada inválida"<<std::endl;
    break;
  }
}

Lista<Pelicula> Menu::generar_recomendaciones(Lista<Pelicula> vistas, Lista<Pelicula> no_vistas){
	Lista<Pelicula> recomendadas;
	bool ya_esta = false;
  int posicion_recomendadas, cantidad_recomendadas;
  int posicion_vistas = INICIO;
  int posicion_no_vistas = INICIO;

  int cantidad_vistas = vistas.obtener_tam();
  int cantidad_no_vistas = no_vistas.obtener_tam();

  Pelicula aux_vistas, aux_no_vistas, aux_recomendadas;

  while(posicion_vistas <= cantidad_vistas){
    aux_vistas = vistas.obtener_dato(posicion_vistas);
    
    posicion_no_vistas = INICIO;
    
    while(posicion_no_vistas <= cantidad_no_vistas){
     
      aux_no_vistas = no_vistas.obtener_dato(posicion_no_vistas);
    
      if(aux_vistas.es_recomendable(aux_no_vistas) ){
        
        if( !recomendadas.obtener_tam() )
          recomendadas.agregar_dato(aux_no_vistas);
        else{
          posicion_recomendadas = INICIO;
          cantidad_recomendadas = recomendadas.obtener_tam();
          while(posicion_recomendadas <= cantidad_recomendadas){

            aux_recomendadas = recomendadas.obtener_dato(posicion_recomendadas);
            if(aux_recomendadas.obtener_titulo() == aux_no_vistas.obtener_titulo() ){
              ya_esta = true;
            }

            posicion_recomendadas++;
          }
          if(!ya_esta){
            recomendadas.agregar_dato(aux_no_vistas);
          }
        }     
      }
      posicion_no_vistas++;
    }
    posicion_vistas++;
  }
  return recomendadas;
}

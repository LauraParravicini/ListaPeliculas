#include <iostream>
#include "menu.h"
using namespace std;

int main(){
	Lista<Pelicula> lista_peliculas_vistas;
  Lista<Pelicula> lista_peliculas_no_vistas;
	Menu menu;

	menu.inicializar(lista_peliculas_vistas, lista_peliculas_no_vistas);

	return 0;
}

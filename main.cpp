#include <iostream>
#include "carga_listas.h"
#include "menu.h"

using namespace std;

const string RUTA_VISTAS = "películas_vistas.txt";
const string RUTA_NO_VISTAS = "películas_no_vistas.txt";

int main(){
	Lista<Pelicula> lista_peliculas_vistas;
  	Lista<Pelicula> lista_peliculas_no_vistas;
	
	Carga_listas lista_vistas(lista_vistas, RUTA_VISTAS, lista_peliculas_vistas);
  	Carga_listas lista_no_vistas(lista_no_vistas, RUTA_NO_VISTAS, lista_peliculas_no_vistas);

	Menu menu;

	menu.inicializar(lista_vistas, lista_peliculas_vistas, lista_no_vistas, lista_peliculas_no_vistas);

	lista_vistas.liberar_lista_cargada(&lista_peliculas_vistas);
	lista_no_vistas.liberar_lista_cargada(&lista_peliculas_no_vistas);

	return 0;
}

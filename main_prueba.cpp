#include <iostream>
#include "carga_listas.h"

using namespace std;

const string RUTA_VISTAS = "películas_vistas.txt";
const string RUTA_NO_VISTAS = "películas_no_vistas.txt";

int main(){

	list<Pelicula> lista_peliculas_vistas;
  list<Pelicula> lista_peliculas_no_vistas;

  //Cargo las listas
	Carga_listas lista_vistas(RUTA_VISTAS, lista_peliculas_vistas);
  Carga_listas lista_no_vistas(RUTA_NO_VISTAS, lista_peliculas_no_vistas);

  //Muestra por pantalla las listas.
	cout << "----------------VISTAS----------------" << endl<<endl<<endl;
	lista_vistas.mostrar_peliculas(lista_peliculas_vistas);
  cout << "----------------NO VISTAS----------------" << endl<<endl<<endl;
  lista_no_vistas.mostrar_peliculas(lista_peliculas_no_vistas);

	//Genera 3er lista (recomendaciones) y la imprime por pantalla
	list<Pelicula> lista_peliculas_recomendadas = lista_vistas.generar_recomendaciones(lista_peliculas_vistas, lista_peliculas_no_vistas);
	Carga_listas lista_recomendadas;
	cout << "----------------RECOMENDADAS----------------" << endl<<endl<<endl;
	lista_recomendadas.mostrar_peliculas(lista_peliculas_recomendadas);

	return 0;
}

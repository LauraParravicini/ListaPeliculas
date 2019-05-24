#include "carga_listas.h"

using namespace std;

const string ruta_vistas = "películas_vistas.txt";
const string ruta_no_vistas = "películas_no_vistas.txt";

int main(){
	
	list<Pelicula> lista_peliculas_vistas;
    list<Pelicula> lista_peliculas_no_vistas;

    //Cargo las listas
	Carga_listas lista_vistas(ruta_vistas,lista_peliculas_vistas);
    Carga_listas lista_no_vistas(ruta_no_vistas,lista_peliculas_no_vistas);

    //Muestra por pantalla las listas.
	lista_vistas.mostrar_peliculas(lista_peliculas_vistas);
    cout << "-------------------------------" << endl;
    lista_no_vistas.mostrar_peliculas(lista_peliculas_no_vistas);

}
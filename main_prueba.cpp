#include "carga_listas.h"

using namespace std;

// Estas dos funciones irian a carga listas que va a cambiar
// de nombre a operaciones listas
void mostrar_actores(list <string> g){ 
    list <string> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it){
        cout << *it << " " << endl; 
    }
    cout << '\n'; 
}

void mostrar_peliculas(list <Pelicula> g){ 
    list <Pelicula> :: iterator it; 
    list <string> lista_actual;

    for(it = g.begin(); it != g.end(); ++it){
        cout << it->obtener_titulo() << " " << it->obtener_genero() << " " << it->obtener_puntaje() << " " << it->obtener_director() << endl;
        lista_actual = it->obtener_lista_actores();
        mostrar_actores(lista_actual);
    }
    
    cout << '\n'; 
}

int main(){
	
	list<Pelicula> lista_peliculas_vistas;
    list<Pelicula> lista_peliculas_no_vistas;

	Carga_listas cargar_vistas("películas_vistas.txt",lista_peliculas_vistas);
    Carga_listas cargar_no_vistas("películas_no_vistas.txt",lista_peliculas_no_vistas);

	mostrar_peliculas(lista_peliculas_vistas);
    cout << "-------------------------------" << endl;
    mostrar_peliculas(lista_peliculas_no_vistas);

}
#include <iostream>
#include "menu.h"
using namespace std;

int main(){
	Lista<Pelicula> vistas;
  Lista<Pelicula> no_vistas;
	Lista<Pelicula> recomendadas;
	Menu menu;

	menu.inicializar(&vistas, &no_vistas, &recomendadas);

	return 0;
}

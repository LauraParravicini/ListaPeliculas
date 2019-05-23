#include "persona.h"

Persona::Persona(){
	nombre_apellido = " ";
}

Persona::Persona(std::string nombre_apellido){
	this->nombre_apellido = nombre_apellido;
}

void Persona::asignar_nombre_apellido(std::string nombre_apellido){
	this->nombre_apellido = nombre_apellido;
}

std::string Persona::obtener_nombre_apellido(){
	return nombre_apellido;
}
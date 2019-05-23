#ifndef PERSONA_H
#define PERSONA_H

class Persona{
	//Atributos
	private:
		std::string nombre_apellido;

	//Métodos
	public:
		//Constructor
		Persona();

		//Constructor con parámetros
		Persona(std::string nombre_apellido);

		//Asignar nombre y apellido
		//Descripción: Procedimiento que recibe nombre y apellido de una persona y la asigna al atributo
		//			   nombre_apellido de la clase
		//Pre: Procedimiento que recibe cadena de caracter
		//Post: Asignar la cadena recibida al atributo nombre_apellido de la clase
		void asignar_nombre_apellido(std::string nombre_apellido);

		//Obtener nombre y apellido
		//Post: Devuelve el los datos del atributo nombre_apellido de la clase
		std::string obtener_nombre_apellido();
};

#endif 
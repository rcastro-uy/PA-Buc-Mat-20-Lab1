#include "Viaje.h"

Viaje::Viaje(){}
Viaje::~Viaje(){}


String Viaje::getDuracion(){
	return this->duracion;
}

String Viaje::getDistancia(){
	return this->distancia;
}

DtFecha Viaje::getFecha(){
	return this->fecha;
}
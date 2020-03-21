
#include "Bicicleta.h"

Bicicleta::Bicicleta():Vehiculo(){}
Bicicleta::~Bicicleta():~Vehiculo{}
void Bicicleta::setTipo(TipoBici tb){
	this->tipo=tb;
}
TipoBici Bicicleta::getTipoBici(){
	return this->tipo;
}
void Bicicleta::setCantCambios(int cc){
	this->cantCambios=cc;
}
int Bicicleta::getCantCambios(){
	return this->cantCambios;
}


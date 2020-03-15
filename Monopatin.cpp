
#include "Monopatin.h"

Monopatin::Monopatin():Vehiculo(){}
Monopatin::~Monopatin():~Vehiculo(){}
void Monopatin::setTieneLuces(bool f){
	this->tieneLuces=f;
}
bool Monopatin::getTieneLuces(){
	return this->tieneLuces;
}


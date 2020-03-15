
#include "Vehiculo.h"

Vehiculo::Vehiculo(){}
Vehiculo::~Vehiculo(){}
void Vehiculo::setNroSerie(int ns){
	this->nroSerie=ns;
}
int Vehiculo::getNroSerie(){
	return this->nroSerie;
}
void Vehiculo::setPorcentajeBateria(float pb){
	this->porcentajeBateria=pb;
}
float Vehiculo::getPorcentajeBateria(){
	return this->porcentajeBateria;
}
void Vehiculo::setPrecioBase(float p){
	this->precioBase=p;
}
float Vehiculo::getPrecioBase(){
	return this->precioBase();
}
//falta definir darPrecioViaje; esperar por si hay que hacer algo diferente



#include "Usuario.h"

Usuario::Usuario(){}
Usuario::~Usuario(){}
void Usuario::setCedula(String c){
	this->cedula=c;
}
String Usuario::getCedula(){
	return this->cedula;
}
void Usuario::setNombre(String n){
	this->nombre=n;
}
String Usuario::getNombre(){
	return this->nombre;
}
void Usuario::setFechaIngreso(DtFecha f){
	this->fechaIngreso=f;
}
DtFecha Usuario::getFechaIngreso(){
	return this->fechaIngreso;
}


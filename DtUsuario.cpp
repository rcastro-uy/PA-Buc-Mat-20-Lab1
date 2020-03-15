
#include "DtUsuario.h"

DtUsuario::DtUsuario(){}
DtUsuario::~DtUsuario(){}
String DtUsuario::getCedula(){
       return cedula;
}
String DtUsuario::getNombre(){
	return nombre;
}
DtFecha DtUsuario::getFechaIngreso(){
	return fechaIngreso;
}

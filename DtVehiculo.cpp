#include "DtVehiculo.h"
using namespace std;

DtVehiculo::DtVehiculo(){}
DtVehiculo::DtVehiculo(int a,float b ,float c){
	this->nroSerie=a;
	this->porcentajeBateria=b;
	this->precioBase=c;
}
DtVehiculo::~DtVehiculo(){}
int DtVehiculo::getNroSerie(){
	return nroSerie;
}
float DtVehiculo::getPorcentajeBateria(){
	return porcentajeBateria;
}
float DtVehiculo::getPrecioBase(){
	return precioBase;
}

ostream& operator <<(ostream& s,const DtVehiculo& v){
	cout << " - Numero serie: " << v.nroSerie;
	cout << " - Porcentaje bateria: " << v.porcentajeBateria;
	cout << " - Precio base: $" << v.precioBase;
	return s;
}

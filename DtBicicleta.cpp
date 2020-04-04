#include "DtBicicleta.h"
#include "TipoBici.h"
#include <iostream>
using namespace std;

DtBicicleta::DtBicicleta(){}

DtBicicleta::DtBicicleta(int nroSerie,float porBateria,float precioBase,TipoBici tb,int cambios):DtVehiculo(nroSerie,porBateria,precioBase){
    this->tipo=tb;
    this->cantCambios=cambios;
}

DtBicicleta::~DtBicicleta(){}

TipoBici DtBicicleta::getTipoBici(){
    return this->tipo;
}

void DtBicicleta::setTipoBici(TipoBici t){
    this->tipo=t;
}

int DtBicicleta::getCantCambios(){
    return this->cantCambios;
}

void DtBicicleta::setCantCambios(int c){
    this->cantCambios=c;
}

ostream& operator <<(ostream& s,DtBicicleta& v){
    cout << (DtVehiculo) v;
    cout << " - Tipo de Bicicleta: " << v.tipo << endl;
    cout << " - Cantidad de cambios: " << v.cantCambios << endl; 
    return s;
}

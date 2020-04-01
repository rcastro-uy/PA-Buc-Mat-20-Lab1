#include "DtBicicleta.h"
#include "TipoBici.h"
#include <iostream>
using namespace std;

DtBicicleta::DtBicicleta(){}

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
    cout << " - Tipo de Bicicleta: " << v.tipo;
    cout << " - Cantidad de cambios: " << v.cantCambios; 
    return s;
}

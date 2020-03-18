
#include "DtBicicleta.h"
#include "TipoBici.h"

DtBicicleta::DtBicicleta(){}

DtBicicleta::~DtBicicleta(){}

TipoBici DtBicicleta::getTipoBici(){
    return this->tipo;
}

void DtBicicleta::setTipoBici(TipoBici t){
    this->tipo=t;
}

int DtBicicleta::getcantCambios(){
    return this->cantCambios;
}

void DtBicicleta::setcantCambios(int c){
    this->cantCambios=c;
}

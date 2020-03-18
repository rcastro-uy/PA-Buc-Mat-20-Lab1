
#include "DtMonopatin.h"

DtMonopatin::DtMonopatin():Vehiculo(){}
DtMonopatin::~Bicicleta():~Vehiculo(){}

bool DtMonopatin::getTieneLuces(){
    if(tieneLuces){
        return true;
    }else{
        return false;
    }
}

void DtMonopatin::setTienLuces(bool b){
    this->tieneLuces=b;
}

float DtMonopatin::darPrecioViaje():Vehiculo(){
    int precio;
    if(this->tieneLuces){
        precio = 0.5 * duracion + distancia * precioBase;
    }else{
        precio = distancia * precioBase;
    }
}

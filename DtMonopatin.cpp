
#include "DtMonopatin.h"
#include <iostream>
using namespace std;

DtMonopatin::DtMonopatin(){}
DtMonopatin::DtMonopatin(bool b){
    this->tieneLuces=b;
}
DtMonopatin::~DtMonopatin(){}

bool DtMonopatin::getTieneLuces(){
    if(tieneLuces){
        return true;
    }else{
        return false;
    }
}

void DtMonopatin::setTieneLuces(bool b){
    this->tieneLuces=b;
}


ostream& operator <<(ostream& s,DtMonopatin& v){
    cout << (DtVehiculo) v;
    if(v.tieneLuces){
        cout << " - Tiene luces: Si";
    }else{
        cout << " - Tiene luces: No";
    }
    return s;
}

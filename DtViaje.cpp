#include "DtViaje.h"
#include "DtVehiculo.h"
using namespace std;

    DtViaje::DtViaje(){}
    DtViaje::DtViaje(float precioTotal,DtVehiculo vehiculo){
        this->precioTotal=precioTotal;
        this->vehiculo=vehiculo;
    }
    DtViaje::~DtViaje(){}

    void DtViaje::setPrecioTotal(float precioTotal){
        this->precioTotal=precioTotal;
    } 
    float DtViaje::getPrecioTotal(){
        return this->precioTotal;
    }
    void DtViaje::setVehiculo(DtVehiculo vehiculo){
        this->vehiculo=vehiculo;
    }
    DtVehiculo DtViaje::getVehiculo(){
        return this->vehiculo;
    }

    ostream& operator <<(ostream& sal,const DtViaje& v){
        cout << v.precioTotal;
        return sal;
    }
#ifndef Vehiculo.h
#define Vehiculo.h

using namespace std;

class DtVehiculo{
	private:
		int nroSerie;
		float porcentajeBateria;
		float precioBase;
	public:
		DtVehiculo();
		~DtVehiculo();
		int getNroSerie();
		float getPorcentajeBateria();
		float getPrecioBase();
		float darPrecioViaje(int,int);

};


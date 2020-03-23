#ifndef Vehiculo
#define Vehiculo

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


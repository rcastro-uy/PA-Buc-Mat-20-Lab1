#ifndef Vehiculo
#define Vehiculo

using namespace std;

class Vehiculo{
	private:
		int nroSerie;
		float porcentajeBateria;
		float precioBase;

	public:
		Vehiculo();
		~Vehiculo();

		void setNroSerie(int);
		int getNroSerie();
		void setPorcentajeBateria(float);
		float getPorcentaBateria();
		void setPrecioBase(float);
		float getPrecioBase();

		float darPrecioViaje(int,int);
};

#endif

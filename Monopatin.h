#ifndef MONOPATIN
#define MONOPATIN
using namespace std;

class Monopatin: public Vehiculo{
	private:
		bool tieneLuces;
	public:
		Monopatin();
		~Monopatin();
		void setTieneLuces(bool);
		bool getTieneLuces();

		float darPrecioViaje(int,int);
};

#endif
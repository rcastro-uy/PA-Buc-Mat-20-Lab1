#ifndef Bicicleta.h
#define Bicicleta.h

#include "TipoBici.h"

using namespace std;

class Bicicleta{
	private:
		TipoBici tipo;
		int cantCambios;
	public:
		Bicicleta();
		~Bicicleta();
		void setTipo(TipoBici);
		TipoBici getTipo();
		void setCantCambios(int);
		int getCantCambios();
//falta darPrecioViaje
};

#endif

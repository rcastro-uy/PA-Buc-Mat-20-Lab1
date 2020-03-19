#ifndef Viaje
#define Viaje

#include "DtFecha.h"

using namespace std;

class Viaje{

    private:

        int duracion;
        int distancia;
        DtFecha fecha;

    public:

        Viaje();

        void setDuracion(int);
        int getDuracion();

        void setDistancia(int);
        int getDistancia();

        void setFecha(DtFecha);
		DtFecha getFecha();
        
        ~Viaje();



};





#endif
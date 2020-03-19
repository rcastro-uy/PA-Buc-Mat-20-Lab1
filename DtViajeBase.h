#ifndef DtViajeBase
#define DtViajeBase

#include "DtFecha.h"

using namespace std;

class ViajeBase{

    private:

        int duracion;
        int distancia;
        DtFecha fecha;

    public: 

        DtViajeBase();   

        int getDuracion(); 

        int getDistancia();
        
		DtFecha getFecha();

        ~DtViajeBase(); 
};
#endif 
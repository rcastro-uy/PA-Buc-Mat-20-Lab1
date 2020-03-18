#ifndef DtBicicleta
#define DtBicicleta

#include "DtVehiculo.h"
#include "TipoBici.h"

using namespace std;

class DtBicicleta: public DtVehiculo{
    private:
        TipoBici tipo;
        int cantCambios;
    public:
        DtBicicleta();
        DtBicicleta(TipoBici,int);
        
        TipoBici getTipoBici();
        void setTipoBici(TipoBici);
        int getcantCambios();
        void setcantCambios(TipoBici);

        ~DtBicicleta();
        float darPrecioViaje(int duracion)







};
#endif
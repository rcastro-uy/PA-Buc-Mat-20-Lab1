#ifndef DtMonopatin
#define DtMonopatin

#include "DtVehiculo.h"

using namespace std;

class DtMonopatin : public DtVehiculo{
    private:
        bool tieneLuces;
    public:
        DtMonopatin();
        DtMonopatin(bool);

        bool getTieneLuces();
        void setTieneLuces(bool);

        float darPrecioViaje();
        ~DtMonopatin();
};

#endif
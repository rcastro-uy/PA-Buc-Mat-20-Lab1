#ifndef DTMONOPATIN
#define DTMONOPATIN
#include "DtVehiculo.h"
using namespace std;

class DtMonopatin : public DtVehiculo{
    private:
        bool tieneLuces;
    public:
        DtMonopatin();
        DtMonopatin(int,float,float,bool);

        bool getTieneLuces();
        void setTieneLuces(bool);

        ~DtMonopatin();
        friend ostream& operator <<(ostream&,DtMonopatin&);
};

#endif
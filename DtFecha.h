#ifndef DTFECHA
#define DTFECHA

class DtFecha{
    private:
        int dia;
        int mes;
        int anio;
    public: 
        DtFecha();
        DtFecha(int,int,int);
        ~DtFecha();

        void setDia(int);
        int getDia();

        void setMes(int);
        int getMes();

        void setAnio(int);
        int getAnio(); 
};
#endif 
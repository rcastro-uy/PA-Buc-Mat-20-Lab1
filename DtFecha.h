#ifndef DtFecha
#define DtFecha
class DtFecha{
    private:
        int dia;
        int mes;
        int anio;
    public: 
        DtFecha();
        ~DtFecha();

        void setDia(int);
        int getDia();

        void setMes(int);
        int getMes();

        void setAnio(int);
        int getAnio(); 
};
#endif 
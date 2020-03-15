#ifndef Usuario
#define Usuario

#include "DtFecha.h"

using namespace std;

class Usuario{
	private:
		String cedula;
		String nombre;
		DtFecha fechaIngreso;
	public:
		Usuario();
		~Usuario();
		void setCedula(String);
		String getCedula();
		void setNombre(String);
		String getNombre();
		void setFechaIngreso(DtFecha);
		DtFecha getFechaIngreso();

};





#endif

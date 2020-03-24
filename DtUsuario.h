#ifndef DtUsuario
#define DtUsuario
#include "DtFecha.h"

using namespace std;

class DtUsuario{
	private:
		String cedula;
		String nombre;
		DtFecha fechaIngreso;
	public:
		DtUsuario();
		~DtUsuario();
		String getCedula();
		String getNombre();
		DtFecha getFechaIngreso();

};

#endif

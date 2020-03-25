
#include "Bicicleta.h"
#include "DtBicicleta.h"
#include "DtFecha.h"
#include "DtMonopatin.h"
#include "DtVehiculo.h"
#include "DtViajeBase.h"
#include "Monopatin.h"
#include "TipoBici.h"
#include "Usuario.h"
#include "Vehiculo.h"
#include "Viaje.h"
#include <iostream>
#define MAX_USUARIOS 50
//#define MAX_VEHICULOS 100

using namespace std;

struct coleccionUsuarios{
	Usuario* usuarios[MAX_USUARIOS];
	int tope;
};


//REVISADO HASTA ACA


//Prototipos
//void ingresarViaje();
//void ingresarViaje(string ci,int nroSerieVehiculo,DtViajeBase& viaje);



// ingresarViaje

/*
void ingresarViaje(){
	string ci;
	int nroSerie;
	DtViajeBase viaje;
	cout << "Ingrese su cedula: ";
	cin >> ci;
	cout << "Ingrese numero de serie del vehiculo" << endl;
	cin >> nroSerie;
	cout << 

	try{
		if(existeUsuario(ci) && existeVehiculo(nroSerie)){



		}



	}catch(){

	}




}

void ingresarViaje(string ci, int nroSerieVehiculo, DtViajeBase& viaje){


	if(duracion > 0 && distancia > 0)


	if()

}
*/

//REVISADO EL MAIN


int main(){

	int opcion;

	system("clear");
	cout << "Bienvenido. Elija la opción." << endl;
	cout << "1) Registrar usuario" << endl;
	cout << "2) Agregar vehículo" << endl;
	cout << "3) Ingresar viaje" << endl;
	cout << "4) Ver viajes antes de.." << endl;
	cout << "5) Eliminar viajes" << endl;
	cout << "6) Cambiar bateria vehículo" << endl;
	cout << "7) Obtener vehículos" << endl;
	cout << "0) Salir" << endl;
	cout << "Opción:";
	cin >> opcion;
		switch(opcion){
			case 1: //registrarUsuario(ci,nombre);
				break;
			case 2: //agregarVehiculo(vehiculo);
				break;
			case 3: //ingresarViaje(ci,nroSerieVehiculo,viaje);
				break;
			case 4: //verViajesAntesDeFecha(fecha,ci,cantViajes);
				break;
			case 5: //eliminarViajes(ci,fecha);
				break;
			case 6: //cambiarBateriaVehiculo(nroSerieVehiculo,cargaVehiculo);
				break;
			case 7: //obtenerVehiculos(cantVehiculos);
				break;
			case 0: system("exit");
				break;
			default:
				cout << "Opción incorrecta" << endl;
		}

	return 0;
	
}

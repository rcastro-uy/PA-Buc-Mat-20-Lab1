
#include "Bicicleta.h"
#include "DtBicicleta.h"
#include "DtFecha.h"
#include "DtMonopatin.h"
#include "DtVehiculo.h"
#include "DtViajeBase.h"
#include "DtViaje.h"
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
void ingresarViaje();
void ingresarViaje(string ci,int nroSerie,DtViajeBase& viajeB);
float darPrecioViaje(int duracion,int distancia);



// ingresarViaje


void ingresarViaje(){
	string ci;
	int nroSerie;
	DtViajeBase viajeB;
	DtFecha fecha;
	int dia, mes, anio, duracion, distancia;
	cout << "Ingrese su cedula: ";
	cin >> ci;
	cout << "Ingrese numero de serie del vehiculo" << endl;
	cin >> nroSerie;
	try{
		existeUsuario(ci);
		existeVehiculo(nroSerie);
		cout <<  "Ingrese dia: ";
		cin >> dia;
		cout << "Ingrese mes: ";
		cin >> mes;
		cout << "Ingrese anio: ";
		cin >> anio;
		fecha=DtFecha(dia,mes,anio);
		cout << "Ingrese la duracion del viaje: ";
		cin >> duracion;
		cout << "Ingrese la distancia del viaje: ";
		cin >> distancia;
		if(duracion > 0 && distancia > 0){
			darPrecioViaje();
			viajeB=DtViajeBase(duracion,distancia,fecha);
			ingresarViaje(ci,nroSerie,viajeB);
		}else{
			cout << "La distancia y duracion deben ser mayor a 0";
		}

	}catch(invalid_argument& e){
		cout << e.what() << endl;
	}
}

void ingresarViaje(string ci, int nroSerieVehiculo, DtViajeBase& viajeB){
	try{
		Usuario* usuario = obtenerUsuario(ci);
		Vehiculo* vehiculo = obtenerVehiculo(nroSerie);
		





		usuario->ingresarViaje()
		DtViaje* dtv = new DtViaje(darPrecioViaje(viajeB.getDuracion(),viajeB.getDistancia()),vehiculo);
		Viaje* v = new Viaje(dtv.getDuracion(),dtv.getDistancia(),viajeB.getFecha());


	}catch(){

	}

}

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
			case 3: ingresarViaje();
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

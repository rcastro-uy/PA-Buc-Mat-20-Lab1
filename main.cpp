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
#include "DtViaje.h"
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;
#define MAX_USUARIOS 30
#define MAX_VEHICULOS 100

struct{
	Usuario* usuarios[MAX_USUARIOS];
	int tope;
} coleccionUsuarios;

struct{
	Vehiculo* vehiculos[MAX_VEHICULOS];
	int tope;
} coleccionVehiculos;


//Prototipos
void porcentajeValido(float);
void precioBaseValido(float);
void existeVehiculo(int);

Usuario* obtenerUsuario (string);

void ingresarViaje();
void ingresarViaje(string ci,int nroSerie,DtViajeBase& viajeB);


void precioBaseValido(float pb){
    if(pb<=0)
        throw invalid_argument("Precio base inválido; debe ser mayor a 0\n");
}

void existeVehiculo(int nroSerie){
    int i=0;
    // bool existe=true;
    while(i<coleccionVehiculos.tope){//&&(existe)){
        if(nroSerie==coleccionVehiculos.vehiculos[i]->getNroSerie())
            throw invalid_argument("Ya existe ese vehículo\n");
        i++;
    }
}

void existeUsuario(string ci){
    int i=0;
    bool existe=false;
    while((!existe)&&(i<coleccionUsuarios.tope)){
        if(ci==coleccionUsuarios.usuarios[i]->getCedula())
            existe=true;
        else
            i++;
        }
        if(existe)
            throw invalid_argument("ERROR: YA EXISTE USUARIO CON ESA CI EN EL SISTEMA\n");
}

Usuario* obtenerUsuario(string ci){ //falta probar
    Usuario* user;
	bool existe=false;
	int i=0;
	while((i<coleccionUsuarios.tope)&&(!existe)){
		if(ci==coleccionUsuarios.usuarios[i]->getCedula()){
			user=coleccionUsuarios.usuarios[i];
			existe=true;
		}
		i++;
	}
	return user;
}

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


		existeVehiculo(nroSerie);
        // Comprobar si existe el vehiculo

        precioBaseValido(duracion);
		precioBaseValido(distancia);
		// Comprobar si el precio es valido

		// Comprobar que existe el usuario

		viajeB=DtViajeBase(duracion,distancia,fecha);
		ingresarViaje(ci,nroSerie,viajeB);


	}catch(invalid_argument& e){
		cout << e.what() << endl;
	}
}

void ingresarViaje(string ci, int nroSerieVehiculo, DtViajeBase& viajeB){
	try{
		Usuario* usuario = obtenerUsuario(ci);
		Vehiculo* vehiculo = obtenerVehiculo(nroSerie);
		//usuario->ingresarViaje()
		DtViaje* dtv = new DtViaje(vehiculo->darPrecioViaje(viajeB.getDuracion(),viajeB.getDistancia()),vehiculo);
		Viaje v = new Viaje(dtv->getDuracion(),dtv->getDistancia(),viajeB.getFecha());

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

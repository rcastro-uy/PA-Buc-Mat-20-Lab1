#include <stdio.h>
#include <iostream>
#include <stdexcept> //funcion invaid_argument
#include <stdlib.h> //funcion system
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

using namespace std;
#define MAX_USER 30
#define MAX_VEHICULOS 100

struct{
	Usuario* usuarios[MAX_USER];
	int tope;
} coleccionUsuarios;

struct{
	Vehiculo* vehiculos[MAX_VEHICULOS];
	int tope;
} coleccionVehiculos;

void existeUsuario(string ci);
Usuario* obtenerUsuario (string);
Vehiculo* obtenerVehiculo(int nroSerie);
void existeVehiculo(int);
void porcentajeValido(float);
void precioBaseValido(float);
void valorPositivo(int);
void fechaValida(DtFecha,string);

//Prototipos
void ingresarViaje();
void ingresarViaje(string ci,int nroSerieVehiculo,DtViajeBase& viaje);

void valorPositivo(int d){
	if(d<=0)
		throw invalid_argument("El valor debe ser positivo\n");
}

void fechaValida(DtFecha f, string ci){
	Usuario* user = obtenerUsuario(ci);
	if(f < user->getFechaIngreso())
		throw invalid_argument("La fecha del viaje debe ser posterior o igual a la fecha de ingreso del usuario\n");
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
		if(ci == coleccionUsuarios.usuarios[i]->getCedula()){
			user=coleccionUsuarios.usuarios[i];
			existe=true;
		}
		i++;
	}
	return user;
}

Vehiculo* obtenerVehiculo(int nroSerie){ //falta probar
    Vehiculo* vehiculo;
	bool existe=false;
	int i=0;
	while((i<coleccionVehiculos.tope)&&(!existe)){
		if(nroSerie==coleccionVehiculos.vehiculos[i]->getNroSerie()){
			vehiculo=coleccionVehiculos.vehiculos[i];
			existe=true;
		}
		i++;
	}
	return vehiculo;
}


void ingresarViaje(){
	string ci;
	int nroSerieVehiculo;
	int dia, mes, anio, duracion, distancia;
	cout << "Ingrese su cedula: ";
	cin >> ci;
	cout << "Ingrese numero de serie del vehiculo: ";
	cin >> nroSerieVehiculo;
	try{

		existeUsuario(ci);
		// Comprobar si existe el Usuario

		existeVehiculo(nroSerieVehiculo);
        // Comprobar si existe el vehiculo
		
		cout << "Ingrese dia: ";
		cin >> dia;
		cout << "Ingrese mes: ";
		cin >> mes;
		cout << "Ingrese anio: ";
		cin >> anio;
		cout << "Ingrese la duracion del viaje: ";
		cin >> duracion;
		cout << "Ingrese la distancia del viaje: ";
		cin >> distancia;

        valorPositivo(duracion);

		valorPositivo(distancia);
		// Comprobar si la distancia y duracion son validas

		DtFecha fecha=DtFecha(dia,mes,anio);
		Usuario* usuario = obtenerUsuario(ci);

		fechaValida(fecha,ci);
		// Comprobar si la fecha del viaje es posterior o igual a la fecha de ingreso del usuario

		DtViajeBase viaje = DtViajeBase(duracion,distancia,fecha);
		ingresarViaje(ci,nroSerieVehiculo,viaje);

	}catch(std::invalid_argument& e){
		cout << e.what() << endl;
	}
}

void ingresarViaje(string ci, int nroSerieVehiculo, DtViajeBase& viaje){
	try{


		// obtener Usuario 
		Usuario* usuario = obtenerUsuario(ci);

		// Obtener Vehiculo
		Vehiculo* vehiculo; //= obtenerVehiculo(nroSerieVehiculo);

		// obtener dtVehiculo
		DtVehiculo *dtve;// = obtenerDtVehiculo(nroSerieVehiculo);

		float precioViaje;
		
		try{
			DtBicicleta& bici = dynamic_cast<DtBicicleta&>(dtve);
			Bicicleta* bic = new Bicicleta(bici.getNroSerie(),bici.getPorcentajeBateria(),bici.getPrecioBase(),bici.getTipoBici(),bici.getCantCambios());
			precioViaje = bic->darPrecioViaje(viaje.getDuracion(),viaje.getDistancia());
		}catch(bad_cast){
			try{
			DtMonopatin& monop = dynamic_cast<DtMonopatin&>(dtve);
			Monopatin* mono = new Monopatin(monop.getNroSerie(),monop.getPorcentajeBateria(),monop.getPrecioBase(),monop.getTieneLuces());
			precioViaje = mono->darPrecioViaje(viaje.getDuracion(),viaje.getDistancia());
			}catch(bad_cast){	
			}
		
		}
		
		// Crear dtViaje
		DtViaje* dviaje = new DtViaje(viaje.getDuracion(),viaje.getDistancia(),viaje.getFecha(),precioViaje,dtve);


		// Crear Viaje
		Viaje* viajea = new Viaje(viaje.getDuracion(),viaje.getDistancia(),viaje.getFecha(),vehiculo);
		usuario->agregarViaje(viajea);

	}catch(std::invalid_argument& e){
		cout << e.what() << endl;
	}

}


int main(){

	DtFecha fecha = DtFecha(25,8,2020);
	Usuario u = Usuario("55213703","Mauricio",fecha);
	DtMonopatin v = DtMonopatin(52617,50,100,true);

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
			case 1: //registrarUsuario();
				break;
			case 2: //agregarVehiculo();
				break;
			case 3: ingresarViaje();
				break;
			case 4: //verViajesAntesDeFecha();
				break;
			case 5: //eliminarViajes();
				break;
			case 6: //cambiarBateriaVehiculo();
				break;
			case 7: //obtenerVehiculos();
				break;
			case 0: system("exit");
				break;
			default:
				cout << "Opción incorrecta" << endl;
		}

	return 0;
	
}

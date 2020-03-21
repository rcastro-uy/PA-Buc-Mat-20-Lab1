#define MAX_USUARIOS 100
#define MAX_VEHICULOS 30
#include "Usuario.h"
#include "Viaje.h"
#include "Vehiculo.h"
#include "Monopatin.h"
#include "Bicicleta.h"
#include "DtFecha.h"
#include "DtViajeBase.h"
#include "DtViaje.h"
#include "DtVehiculo.h"
#include "DtMonopatin.h"
#include "DtBicicleta.h"

#include <iostream>

using namespace std;

//void registrarUsuario(string ci,string nombre);

//void agregarVehiculo(DtVehiculo& vehiculo);

void ingresarViaje();
void ingresarViaje(string ci,int nroSerieVehiculo,DtViajeBase& viaje);

//DtViaje** verViajesAntesDeFecha(DtFecha& fecha,string ci,int& cantViajes);

//void eliminarViajes(string ci,DtFecha& fecha);

//void cambiarBateriaVehiculo(int nroSerieVehiculo,float cargaVehiculo);

//DtVehiculo** obtenerVehiculos(int& cantVehiculos);


//OPERACION A
void registrarSocio();
void registrarSocio(string,string,DtMascota&);
//OPERACION B
void agregarMascota();
void agregarMascota(string,DtMascota&);
//OPERACION C
void ingresarConsulta();
void ingresarConsulta(string,string,DtFecha&);
//OPERACION D
void verConsultasAntesDeFecha();
DtConsulta** verConsultasAntesDeFecha(DtFecha&,string,int&);
//OPERACION E
void eliminarSocio();
void eliminarSocio(string ci);
//OPERACION F
void obtenerMascotas();
DtMascota** obtenerMascotas(string,int&);
//OPERACIONES AUXILIARES
void existeSocio(string);
Socio* obtenerSocio(string);
void menu();
void cargarDatos();



// ingresarViaje mi funcion

void ingresarViaje(string ci, int nroSerieVehiculo, DtViajeBase& viaje){
	system("clear");

	cout <<"_____________________________________________" <<endl;
	cout <<"_____R E G I S T R A R___V I A J E S_____"<< endl;
	string ci;
	int nroSerieVehiculo;
	int dia,mes,anio;
	DtFecha dtFecha;
	cout << "CI: ";
	cin >> ci;
	try{


void existeSocio(string ci){
	int i=0;
	bool existe=false;
	while((i<coleccionSocios.tope)&&(!existe)){

		if(ci == coleccionSocios.socios[i]->getCi())
			existe=true;
		i++;
	}
	if (!existe)
		throw invalid_argument("ERROR: NO EXISTE USUARIO CON ESA CI EN EL SISTEMA\n");
}




		existeSocio(ci);
		cout << endl;
		cout << "MOTIVO: ";
		cin >> motivo;
		cout << endl;
		cout << "DIA: ";
		cin >> dia;
		cout << endl;
		cout << "MES: ";
		cin >> mes;
		cout << endl;
		cout << "ANIO: ";
		cin >> anio;
		cout << endl;
		dtFecha=DtFecha(dia,mes,anio);
		ingresarConsulta(motivo,ci,dtFecha);
	}catch(invalid_argument& e){
		cout << e.what() << endl;
	}
}

void ingresarViaje(string ci,int nroSerieVehiculo,DtViajeBase& viaje){
void ingresarViaje(string motivo,string ci,DtFecha& dtFecha)
	Usuario* usuario = obtenerSocio(ci);
	Consulta* consulta = new Consulta(viaje,ci);
	usuario->agregarConsulta(consulta);
	cout << "SE HA INGRESADO EL VIAJE CORRECTAMENTE AL USUARIO DE CI: " << ci <<endl;
}



//OPERACION D
void verConsultasAntesDeFecha(){
	system("clear");
	cout <<"_________________________________________________" <<endl;
	cout <<"__V E R__L I S T A D O__ D E__C O N S U L T A S__"<< endl;
	string ci;
	int dia,mes,anio,cantConsultas, cantMostrar;
	DtFecha dtFecha;
	cout << "CI: ";
	cin >> ci;
	cout << "\nDIA: ";
	cin >> dia;
	cout << "\nMES: ";
	cin >> mes;
	cout << "\nANIO: ";
	cin >> anio;
	cout << "\nCuantas consultas?: ";
	cin >> cantConsultas;
	dtFecha = DtFecha(dia,mes,anio);
	cout << "\nCONSULTAS ANTES DE " << dia << "/" << mes << "/" << anio << ": " << endl;
	DtConsulta** consultas = verConsultasAntesDeFecha(dtFecha,ci,cantConsultas);
	for (int i = 0; i < cantConsultas; i++)
		cout << "\n\n" << *(consultas[i]);
}
DtConsulta** verConsultasAntesDeFecha(DtFecha& dtFecha,string ci,int& cantConsultas){
	Socio* socio = obtenerSocio(ci);
	if(cantConsultas>socio->getTopeConsultas())
		cantConsultas=socio->getTopeConsultas();
	Consulta** consultas = socio->obtenerConsultas();
	DtConsulta** dtConsultas = new DtConsulta*[cantConsultas];
	DtConsulta* dtConsulta;
	int i=0,j=0;
	while(i<cantConsultas){
		cout << consultas[j]->getMotivo() << endl;
		if ((consultas[j]->getFechaConsulta()) < dtFecha){
			dtConsulta= new DtConsulta(consultas[i]->getFechaConsulta(),consultas[i]->getMotivo());
			dtConsultas[i]=dtConsulta;
			i++;
		}
		j++;
	}
	return dtConsultas;
}



//OPERACION E
void eliminarSocio(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"_________E L I M I N A R__S O C I O__________"<< endl;
	string ci;
	cout << "CI: ";
	cin >> ci;
	cout << endl;
	try{
		existeSocio(ci);
		eliminarSocio(ci);
		cout << "SE HA ELIMINADO EL SOCIO DE CI: "<< ci <<endl;
	}catch(invalid_argument& e){
		cout << e.what() << endl;
	}
}
void eliminarSocio(string ci){
	int i=0;
	while(ci != coleccionSocios.socios[i]->getCi())
		i++;
	delete coleccionSocios.socios[i];
	coleccionSocios.socios[i]=coleccionSocios.socios[coleccionSocios.tope-1];
	coleccionSocios.tope--;
}



//OPERACION F
void obtenerMascotas(){
	system("clear");
	cout <<"_________________________________________________" <<endl;
	cout <<"___V E R__L I S T A D O__ D E__M A S C O T A S___"<< endl;
	string ci;
	int cantMascotas;
	DtPerro* perro;
	DtGato* gato;
	cout << "CI: ";
	cin >> ci;
	cout << endl;
	try{
		existeSocio(ci);
		cout << "Cuantas mascotas?: ";
		cin >> cantMascotas;
		cout << endl;
		DtMascota** dtMascotas = obtenerMascotas(ci,cantMascotas);
		cout << "MASCOTAS DEL SOCIO DE CI: " << ci <<endl;
		for (int i = 0; i < cantMascotas; i++){
			perro = dynamic_cast<DtPerro*>(dtMascotas[i]);
			if (perro!=NULL)
				cout << "\n\n" << *(perro);
			else{
				gato = dynamic_cast<DtGato*>(dtMascotas[i]);
				if (gato!=NULL)
					cout << "\n\n" << *(gato);	
			}
			cout << "-------------------------"<< endl;	
		}
	}catch(invalid_argument& e){
		cout << e.what() << endl;
	}
}
DtMascota** obtenerMascotas(string ci,int& cantMascotas){
	Socio* socio = obtenerSocio(ci);
	Mascota** mascotas = socio->obtenerMascotas();
	DtPerro* dtPerro;
	DtGato* dtGato;
	if(cantMascotas>socio->getTopeMascotas())
		cantMascotas=socio->getTopeMascotas();
	DtMascota** dtMascotas = new DtMascota*[cantMascotas];
	for(int i=0;i<cantMascotas;i++){
		if(Perro* perro = dynamic_cast<Perro*>(mascotas[i])){
				dtPerro = new DtPerro(perro->getNombre(),perro->getGenero(),perro->getPeso(),perro->obtenerRacionDiaria(),perro->getRaza(),perro->getVacunaCachorro());
				dtMascotas[i]=dtPerro;
		}else{
			if(Gato* gato = dynamic_cast<Gato*>(mascotas[i])){
					dtGato = new DtGato(gato->getNombre(),gato->getGenero(),gato->getPeso(),gato->obtenerRacionDiaria(),gato->getTipoPelo());
					dtMascotas[i]=dtGato;
			}
		}
	}
	return dtMascotas;
}




Socio* obtenerSocio(string ci){
	Socio* socioObtenido;
	int i=0;
	bool existe=false;
	while((i<coleccionSocios.tope)&&(!existe)){
		if(ci == coleccionSocios.socios[i]->getCi()){
			socioObtenido=coleccionSocios.socios[i];
			existe=true;
		}
		i++;
	}
	return socioObtenido;
}


void cargarDatos(){
	//REGISTRANDO SOCIOS
	DtPerro dtp= DtPerro("Billi",MACHO,11,0,LABRADOR,true);
	DtGato dtg= DtGato("Tom",MACHO,6,0,CORTO);
	registrarSocio("49335620","Yonathan",dtp);
	registrarSocio("40037741","Cristhian",dtg);
	cout << "EXISTEN " << coleccionSocios.tope << " SOCIOS"<<endl;
	cout << coleccionSocios.socios[0]->getNombre() << " " << coleccionSocios.socios[0]->getCi() << endl;
	cout << coleccionSocios.socios[1]->getNombre() << " " << coleccionSocios.socios[1]->getCi() << endl;
	cout << coleccionSocios.socios[0]->getCi() << " " << coleccionSocios.socios[0]->getTopeMascotas() << endl;
	cout << coleccionSocios.socios[1]->getCi() << " " << coleccionSocios.socios[1]->getTopeMascotas() << endl;
	//REGISTRANDO MASCOTAS A SOCIOS
	DtPerro dtp1= DtPerro("Kinki",HEMBRA,9,0,OVEJERO,false);
	DtGato dtg2= DtGato("Maniri",HEMBRA,3,0,LARGO);
	agregarMascota("49335620",dtp1);
	agregarMascota("40037741",dtg2);
	agregarMascota("40037741",dtp1);
	cout << coleccionSocios.socios[0]->getCi() << " " << coleccionSocios.socios[0]->getTopeMascotas() << endl;
	cout << coleccionSocios.socios[1]->getCi() << " " << coleccionSocios.socios[1]->getTopeMascotas() << endl;
	//REGISTRANDO CONSULTAS
	DtFecha f15 = DtFecha(1,1,2015);
	DtFecha f16 = DtFecha(1,1,2016);
	DtFecha f17 = DtFecha(1,1,2017);
	DtFecha f18 = DtFecha(1,1,2018);
	ingresarConsulta("Consulta del 2015","49335620",f15);
	ingresarConsulta("Consulta del 2016","49335620",f16);
	ingresarConsulta("Consulta del 2017","49335620",f17);
	ingresarConsulta("Consulta del 2018","49335620",f18);
	ingresarConsulta("Consulta del 2015","40037741",f15);
	ingresarConsulta("Consulta del 2016","40037741",f16);
	ingresarConsulta("Consulta del 2017","40037741",f17);
	ingresarConsulta("Consulta del 2018","40037741",f18);
	cout << coleccionSocios.socios[0]->getCi() << " " << coleccionSocios.socios[0]->getTopeConsultas() << endl;
	cout << coleccionSocios.socios[1]->getCi() << " " << coleccionSocios.socios[1]->getTopeConsultas() << endl;
}



int main(){

	int opcion;

	system(clear);
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
	while(opcion != 0){
		switch(opcion){
			case 1: //registrarUsuario(ci,nombre);
				break;
			case 2: //agregarVehiculo(vehiculo);
				break;
			case 3: ingresarViaje(ci,nroSerieVehiculo,viaje);
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

	}

	return 0;
	
}

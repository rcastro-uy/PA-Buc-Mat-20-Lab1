#include<stdio.h>
#include<iostream>
#include<ctime>
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
#define MAX_USER 30

struct coleccionUsuarios{
	Usuario usuarios[MAX_USER];
	int tope;
};

bool cedulaVerif(int a){
    int arr[7];
    int res, aux;
    for(int i=7;i>=0;i--){
        arr[i] = a%10;
        a = a/10;
    }
    res = arr[0]*2 + arr[1]*9 + arr[2]*8 + arr[3]*7 + arr[4]*6 + arr[5]*3 + arr[6]*4;
    aux=res;
    while(aux%10 != 0){
        aux++;
    }
    aux = aux-res;
    if(aux == arr[7])
        return true;
    else
        return false;
}

void registrarUsuario(){
    string ci, nombre;
    cout << endl << "Cedula: ";
    cin >> ci;
    if(!cedulaVerif(ci))
        printf("Cédula invalida");
    else{
        bool cIgual=false;
        for(int i=0;i<coleccionUsuarios.tope;i++){
            coleccionUsuarios.usuarios[i].getCedula()
        }   
        cout << endl << "nombre: ";
        cin >> nombre;

    }
}
 
int main(){
    usuario valentin;
    string ci="49457795"
    valentin.setCedula(ci);
    printf("%s",coleccionUsuarios.usuarios[i].getCedula())
}

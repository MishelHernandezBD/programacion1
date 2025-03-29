#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

//Declaracion de constantes
#define NOTAS_INGRESADAS 4
#define NOTAS_ALUMNOS 5

//Variables
int notas [NOTAS_ALUMNOS][NOTAS_INGRESADAS];// Almacena las notas de los alumnos
int porcentajes [NOTAS_INGRESADAS][NOTAS_ALUMNOS]; //Porceentajes de los alumnos
int notasFinales [NOTAS_INGRESADAS][NOTAS_ALUMNOS];

//Funciones prototipos
void INGRESO_NOTAS ();
void CALCULO_PORCETAJES();
void CALCULO_FINALES ();

int main(){

    INGRESO_NOTAS();
    CALCULO_FINALES();
    return 0;
}

void INGRESO_NOTAS(){
    for (int j=0; j<NOTAS_ALUMNOS; j++){
        cout << "Ingrese las notas del alumno "<< j +1  <<": \n";
        for (int i=0; i<NOTAS_INGRESADAS; i++){
            cout << "Nota " << i+1 <<": ";
            cin >> notas[i];
            }
    }
}

void CALCULO_FINALES(){
    for (int i=0; i<NOTAS_ALUMNOS; i++){
        for (int j=0; i<NOTAS_INGRESADAS; j++){
            notasFinales[i][j] += notas[i][j];
        }
    }

    cout << "---Las notas finales--\n";
    cout << "\t\t1P\t2P\tACT\tEF" <<endl;
    for (int i=0; i<NOTAS_ALUMNOS; i++){
        cout << "n1. "<< i+1;
        for(int j=0; j<NOTAS_INGRESADAS; j++){
            cout << notas[i][j];
            cout << notasFinales[i][j];
        }
     }
}





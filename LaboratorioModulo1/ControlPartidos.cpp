#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iomanip>

using namespace std;

//Declaracion de constantes
#define nombres_candidatos 5
#define rondas 5
#define max_votos 50
#define min_votos 0
#define MAXIMA_LONGITUD_CADENA 100

//Matrices
char candidatos[nombres_candidatos][MAXIMA_LONGITUD_CADENA];
int resultados[nombres_candidatos][rondas];

//Prototipos de la funcion
void llamaCiclo(); //Funciòn que controla el Ciclo comparativo de datos por todas las facultades
int busquedaAleatorios(int minimo, int maximo);  //Funciòn que permite obtener valores aleatorios en las notas de cada alumno
void ingresarPartidos();
void llenarResultados();
void imprimirLinea();
void imprimirTabla();
void calcularEstadisticas();


int main(){
    srand(getpid()); //Proceso preparativo para generaciòn de valores aleatorios
    llamaCiclo();
    return 0;
}

void llamaCiclo(){
    char opcion; //almacenar las respuestas del usuario
    bool repetir = true;

    do {
        system("cls");
        cout << "* Eleccion de candidatos *\n\n";

        ingresarPartidos();
        llenarResultados();
        imprimirTabla();
        calcularEstadisticas();

        cout << "Desea generar otro campeonato (s/n)? ";
        cin >> opcion;
        if (opcion == 'n'|| opcion == 'N') {
            repetir = false;
        }
    } while (repetir);
}

//número aleatorio
int busquedaAleatorios(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void ingresarPartidos(){
    cout << "Ingrese los nombres de los candidatos 5 candidatos:\n";
    for (int i=0; i<nombres_candidatos; i++){
        cout <<"Candidato "<< i+1 <<": ";
        cin >> candidatos[i];
    }
}

//LLena la matriz con los resultados
void llenarResultados() {
    for (int j=0; j<rondas; j++){
        int votosRestantes = max_votos;
        int votosAsignados[nombres_candidatos] = {0};

        //Distribucion de votos
        for (int i=0; i< nombres_candidatos-1 ; i++){
            int candidatoAleatorio = busquedaAleatorios(0, nombres_candidatos -1);
            votosAsignados[candidatoAleatorio]++;
        }

        for (int i=0; i<nombres_candidatos; i++){
            resultados[i][j] = votosAsignados[i];
        }
    }
}

void imprimirLinea() {
    cout << "+--------";
    for(int i = 0; i < rondas; i++) {
        cout << "+---------";
    }
    cout << "+\n";
}

void imprimirTabla(){
    cout << "\nRESULTADOS DE LA ELECCION\n";
    imprimirLinea();

    cout <<"| Candidato     ";
    for (int i=0; i<rondas; i++){
        cout << "| Ronda " << i+1 << " ";
    }
    cout << "|\n";
    imprimirLinea();

    for (int i=0; i<nombres_candidatos; i++){
        cout << "| " << left << setw(15) << candidatos[i];
        for (int j=0; j<rondas; j++){
            cout << "| " << setw(7) << resultados[i][j];
        }
        cout << "|\n";
    }

    imprimirLinea();
}

void calcularEstadisticas(){
    int votosTotales [nombres_candidatos]= {0};
    int votosMaximos =0, votosMinimo = max_votos* rondas;
    int ganador = 0, perdedor =0;

    for (int i = 0; i < nombres_candidatos; i++) {
        for (int j = 0; j < rondas; j++){
            votosTotales[i] += resultados[i][j];
        }

        if (votosTotales[i] > votosMaximos){
            votosMaximos = votosTotales[i];
            ganador = i;
        }

        if (votosTotales[i] < votosMinimo){
            votosMinimo = votosTotales[i];
            perdedor = i;
        }
    }

    cout << "\nResultados Finales: \n";
    cout << "Ganador: " << candidatos[ganador] << " con " << votosMaximos << " votos.\n";
    cout << "Ultimo lugar: " << candidatos[perdedor] << " con " << votosMinimo << " votos.\n";
}




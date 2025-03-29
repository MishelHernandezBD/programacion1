#include "partidos.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

Partidos::Partidos()
{
    srand(time(0));
    reinicioEstadisticas();
}
int Partidos::resultadosAleatorios(int minimo, int maximo){
    return minimo + rand() % (maximo - minimo + 1);
}
void Partidos::calcularEstadisticas(){
    reinicioEstadisticas();
    for(int i = 0; i < NUMERO_EQUIPOS; i++) {
        for(int j = 0; j < NUMERO_EQUIPOS; j++) {
            if(i != j) { //verificar que no sea mismo equipo
                // partidos jugados
                estadisticas[i][0]++;

                // Actualizar goles
                estadisticas[i][4] += resultados[i][j][0]; // Goles a favor
                estadisticas[i][5] += resultados[i][j][1]; // Goles en contra

                // Actualizar resultados
                if(resultados[i][j][0] > resultados[i][j][1]) {
                    estadisticas[i][1]++; // suma una victoria
                    estadisticas[i][6] += 3; // Suma 3 puntos
                }
                else if(resultados[i][j][0] < resultados[i][j][1]) {
                    estadisticas[i][3]++; // Suma una derrota
                }
                else {
                    estadisticas[i][2]++;// Suma un empate
                    estadisticas[i][6] += 1; // Suma 1 punto
                }
            }
        }
    }
}

void Partidos::reinicioEstadisticas() {
    for(int i = 0; i < NUMERO_EQUIPOS; i++) {
        for(int j = 0; j < 7; j++) {
            estadisticas[i][j] = 0; // Reinicia todos los campos
        }
    }
}

void Partidos::imprimirLinea(){
    cout << "+--------";
    for(int i = 0; i < 7; i++) {
        cout << "+---------";
    }
    cout << "+\n";
}

void Partidos::ingresarEquipos(){
    cout << "Ingrese los nombres de los " << NUMERO_EQUIPOS << " equipos:" << endl;
    for(int i = 0; i < NUMERO_EQUIPOS; i++) {
        cout << "Equipo " << (i + 1) << ": ";
        cin >> equipos[i];
    }
}
void Partidos::llenarResultados(){
    for(int i = 0; i < NUMERO_EQUIPOS; i++) {
        for(int j = 0; j < NUMERO_EQUIPOS; j++) {
            if(i != j) {  // Evita que un equipo juegue contra sí mismo
                int golesIda = resultadosAleatorios(MINIMO_GOLES, MAXIMO_GOLES);
                int golesVuelta = resultadosAleatorios(MINIMO_GOLES, MAXIMO_GOLES);

                // Partido de ida
                resultados[i][j][0] = golesIda;
                resultados[i][j][1] = golesVuelta;

                // Partido de vuelta
                resultados[j][i][0] = golesVuelta;
                resultados[j][i][1] = golesIda;
            }
        }
    }
    calcularEstadisticas();
}
void Partidos::imprimirResultadosPartidos(){
    cout << "\nTabla de RESULTADOS de los Partidos:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Equipo"
         << "| " << setw(12) << left << "Equipo"
         << "| " << setw(9) << left << "Resultado" << "|" << endl;
    cout << "--------------------------------------------------" << endl;

    for(int i = 0; i < NUMERO_EQUIPOS; i++) {
        for(int j = i + 1; j < NUMERO_EQUIPOS; j++) {
            cout << "| " << setw(12) << left << equipos[i]
                 << "| " << setw(12) << left << equipos[j]
                 << "| " << setw(2) << resultados[i][j][0] << " -"
                 << setw(6) << left << resultados[i][j][1] << "|" << endl;
        }
    }
    cout << "--------------------------------------------------" << endl;
}
void Partidos::imprimirTabla(){
    cout << "Tabla de Posiciones:" << endl;
    imprimirLinea();
    cout << "| "<< setw(7) << "Equipo";
    cout << "| "<< setw(8) << "PJ";
    cout << "| "<< setw(8) << "PG";
    cout << "| "<< setw(8) << "PE";
    cout << "| "<< setw(8) << "PP";
    cout << "| "<< setw(8) << "GF";
    cout << "| "<< setw(8) << "GC";
    cout << "| "<< setw(8) << "Pts tot" << "| " << endl;
    imprimirLinea();

    int maxPuntos = -1, minPuntos = 999;
    int campeon = 0, ultimo = 0;

    for(int i = 0; i < NUMERO_EQUIPOS; i++) {
        cout << "| " << setw(7) << equipos[i];
        for(int j = 0; j < 7; j++) {
            cout << "| " << setw(8) << estadisticas[i][j];
        }
        cout << endl;
        imprimirLinea();

        if(estadisticas[i][6] > maxPuntos) {
            maxPuntos = estadisticas[i][6];
            campeon = i;
        }
        if(estadisticas[i][6] < minPuntos) {
            minPuntos = estadisticas[i][6];
            ultimo = i;
        }
    }

    cout << "Campeon: " << equipos[campeon]<< " con " << maxPuntos << " puntos" << endl;
    cout << "Desciende: " << equipos[ultimo] << " con " << minPuntos << " puntos" << endl;
}

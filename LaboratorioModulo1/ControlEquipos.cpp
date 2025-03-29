#include <iostream>

using namespace std;

const int numeroEquipo=6;

int main(){
    //Declaracion de variables
    string equipos[numeroEquipo];
    char opccion;
    bool repetir = true;

    //Declaracion de matrices
    int tabla[numeroEquipo][5]={};
    int resultados[numeroEquipo][numeroEquipo];

    do{
        int i, j;
        int puntosMaximo=0, puntosMinimo =100, indiceCampeon=0, indiceUltimo=0, contadorPartidos =1;

        //Ingreso de equipos
        cout << "Ingrese el nombre de los 6 equipos: \n";
        for ( i = 0; i<numeroEquipo; i++){
            cout << "Equipo "<< i+1 << ": ";
            cin >> equipos[i];
        }

        //Ingreso de resultados
        cout << "\nIngrese los marcadores de los partidos de ida y vuelta:\n";
        for ( i=0; i<numeroEquipo; i++){
            for ( j=0; j<numeroEquipo; j++){
                if (i != j){
                    cout <<"\n----------------------------------------------------\n";
                    cout << "Total de partidos: " << contadorPartidos++ << endl;
                    cout <<"----------------------------------------------------\n";

                    cout << equipos[i] << " vs " << equipos[j] << "--Goles de "<< equipos[i] <<": ";
                    cin >> resultados[i][j];

                    cout << equipos[j] << " vs " << equipos[i] << "--Goles de "<< equipos[j] <<": ";
                    cin >> resultados[j][i];
                }
                else {
                    resultados[i][j] = -1;
                }
            }
        }


        for (i=0; i<numeroEquipo; i++){
            for (j=0; j<numeroEquipo; j++){
                if (i != j){
                    tabla[i][0]++; //Partidos jugados
                    if (resultados [i][j] > resultados [j][i]){
                        tabla[i][1]++; // Partidos ganados
                        tabla[i][4] += 3; //Puntos ganados
                    }
                    else if (resultados[i][j] == resultados[j][i]){
                        tabla[i][2]++; //empate
                        tabla[i][4] +=1; //Puntos por empate
                    }
                    else
                        tabla [i][3]++; // partidos perdidos
                }
            }
            //Determinar al campeon
            if (tabla[i][4] > puntosMaximo){
                puntosMaximo = tabla[i][4];
                indiceCampeon = i;
            }
            if (tabla[i][4] < puntosMinimo){
                puntosMinimo = tabla[i][4];
                indiceUltimo = i;
            }
        }

        //Tabla
        cout << "\nTabla de posiciones:\n";
        cout << "Equipo\t\tPJ\tG\tE\tP\tPuntos\n";
        for (int i = 0; i < numeroEquipo; i++) {
            cout << equipos[i] << "\t\t" << tabla[i][0] << "\t"
                 << tabla[i][1] << "\t" << tabla[i][2] << "\t"
                 << tabla[i][3] << "\t" << tabla[i][4] << endl;
        }

        //Resultados
        cout << "\nEl ganador es: " << equipos[indiceCampeon] << " con " << puntosMaximo << " puntos";
        cout << "\nDescendido: " << equipos[indiceUltimo] << " con " << puntosMinimo << " puntos.\n";

        // Reiniciar la tabla para el nuevo torneo
        for (i = 0; i < numeroEquipo; i++) {
            for (int j = 0; j < 5; j++) {
                tabla[i][j] = 0;
            }
        }

        cout << "Desea realizar otro calculo (s/n)?";
        cin >> opccion;
        if (opccion =='n' || opccion=='N'){
            repetir = false;
        }

    }while (repetir);

    return 0;
}




#ifndef PARTIDOS_H
#define PARTIDOS_H

#include "equipos.h"
#include <iostream>

using namespace std;


//Declaración de Constantes
#define NUMERO_EQUIPOS 6
#define MAXIMO_GOLES 10
#define MINIMO_GOLES 0

class Partidos
{
    public:
        Partidos();

        void ingresarEquipos();
        void llenarResultados();
        void imprimirResultadosPartidos();
        void imprimirTabla();

    protected:

    private:
        //Variables
        string equipos[NUMERO_EQUIPOS];
        int resultados[NUMERO_EQUIPOS][NUMERO_EQUIPOS][2];
        int estadisticas[NUMERO_EQUIPOS][7];

        int resultadosAleatorios(int minimo, int maximo);
        void calcularEstadisticas();
        void reinicioEstadisticas();
        void imprimirLinea();

};
#endif // PARTIDOS_H

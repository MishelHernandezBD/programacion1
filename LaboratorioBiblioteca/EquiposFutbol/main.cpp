#include <iostream>
#include "partidos.h"

using namespace std;

int main()
{
    Partidos partido;
    char opcion;
    bool repetir = true;

    do {
        system("cls");
        cout << "* Campeonato de Futbol *" << endl << endl;

        partido.ingresarEquipos();
        partido.llenarResultados();
        partido.imprimirResultadosPartidos();
        partido.imprimirTabla();

        cout << "Desea generar otro campeonato (s/n)? ";
        cin >> opcion;
        if (opcion == 'n' || opcion =='N') {
            repetir = false;
        }
    }while (repetir);

    return 0;
}

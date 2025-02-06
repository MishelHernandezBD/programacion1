#include <iostream>
//Calculadora para calcular la masa corporal de una persona
using namespace std;

int main ()
{
    //Variables
    float pesoEnLibras=0;
    float alturaEnPulgadas=0;
    float resultadoPeso=0;
    float pesoEnKilogramos=0;
    float alturaEnMetros=0;
    int opcionMenu=0;
    int opcionInvalida =0;

    //menu
    cout <<"1. Calculo de peso en libras\n";
    cout <<"2. Calculo de peso en Kilogramos\n";
    cout <<"Opccion: ";
    cin >> opcionMenu;

    //Calculo en libras
    if (opcionMenu==1){
        cout <<"Ingrese el peso en libras:\n ";
        cin >> pesoEnLibras;
        cout <<"Ingrese altura en pulgadas:\n ";
        cin >> alturaEnPulgadas;
        resultadoPeso = (pesoEnLibras*703)/(alturaEnPulgadas*alturaEnPulgadas);
    }
    //Calculo en kilogramos
    else if (opcionMenu==2){
        cout <<"Ingrese el peso en kilogramos:\n ";
        cin >> pesoEnKilogramos;
        cout <<"Ingrese altura en metros:\n ";
        cin >> alturaEnMetros;
        resultadoPeso = pesoEnKilogramos/(alturaEnMetros*alturaEnMetros);
    }
    else{
        cout <<"Opccion no valida\n";
        opcionInvalida =1;
    }

    // Evaluación del BMI
    if (opcionInvalida != 1) {
        cout << "Su Indice de masa es: " << resultadoPeso<<endl;

        if (resultadoPeso >= 0 && resultadoPeso < 18.5) {
            cout << "Bajo peso: menos de 18.5\n";
        }
        else if (resultadoPeso >= 18.5 && resultadoPeso <= 24.9) {
            cout << "Normal: entre 18.5 y 24.9\n";
        }
        else if (resultadoPeso >= 25 && resultadoPeso <= 29.9) {
            cout << "Sobrepeso: entre 25 y 29.9\n";
        }
        else {
            cout << "Obeso: 30 o mas\n";
        }
    }
    return 0;
}

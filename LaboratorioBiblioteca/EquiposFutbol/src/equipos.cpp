#include "equipos.h"
#include <iostream>

using namespace std;

equipos::equipos()
{
}
equipos::equipos(string nombre)
{
   this->nombre = nombre;
}

string equipos::getNombre()
{
    return nombre;
}
void equipos::setNombre(string nombre)
{
    this->nombre = nombre;
}

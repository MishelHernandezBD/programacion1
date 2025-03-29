#ifndef EQUIPOS_H
#define EQUIPOS_H
#include <iostream>

using namespace std;


class equipos
{
    public:
        equipos();
        equipos(string nombre);

        string getNombre();
        void setNombre(string nombre);

    protected:

    private:
        //Variables
        string nombre;
};

#endif // EQUIPOS_H

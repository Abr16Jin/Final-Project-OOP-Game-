#ifndef PROPIEDADES_H
#define PROPIEDADES_H

#include <iostream>
#include <string>
using namespace std;

class Propiedades
{
    private:
        int efectoFuerza;
        int efectoSalud;
    public:
        Propiedades();
        Propiedades(int, int);
        ~Propiedades();

    //Metodos Propiedades

        int getFuerza() const;
        void setFuerza(int);

        int getSalud() const;
        void setSalud(int);
};

#endif // PROPIEDADES_H

#include <iostream>
#include "Jugador.h"
/*Bienvenido querido Javier al Archivo MAIN del proyecto final uwu*/

using namespace std;

int main()
{
    cout << "Este es el menu principal OwO!" << endl;

    Item voidItem;

    Propiedades pulgasP(-100, 0);
    Item pulgasItem("Pulgas", pulgasP);

    Granja grInicial("Los Santos", 1000 , pulgasItem);


    Jugador hoja("Hojalata99", 100, 100, grInicial);

    cout<<hoja.getNombre()<<" "<<hoja.getPlata()<<" "<<hoja.getPrestigio()<<endl;
    cout<<"Granja del Jugador: "<<hoja.getNombre()<<" "<<">>"<<hoja.getGranja().getNombre()<<endl;
    vector<Item> copyList = hoja.getGranja().getItemList();
    cout<<"PRIMER ITEM ENCONTRADO:"<<" "<<copyList[0].getNombre()<<endl;

    return 0;
}

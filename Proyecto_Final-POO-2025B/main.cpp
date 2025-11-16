#include <iostream>
#include "Jugador.h"
#include "Instancias.h"

/*Bienvenido querido Javier al Archivo MAIN del proyecto final uwu*/

using namespace std;

int main()
{

    cout << "Este es el menu principal OwO!" << endl;

    //INSTANCIAS Y DATOS INICIALES
    Item Pulgas = crearpulgas();

    Granja grInicial("Los Santos", 1000 , Pulgas, crearTerreno_Inicial());


    Jugador hoja("Hojalata99", 100, 100, grInicial);

    cout<<hoja.getNombre()<<" "<<hoja.getPlata()<<" "<<hoja.getPrestigio()<<endl;
    cout<<"Granja del Jugador: "<<hoja.getNombre()<<" "<<">>"<<hoja.getGranja().getNombre()<<endl;
    vector<Item> copyList = hoja.getGranja().getItemList();
    cout<<"PRIMER ITEM ENCONTRADO:"<<" "<<copyList[0].getNombre()<<endl;

    return 0;
}

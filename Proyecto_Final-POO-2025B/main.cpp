#include <iostream>
#include "Jugador.h"
#include "Instancias.h"

/*Bienvenido querido Javier al Archivo MAIN del proyecto final uwu*/

using namespace std;

int main()
{
    Terreno terrenoJav(3, 4, Tipo::RANCHO_M, 30000, {Nivel::DOMESTICO, Nivel::COMBATE});
    terrenoJav.agregarAnimal(crearVaca());
    //JUGADORES/OPONENTES POR DEFECTO
    Granja JavGranja("FairView", 2700, crearpulgas(), move(terrenoJav));
    Jugador Javier("Javiercito", 1500, 200, move(JavGranja));

    Javier.getGranja().setItem(crearbombaKap());

    cout << "Este es el menu principal OwO!" << endl;

    cout<<Javier.getNombre()<<" Plata: "<<Javier.getPlata()<<" Prestigio: "<<Javier.getPrestigio()<<endl;
    cout<<"Granja: "<<Javier.getGranja().getNombre()<<" Terreno LVL: "<<(int)Javier.getGranja().getTerreno().getCapacidadP()+1<<endl;

    vector<Item> copyList = Javier.getGranja().getItemList();

    for(int i=0; i < (int)copyList.size(); i++)
    {
        cout<<"ITEM: "<<copyList.at(i).getNombre();
        cout<<endl;
    }
}

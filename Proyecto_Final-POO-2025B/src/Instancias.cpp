#include "Instancias.h"

//ITEMS Y PROPIEDADES
Item crearEnerg()
{
    Propiedades energizanteP(19, 10);
    return Item("Energizante Animal", energizanteP);
}
Item crearpulgas()
{
    Propiedades pulgasP(-10, -5);
    return Item("Pulgas", pulgasP);
}
Item crearbombaKap()
{
    Propiedades bombaP(-5, -25);
    return Item("Bomba Kapossai", bombaP);
}

//ANIMALES POINTERS

Animal* crearGallina()
{
    return new Domestico("Gallina", 15, 80, 25);
}
Animal* crearVaca()
{
    return new Domestico("Vaca", 120, 800, 500);
}
Animal* crearConejo()
{
    return new Domestico("Conejo", 25, 120, 50);
}
Animal* crearCerdo()
{
    return new Domestico("Cerdo", 60, 300, 150);
}
Animal* crearGallo()
{
    return new Combate("Gallo", 35, 160, 80);
}
Animal* crearPerro()
{
    return new Combate("Perro", 90, 450, 300);
}
Animal* crearCaballo()
{
    return new Combate("Caballo", 200, 1500, 1200);
}
Animal* crearZorro()
{
    return new Alta_Clase("Zorro", 280, 1800, 2200);
}
Animal* crearAguila()
{
    return new Alta_Clase("Aguila", 380, 2500, 3800);
}
Animal* crearDragon()
{
    return new Alta_Clase("Dragon", 500, 4000, 6000);
}
 // TERRENOS INICIALES
Terreno crearTerreno_Inicial()
{
    Terreno terreno;
    cout<<"Configurando el terreno inicial."<<endl;

    terreno.agregarAnimal(crearVaca());
    terreno.agregarAnimal(crearGallina());
    terreno.agregarAnimal(crearGallina());
    terreno.agregarAnimal(crearConejo());
    terreno.agregarAnimal(crearConejo());
    terreno.agregarAnimal(crearConejo());

    cout<<"Terreno inicial LISTO!."<<endl;
    return terreno;
}

//JUGADOR PRUEBA


//GRANJAS




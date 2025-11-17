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

//JUGADORES DE PRUEBA

Jugador crearOponenteParcela()
{
    cout << "Instanciando Oponente (Parcela)..." << endl;

    Terreno terrenoBot(3, 4, Tipo::PARCELA_P, 10000, {Nivel::DOMESTICO});
    terrenoBot.agregarAnimal(crearGallina());
    terrenoBot.agregarAnimal(crearGallina());
    terrenoBot.agregarAnimal(crearConejo());

    Granja granjaBot("Parcela del Bot", 500, crearpulgas(), std::move(terrenoBot));

    return Jugador("Bot Granjero", 300, 80, std::move(granjaBot));
}

Jugador crearOponenteRancho()
{
    cout << "Instanciando Oponente (Rancho)..." << endl;
    Terreno terrenoBot(3, 4, Tipo::RANCHO_M, 25000, {Nivel::DOMESTICO, Nivel::COMBATE});

    terrenoBot.agregarAnimal(crearVaca());
    terrenoBot.agregarAnimal(crearGallo());
    terrenoBot.agregarAnimal(crearGallo());
    terrenoBot.agregarAnimal(crearPerro());

    Granja granjaBot("Rancho del Rival", 1500, crearEnerg(), std::move(terrenoBot));

    return Jugador("Rival Vaquero", 1000, 250, std::move(granjaBot));
}

Jugador crearOponenteFinca()
{
    cout << "Instanciando Oponente (Finca)..." << endl;

    Terreno terrenoBot(4, 9, Tipo::FINCA_M, 70000, {Nivel::DOMESTICO, Nivel::COMBATE, Nivel::ALTA_CLASE});

    terrenoBot.agregarAnimal(crearCaballo());
    terrenoBot.agregarAnimal(crearCaballo());
    terrenoBot.agregarAnimal(crearZorro()); // Nivel ALTA_CLASE
    terrenoBot.agregarAnimal(crearAguila()); // Nivel ALTA_CLASE
    terrenoBot.agregarAnimal(crearCerdo());

    Granja granjaBot("Finca del Barón", 5000, crearbombaKap(), std::move(terrenoBot));

    return Jugador("Barón de la Finca", 3000, 800, std::move(granjaBot));
}




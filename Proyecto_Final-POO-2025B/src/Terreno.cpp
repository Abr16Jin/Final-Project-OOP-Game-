#include "Terreno.h"

//por defecto
Terreno::Terreno()
{
    capacidadEspecie = 3;
    capacidadStack = 4;
    Tipo capacidadTipo = Tipo::PARCELA_P;
    nivelPermitidoA = {Nivel::DOMESTICO};

}

Terreno::~Terreno()
{
    //limpiar animales creados con new
    for (auto const& [especie, listaAnimales] : listasAnimales)
    {
        for (Animal* animalPtr : listaAnimales)
        {
            delete animalPtr;
        }
    }
}

//METODOS TERRENO

int Terreno::getCespecies()
{
    return capacidadEspecie;
}
void Terreno::setCespecies(int cEspecies)
{
    capacidadEspecie = cEspecies;
}
int Terreno::getCstack()
{
    return capacidadStack;
}
void Terreno::setStack(int cStack)
{
    capacidadStack = cStack;
}

//METODOS ANIMAL/TERRENO

bool Terreno::helperNivel(Nivel auxNv)
{
    //check allowed niveles
    for(int i=0; i < (int)nivelPermitidoA.size(); i++)
        {
           if(auxNv == nivelPermitidoA[i]) return true;
        }
    return false;
}

bool Terreno::agregarAnimal(Animal* auxAnimal)
{
    //verificar nivel
    if(helperNivel(auxAnimal->getNivel()) != true)
    {
        cout<<"Tu terreno no admite animales de este nivel!"<<endl;
        return false;
    }

    string especie = auxAnimal->getNombre();

    //verificar espacio especie
    if (listasAnimales.find(especie) == listasAnimales.end())
        {
            if ((int)listasAnimales.size() >= this->capacidadEspecie)
                {
                    cout << "Error: El terreno está lleno (máx " << this->capacidadEspecie << " especies)." << endl;
                    return false;
                }
        }
    //verificar espacio stack
    if ((int)listasAnimales[especie].size() >= this->capacidadStack)
        {
            cout << "Error: El stack para '" << especie << "' está lleno (máx " << this->capacidadStack << ")." << endl;
            return false;
        }
    //agregar animalito
    listasAnimales[especie].push_back(auxAnimal);
    cout << "Se agregó un '" << especie << "'." << endl;
    return true;
}

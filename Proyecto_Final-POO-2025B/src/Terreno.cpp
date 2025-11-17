#include "Terreno.h"

//por defecto
Terreno::Terreno()
{
    capacidadEspecie = 3;
    capacidadStack = 4;
    valorTerreno = 10000; //plata
    capacidadTipo = Tipo::PARCELA_P;
    nivelPermitidoA = {Nivel::DOMESTICO};

}
Terreno::Terreno(int cEspecie, int cStack, Tipo tipoCap, int valorPlataTerr, vector<Nivel> niveles)
{
    capacidadEspecie = cEspecie;
    capacidadStack = cStack;
    capacidadTipo = tipoCap;
    valorTerreno = valorPlataTerr;
    nivelPermitidoA = niveles;
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

int Terreno::getCespecies() const
{
    return capacidadEspecie;
}
void Terreno::setCespecies(int cEspecies)
{
    capacidadEspecie = cEspecies;
}
int Terreno::getCstack() const
{
    return capacidadStack;
}
void Terreno::setStack(int cStack)
{
    capacidadStack = cStack;
}
Tipo Terreno::getCapacidadP() const
{
    return capacidadTipo;
}
void Terreno::setCapacidadP(Tipo capacidadNew)
{
    capacidadTipo = capacidadNew;
}
int Terreno::getValorTerreno() const
{
    return valorTerreno;
}
void Terreno::setValorTerreno(int newValor)
{
    valorTerreno = newValor;
}
//METODO TERRENO PARA BATALLA

Nivel Terreno::getNivelMasAlto() const
{
    Nivel nivelMasAlto = Nivel::DOMESTICO;
    for (const auto& par : listasAnimales)
    {
        for (Animal* animalPtr : par.second)
        {
            Nivel nivelActual = animalPtr->getNivel();
            if (static_cast<int>(nivelActual) > static_cast<int>(nivelMasAlto))
            {
                nivelMasAlto = nivelActual;
            }
            if (nivelMasAlto == Nivel::ALTA_CLASE)
            {
                return Nivel::ALTA_CLASE;
            }
        }
    }
    return nivelMasAlto;
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
    return true;
}

Animal* Terreno::removerAnimal(string especie)
{
    auto iterador = listasAnimales.find(especie);

    if (iterador == listasAnimales.end())
    {
        cout << "Error de Apuesta: No tienes animales de la especie '" << especie << "'." << endl;
        return nullptr;
    }
    vector<Animal*>& stackAnimales = iterador->second;

    if (stackAnimales.empty())
    {
        cout << "Error de Apuesta: No te quedan animales de la especie '" << especie << "'." << endl;
        listasAnimales.erase(iterador);
        return nullptr;
    }

    Animal* animalParaApostar = stackAnimales.back();

    stackAnimales.pop_back();

    cout << "Has seleccionado 1x " << animalParaApostar->getNombre() << " para la apuesta." << endl;

    if (stackAnimales.empty())
    {
        cout << "(Ya no te quedan más " << especie << "s)" << endl;
        listasAnimales.erase(iterador);
    }

    return animalParaApostar;
}

bool Terreno::removerAnimalMuerto(Animal* animalMuerto)
{
    for (auto& par : listasAnimales)
    {
        vector<Animal*>& listaAnimales = par.second;

        for (auto it = listaAnimales.begin(); it != listaAnimales.end(); ++it)
        {
            if (*it == animalMuerto)
            {
                cout << "¡" << animalMuerto->getNombre() << " ha sido derrotado y removido del terreno!" << endl;

                //1 Borramos el animal de la memoria
                delete animalMuerto;

                //2 Quitamos el puntero
                listaAnimales.erase(it);

                //3 Limpiamos la entrada del map si el vector está vacío
                if (listaAnimales.empty())
                {
                    listasAnimales.erase(par.first);
                }

                return true;
            }
        }
    }
    return false; // No se encontró
}

// MOSTRAR animales sin modificarlos
void Terreno::mostrarAnimalesDisponibles() const
{
    cout << "  Animales en este terreno:" << endl;
    if (listasAnimales.empty())
    {
        cout << "  - (No hay animales)" << endl;
        return;
    }

    for (const auto& par : listasAnimales)
    {
        if (!par.second.empty())
        {
            // Imprime la especie y cuántos hay
            cout << "  - Especie: " << par.first
                 << ", Cantidad: " << par.second.size() << endl;

            Animal* animalMuestra = par.second.back();
            cout << "      (Stats: " << animalMuestra->getAtaque()
                 << " ATK / " << animalMuestra->getVida() << " HP)" << endl;
        }
    }
}

// OBTENER un puntero a un animal (sin removerlo)
Animal* Terreno::getAnimal(string especie)
{
    // 1. Buscar si la especie existe
    auto iterador = listasAnimales.find(especie);

    // 2. Verificar si no se encontró
    if (iterador == listasAnimales.end())
    {
        cout << "Error: No se encontró la especie '" << especie << "'." << endl;
        return nullptr;
    }

    // 3. Verificar si el vector de esa especie está vacío
    if (iterador->second.empty())
    {
        cout << "Error: No te quedan animales de la especie '" << especie << "'." << endl;
        return nullptr;
    }

    // 4. Devolvemos el puntero al ÚLTIMO animal de ese stack
    return iterador->second.back();
}

int Terreno::getConteoAnimales() const
{
    int conteoTotal = 0;

    for (const auto& par : listasAnimales)
    {
        conteoTotal += par.second.size();
    }

    return conteoTotal;
}

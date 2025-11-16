#ifndef APUESTA_H
#define APUESTA_H

#include <iostream>
#include <vector>
#include <utility>
#include "Animal.h"
#include "Terreno.h"

using namespace std;

class Apuesta
{
private:
    int prestigioApuesta;
    int plataApuesta;

    vector<Animal*> animalesApuesta;
    Terreno terrenoApuesta;
    bool terrenoEstaApostado;

public:
    Apuesta();
    ~Apuesta();

    Apuesta(const Apuesta&) = delete;
    Apuesta& operator=(const Apuesta&) = delete;

    Apuesta(Apuesta&&) = default;
    Apuesta& operator=(Apuesta&&) = default;

    //METODOS APUESTA

    int getPrestigio() const;
    int getPlata() const;
    const vector<Animal*>& getAnimales() const;
    const Terreno& getTerreno() const;
    bool getTerrenoApostado() const;

    vector<Animal*>& getAnimales();
    Terreno& getTerreno();

    void setPrestigio(int prestigio);
    void setPlata(int plata);

    // Agrega un animal
    void addAnimal(Animal* animal);

    // Establece el terreno
    void setTerreno(Terreno&& terreno);
};

#endif // APUESTA_H

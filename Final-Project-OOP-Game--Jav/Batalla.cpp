#include "Batalla.h"

void Batalla::determinarTurnoInicial()
    {
        cout << "Determinando primer turno..." << endl;

        Jugador& j1 = partida->getJugadorUno();
        Jugador& j2 = partida->getJugadorDos();

        // 1. Obtenemos el nivel más alto de cada jugador
        Nivel nivelJ1 = j1.getGranja().getTerreno().getNivelMasAlto();
        Nivel nivelJ2 = j2.getGranja().getTerreno().getNivelMasAlto();

        // 2. Comparamos los niveles (convirtiendo a int)
        if (static_cast<int>(nivelJ1) > static_cast<int>(nivelJ2))
        {
            atacante = &j1;
            defensor = &j2;
            cout << j1.getNombre() << " (Nivel Animal: " << (int)nivelJ1 << ") ataca primero!" << endl;
        }
        else if (static_cast<int>(nivelJ2) > static_cast<int>(nivelJ1))
        {
            atacante = &j2;
            defensor = &j1;
            cout << j2.getNombre() << " (Nivel Animal: " << (int)nivelJ2 << ") ataca primero!" << endl;
        }
        else // 3. Los niveles son iguales, usamos Prestigio como desempate
        {
            cout << "Nivel de animal empatado. Revisando prestigio..." << endl;
            if (j1.getPrestigio() > j2.getPrestigio())
            {
                atacante = &j1;
                defensor = &j2;
                cout << j1.getNombre() << " (Prestigio: " << j1.getPrestigio() << ") ataca primero!" << endl;
            }
            else if (j2.getPrestigio() > j1.getPrestigio())
            {
                atacante = &j2;
                defensor = &j1;
                cout << j2.getNombre() << " (Prestigio: " << j2.getPrestigio() << ") ataca primero!" << endl;
            }
            else // 4. Empate total
            {
                atacante = &j1; // J1 por defecto en empate total
                defensor = &j2;
                cout << "Prestigio empatado: " << j1.getNombre() << " ataca primero." << endl;
            }
        }
}

void Batalla::cambiarTurno()
{
        Jugador* temp = atacante;
        atacante = defensor;
        defensor = temp;
}

void Batalla::ejecutarTurno()
    {
        cout << "\n--- TURNO DE: " << atacante->getNombre() << " ---" << endl;
        int opcion = 0;

        // Bucle menu de turno
        while (true)
        {
            cout << "Elige una accion:" << endl;
            cout << "  1. Atacar con Animal" << endl;
            cout << "  2. Usar Item" << endl;
            cout << "  3. Rendirse" << endl;
            cout<<"---------------------------"<<endl;
            cout << "Opcion: ";
            cin >> opcion;

            if (opcion == 1) // ATACAR
            {
                string especieAtacante, especieDefensor;

                // 1. Atacante elige su animal
                cout << "\n---< Tus Animales Disponibles >---" << endl;
                atacante->getGranja().getTerreno().mostrarAnimalesDisponibles();
                cout << "Elige tu atacante (escribe la especie) ->: ";
                cin >> especieAtacante;
                Animal* miAnimal = atacante->getGranja().getTerreno().getAnimal(especieAtacante);

                // 2. Atacante elige objetivo
                cout << "\n---< Animales del Oponente >---" << endl;
                defensor->getGranja().getTerreno().mostrarAnimalesDisponibles();
                cout<<"------------------------------"<<endl;
                cout << "Elige tu objetivo (escribe la especie) ->: ";
                cin >> especieDefensor;
                Animal* suAnimal = defensor->getGranja().getTerreno().getAnimal(especieDefensor);

                // 3. Validar selecciones
                if (miAnimal == nullptr || suAnimal == nullptr)
                {
                    cout << "Seleccion de animal INVALIDA! Pierdes el turno." << endl;
                    cout<<endl;
                    return; // Termina el turno
                }

                // 4. Aplicar ataque
                cout << "\n" << miAnimal->getNombre() << " ataca a " << suAnimal->getNombre() << "!" << endl;
                suAnimal->setVida( suAnimal->getVida() - miAnimal->atacar() );

                // 5. Chequear muerte
                if (suAnimal->getVida() <= 0)
                {
                    defensor->getGranja().getTerreno().removerAnimalMuerto(suAnimal);
                }
                else
                {
                    cout << "  -> " << suAnimal->getNombre() << " queda con " << suAnimal->getVida() << " HP." << endl;
                }

                return; // Termina el turno
            }
            else if (opcion == 2) // USAR ITEM
            {
                string nombreItem;

                // 1. Mostrar inventario
                cout << "\n---:: Tu Inventario ::---" << endl;
                atacante->getGranja().mostrarItems();
                cout << "Elige un item (escribe el nombre) =>: ";
                cin.ignore();
                getline(cin, nombreItem);
                Item itemUsado = atacante->getGranja().removerItem(nombreItem);

                if (itemUsado.getNombre() == "")
                {
                    cout << "Item no valido! Pierdes el turno." << endl;
                    return; // Termina el turno
                }

                //Preguntar por el objetivo
                int tipoObjetivo = 0;
                cout << "--> Objetivo del ITEM <--" << endl;
                cout<<"----------------------------------"<<endl;
                cout << "  1. Animal Aliado (Buff)" << endl;
                cout << "  2. Animal Enemigo (Debuff)" << endl;
                cout<<"----------------------------------"<<endl;
                cout << "Opcion: ";
                cin >> tipoObjetivo;

                string especieObjetivo;
                Animal* animalObjetivo = nullptr;

                //animal objetivo
                if (tipoObjetivo == 1) // Aliado
                {
                    cout << "\n---< Tus Animales >---" << endl;
                    atacante->getGranja().getTerreno().mostrarAnimalesDisponibles();
                    cout<<"---------------------------"<<endl;
                    cout << "Elige tu animal objetivo ->: ";
                    cin >> especieObjetivo;
                    animalObjetivo = atacante->getGranja().getTerreno().getAnimal(especieObjetivo);

                    // Aplicar el operador +
                    if(animalObjetivo != nullptr)
                        *animalObjetivo + itemUsado;
                }
                else if (tipoObjetivo == 2) // Enemigo
                {
                    cout << "\n---< Animales del Oponente >---" << endl;
                    defensor->getGranja().getTerreno().mostrarAnimalesDisponibles();
                    cout<<"---------------------------"<<endl;
                    cout << "Elige el animal enemigo ->: ";
                    cin >> especieObjetivo;
                    animalObjetivo = defensor->getGranja().getTerreno().getAnimal(especieObjetivo);

                    //Aplicar el operador -
                    if(animalObjetivo != nullptr)
                        *animalObjetivo - itemUsado;
                }
                else
                {
                    cout << "Opcion INVALIDA." << endl;
                }

                return; // Termina el turno
            }
            else if (opcion == 3) // RENDIRSE
            {
                cout << atacante->getNombre() << " se ha rendido." << endl;
                if (atacante == &(partida->getJugadorUno())) rendirJ1 = true;
                else rendirJ2 = true;
                return; // Termina el turno
            }
            else
            {
                cout << "Opcion no INVALIDA." << endl;
            }
        }
}

bool Batalla::chequearFinBatalla()
    {
        // 1. Chequeo por rendicion
        if (rendirJ1 || rendirJ2)
        {
            return true;
        }
        if (atacante->getGranja().getTerreno().getConteoAnimales() == 0)
        {
            cout << atacante->getNombre() << " se ha quedado sin animales!" << endl;
        }
        if (defensor->getGranja().getTerreno().getConteoAnimales() == 0)
        {
            cout << defensor->getNombre() << " se ha quedado sin animales!" << endl;
        }
        if (partida->getJugadorUno().getGranja().getTerreno().getConteoAnimales() == 0 ||
            partida->getJugadorDos().getGranja().getTerreno().getConteoAnimales() == 0)
        {
            return true;
        }
        return false;
    }

// PUBLIC

Batalla::Batalla(Partida* p) : partida(p), atacante(nullptr), defensor(nullptr), rendirJ1(false), rendirJ2(false)
    {
        if (p == nullptr)
        {
            throw std::runtime_error("La Partida no puede ser nula!");
        }
        cout << "Sistema de Batalla Inicializado." << endl;
    }

void Batalla::iniciarCombate()
    {
        determinarTurnoInicial();

        // --- Bucle principal del combate (DO-WHILE)
        do
        {
            ejecutarTurno();

            if (chequearFinBatalla()) break; // Salir si alguien se rinde o pierde

            cambiarTurno(); // Cambia atacante y defensor

        } while (true); // El 'break' interno maneja la salida


        //Fin de Batalla ---
        cout << "\n+-- BATALLA TERMINADA --+" << endl;

        Jugador& j1 = partida->getJugadorUno();
        Jugador& j2 = partida->getJugadorDos();
        Apuesta& ap = partida->getApuesta();

        // Determinar ganador y perdedor
        Jugador* ganador = nullptr;
        Jugador* perdedor = nullptr;

        //no hay empates
    if (rendirJ1)
    {
        ganador = &j2;
        perdedor = &j1;
    }
    else if (rendirJ2)
    {
        ganador = &j1;
        perdedor = &j2;
    }
    // 2. Chequeo por falta de animales

    else if (j1.getGranja().getTerreno().getConteoAnimales() == 0)
    {
        // J1 no tiene animales, por lo tanto J2 gana.
        ganador = &j2;
        perdedor = &j1;
    }
    else if (j2.getGranja().getTerreno().getConteoAnimales() == 0)
    {
        // J2 no tiene animales, por lo tanto J1 gana.
        ganador = &j1;
        perdedor = &j2;
    }
    else
    {
        // declaramos un empate
        // y nadie obtiene la apuesta.
        cout << "La batalla termino en un EMPATE. La apuesta se anula." << endl;
        ganador = nullptr;
        perdedor = nullptr;
    }

        if (ganador != nullptr && perdedor != nullptr)
        {
            *ganador += ap;
            *perdedor -= ap;
        }

        cout << "Regresando al menu principal..." << endl;
    }


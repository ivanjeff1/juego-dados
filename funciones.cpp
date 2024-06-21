#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "dados.h"
#include "funciones.h"

using namespace std;

int jugarRonda()
{
    int maxPuntajeRonda = 0;

    for (int i = 0; i < 3; i++)
    {
        int puntajeLanzamiento = efectoDado();
        system("cls");

        if (puntajeLanzamiento == 6)
        {
            cout << "Ups, se resetea. " << endl;
            return 0;
        }
        else if (puntajeLanzamiento == 21)
        {
            cout << " Hiciste Escalera! " << endl;
            return 100;
        }
        else if (puntajeLanzamiento >= 1 && puntajeLanzamiento <= 6)
        {
            cout << " Hiciste Sexteto de " << puntajeLanzamiento << " multiplicas x 10 = " << puntajeLanzamiento * 10 << "!" << endl; //corroborar que funcione y se guarde en puntaje
            return puntajeLanzamiento * 10;
        }
        else
        {
            if (puntajeLanzamiento > maxPuntajeRonda)
            {
                maxPuntajeRonda = puntajeLanzamiento;
            }
        }

        cout << "Lanzamiento " << (i + 1) << ": Puntaje = " << puntajeLanzamiento << endl;
        system("pause");
        system("cls");
    }

    return maxPuntajeRonda;
}

int jugarModoUnJugador(char nombre[])
{
    int puntaje = 0;
    int ronda = 0;

    while (puntaje < 100)
    {
        ++ronda;
        int puntajeRonda = jugarRonda();
        puntaje += puntajeRonda;

        cout << " Ronda: " << ronda << " Puntaje maximo de la ronda = " << puntajeRonda << " | Puntaje acumulado = " << puntaje << endl;
        system("pause");
        system("cls");
    }

    cout << "Felicidades: " << nombre << "!! Has alcanzado " << puntaje << " puntos en " << ronda << " rondas. " << endl;
    system("pause");
    system("cls");

    return puntaje;
}

void jugarModoDosJugadores(char nombre1[], char nombre2[])
{
    int puntaje1 = 0, puntaje2 = 0;
    int ronda1 = 0, ronda2 = 0;
    int puntajeMax = 0; //guarda el valor del puntaje max
    char nombreMax[30] = ""; //nombre del jugador con puntaje maximo

    while (puntaje1 < 100 && puntaje2 < 100)
    {
        ++ronda1;
        int puntajeRonda1 = jugarRonda();
        puntaje1 += puntajeRonda1;

        if (puntajeRonda1 > puntajeMax)
        {
            puntajeMax = puntajeRonda1;
            strcpy(nombreMax, nombre1);
        }

        cout << "Ronda: " << ronda1 << " de " << nombre1 << ": Puntaje de la ronda = " << puntajeRonda1 << " | Puntaje acumulado = " << puntaje1 << endl;
        system("pause");
        system("cls");

        if (puntaje1 >= 100) break;



        ++ronda2;
        int puntajeRonda2 = jugarRonda();
        puntaje2 += puntajeRonda2;

        if (puntajeRonda2 > puntajeMax)
        {
            puntajeMax = puntajeRonda2;
            strcpy(nombreMax, nombre2);
        }

        cout << " Ronda: " << ronda2 << " de " << nombre2 << ": Puntaje de la ronda = " << puntajeRonda2 << " | Puntaje acumulado = " << puntaje2 << endl;
        system("pause");
        system("cls");
    }

    if (puntaje1 >= 100)
    {
        cout << " Felicidades: " << nombre1 << "!! Has alcanzado " << puntaje1 << " puntos en " << ronda1 << " rondas y has ganado. " << endl;
        cout << nombre2 << " ha alcanzado " << puntaje2 << " puntos en " << ronda2 << " rondas." << endl;
    }
    else if (puntaje2 >= 100)
    {
        cout << " Felicidades: " << nombre2 << "!! Has alcanzado " << puntaje2 << " puntos en " << ronda2 << " rondas y has ganado. " << endl;
        cout << nombre1 << " ha alcanzado " << puntaje1 << " puntos en " << ronda1 << " rondas. " << endl;
    }

    system("pause");
    system("cls");
}

void mostrarPuntajeMaximo(int puntajeMax, char nombreMax[])
{
    if (puntajeMax > 0)
    {
        cout << " Puntaje maximo alcanzado: " << puntajeMax << " por " << nombreMax << endl;
    }
    else
    {
        cout << " Aun no hay un puntaje registrado en esta sesion. " << endl;
    }

    system("pause");
    system("cls");
}

void menu()
{
    int modoJuego;
    int puntajeMax = 0;
    char nombreMax[30] = "";

    while (true)
    {
        cout << "---MENU PRINCIPAL---" << endl;
        cout << "1. MODO UN JUGADOR" << endl;
        cout << "2. MODO DOS JUGADORES" << endl;
        cout << "3. MOSTRAR PUNTAJE MAXIMO" << endl;
        cout << "4. SALIR DEL JUEGO" << endl;
        cout << "-------------------" << endl;
        cout << "INGRESE LA OPCION: ";
        cin >> modoJuego;
        system("cls");

        switch (modoJuego)
        {
        case 1:
            {
                char nombre[30];
                cout << "Ingresar nombre del jugador:  ";
                cin >> nombre;
                system("pause");
                system("cls");

                int puntaje = jugarModoUnJugador(nombre);

                if (puntaje > puntajeMax)
                {
                    puntajeMax = puntaje;
                    (nombreMax, nombre);
                }
                break;
            }
        case 2:
            {
                char nombre1[30], nombre2[30];
                cout << "Ingresar nombre del jugador 1: ";
                cin >> nombre1;
                cout << "Ingresar nombre del jugador 2: ";
                cin >> nombre2;
                system("pause");
                system("cls");

                jugarModoDosJugadores(nombre1, nombre2);
                break;
            }
        case 3:
            mostrarPuntajeMaximo(puntajeMax, nombreMax);
            break;
        case 4:
            return;
        default:
            cout << " Opcion incorrecta intente nuevamente." << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}


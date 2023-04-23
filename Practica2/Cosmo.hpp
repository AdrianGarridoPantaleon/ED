#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <sstream>

using namespace std;

string CrearNombre(string nombre)
{

    stringstream comprobar;
    string okey;
    int numeros;
    numeros = rand() % 1000;

    if (numeros < 100 && numeros >= 10)
    {
        comprobar << numeros;
        comprobar >> okey;
        nombre += "0" + okey;
    }
    if (numeros < 10)
    {
        comprobar << numeros;
        comprobar >> okey;
        nombre += "00" + okey;
    }
    if (numeros >= 100)
    {
        comprobar << numeros;
        comprobar >> okey;
        nombre += okey;
    }

    cout << "Introduce el tipo de cuerpo (S,P,M): " << endl;
    while (1)
    {
        cin >> okey;
        if (okey == "S")
        {
            nombre += okey;
            break;
        }
        else if (okey == "P")
        {
            nombre += okey;
            break;
        }
        else if (okey == "M")
        {
            nombre += okey;
            break;
        }
        else if (okey != "P" || okey != "S" || okey != "M")
        {
            cout << "Introduce de forma correcta el tipo de cuerpo (S,P,M): " << endl;
        }
    }

    return nombre;
}

string nombreAleatorio()
{
    int numeroAleatorio;
    string nombreAleatorio;
    string aux;
    stringstream auxSs;

    numeroAleatorio = rand() % 4;
    if (numeroAleatorio == 0)
    {
        nombreAleatorio = "AN";
    }
    else if (numeroAleatorio == 1)
    {
        nombreAleatorio = "CE";
    }
    else if (numeroAleatorio == 2)
    {
        nombreAleatorio = "VL";
    }
    else if (numeroAleatorio == 3)
    {
        nombreAleatorio = "LE";
    }

    numeroAleatorio = rand() % 1000;
    if (numeroAleatorio < 100 && numeroAleatorio >= 10)
    {
        auxSs << numeroAleatorio;
        auxSs >> aux;
        nombreAleatorio += "0" + aux;
    }
    if (numeroAleatorio < 10)
    {
        auxSs << numeroAleatorio;
        auxSs >> aux;
        nombreAleatorio += "00" + aux;
    }
    if (numeroAleatorio >= 100)
    {
        auxSs << numeroAleatorio;
        auxSs >> aux;
        nombreAleatorio += aux;
    }

    numeroAleatorio = rand() % 3;

    if (numeroAleatorio == 0)
    {
        nombreAleatorio += "S";
    }
    else if (numeroAleatorio == 1)
    {
        nombreAleatorio += "P";
    }
    else if (numeroAleatorio == 2)
    {
        nombreAleatorio += "M";
    }

    return nombreAleatorio;
}

int CrearMasa()
{
AGAIN:
    int masa;
    cout << "Introduce la masa del cuerpo con un valor comprendido entre (1-20): " << endl;
    cin >> masa;

    if (masa < 1 || masa > 20)
    {
        goto AGAIN;
    }

    return masa;
}

int masaAleatoria()
{
    int masaAleatoria;
    masaAleatoria = rand() % 20 + 1;

    return masaAleatoria;
}

double CrearDistancia()
{
AGAIN:
    double distancia;
    cout << "Introduce la distancia del cuerpo con un valor comprendido entre (1-1000): " << endl;
    cin >> distancia;

    if (distancia < 1 || distancia > 1000)
    {
        goto AGAIN;
    }

    return distancia;
}

double distanciaAleatoria()
{
    double distanciaAleatoria;
    distanciaAleatoria = rand() % 1000 + 1;

    return distanciaAleatoria;
}

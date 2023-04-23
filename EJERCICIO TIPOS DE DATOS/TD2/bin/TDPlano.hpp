#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "TDPunto.hpp"
#include "TDVector.hpp"
#include "TDRecta.hpp"

using namespace std;

typedef struct TDPlano
{
    punto p;
    vector v;
} plano;

plano crearPlanoVacio()
{
    plano P;
    P.p.X = P.p.Y = P.p.Z = 0;
    P.v.X = P.v.Y = P.v.Z = 0;

    return P;
}

plano crearPlanoPuntoVector(punto p1, vector v1)
{
    plano P;
    P.p.X = p1.X;
    P.p.Y = p1.Y;
    P.p.Z = p1.Z;

    P.v.X = v1.X;
    P.v.Y = v1.Y;
    P.v.Z = v1.Z;

    return P;
}

punto getPuntoPlano(plano P)
{
    return P.p;
}

vector getVectorPlano(plano P)
{
    return P.v;
}

double distanciaPuntoPlano(plano P1, punto p1)
{
    vector v;
    v = crearVectorPuntos(P1.p, p1);

    return (moduloVector(productoVectorialVectores(v, P1.v)) / moduloVector(P1.v));
}

double distanciaRectaPlano(plano P1, recta r1)
{
}

double distanciaPlanoPlano(plano P1, plano P2)
{
}
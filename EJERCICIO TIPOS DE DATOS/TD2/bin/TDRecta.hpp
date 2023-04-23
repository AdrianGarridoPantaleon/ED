#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "TDPunto.hpp"
#include "TDVector.hpp"

using namespace std;

typedef struct TDRecta
{
    punto p;
    vector v;

} recta;

recta crearRecta()
{
    recta r;
    r.p.X = r.p.Y = r.p.Z = 0;
    r.v.X = r.v.Y = r.v.Z = 0;

    return r;
}

recta crearRectaPuntos(punto p1, punto p2)
{
    recta r;

    r.p.X = p1.X;
    r.p.Y = p1.Y;
    r.p.Z = p1.Z;

    r.v.X = p1.X - p2.X;
    r.v.Y = p1.Y - p2.Y;
    r.v.Z = p1.Z - p2.Z;

    return r;
}

recta crearRectaPuntoVector(punto p1, vector v1)
{
    recta r;
    r.p.X = p1.X;
    r.p.Y = p1.Y;
    r.p.Z = p1.Z;

    r.v.X = v1.X;
    r.v.Y = v1.Y;
    r.v.Z = v1.Z;

    return r;
}

punto getPuntoRecta(recta r)
{
    return r.p;
}

vector getVectorRecta(recta r)
{
    return r.v;
}

//muestra la distancia de una recta a un punto
double distanciaPuntoRecta(recta r1, punto p1)
{
    vector v;
    v = crearVectorPuntos(r1.p, p1);

    return (moduloVector(productoVectorialVectores(v, r1.v)) / moduloVector(r1.v));
}

int posicionRelativaRecta(recta r1, recta r2)
{
    // 1: Coincidentes
    // 2: Paralelas
    // 3: Secante
    // 4: Cruce

    if ((r1.v.X / r2.v.X) == (r1.v.Y / r1.v.Y) == (r1.v.Z / r2.v.Z))
    {
        if (((r1.p.X - r2.p.X) / r2.v.X) == ((r1.p.Y - r2.p.Y) / r2.v.Y) ==
            ((r1.p.Z - r2.p.Z) / r2.v.Z))
        {
            return 1;
        }
        else
            return 2;
    }

    else
    {
        if (((r2.p.X - r1.p.X) * r1.v.Y * r2.v.Z) + ((r2.p.Z - r1.p.Z) * r1.v.X * r2.v.Y) + ((r2.p.Y - r1.p.Y) * r1.v.X * r2.v.Z) - ((r2.p.Z - r1.p.Z) * r2.v.X * r1.v.Y) - ((r2.p.Y - r1.p.Y) * r2.v.X * r1.v.Z) - ((r2.p.X - r1.p.X) * r2.v.Y * r1.v.Z) == 0)

            return 3;

        else
            return 4;
    }
}

// muestra la distancia de una recta a otra recta
/*double distanciaRectaRecta(recta r1, recta r2)
{
    recta r;
}*/
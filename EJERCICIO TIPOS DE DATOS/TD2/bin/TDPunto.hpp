#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

typedef struct TDPunto
{

    double X, Y, Z;

} punto;

punto crearPuntoVacio()
{
    punto p;
    p.X = p.Y = p.Z = 0;
    return p;
}

punto valoresCoordenadasPunto(double cX, double cY, double cZ)
{
    punto p;
    p.X = cX;
    p.Y = cY;
    p.Z = cZ;
    return p;
}

double getX(punto p)
{
    return p.X;
}
double getY(punto p)
{
    return p.Y;
}
double getZ(punto p)
{
    return p.Z;
}

void verCoordenadasPunto(punto p)
{

    cout << "X:" << getX(p) << ", Y:" << getY(p) << ", Z:" << getZ(p) << endl;
}

double distanciaEuclidea(punto p1, punto p2)
{
    return (sqrt((p1.X - p2.X) * (p1.X - p2.X) + (p1.Y - p2.Y) * (p1.Y - p2.Y) + (p1.Z - p2.Z) * (p1.Z - p2.Z)));
}

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//#include "TDPunto.hpp"

using namespace std;

typedef struct TDVector
{
    double X, Y, Z;

} vector;

vector crearVectorVacio()
{

    vector v;
    v.X = v.Y = v.Z = 0;
}

vector valoresCoordenadasVector(double cX, double cY, double cZ)
{
    vector v;
    v.X = cX;
    v.Y = cY;
    v.Z = cZ;
    return v;
}

vector crearVectorPuntos(punto p1, punto p2)
{
    vector v;
    v.X = getX(p1) - getX(p2);
    v.Y = getY(p1) - getY(p2);
    v.Z = getZ(p1) - getZ(p2);
    return v;
}

double getX(vector v)
{
    return v.X;
}
double getY(vector v)
{
    return v.Y;
}
double getZ(vector v)
{
    return v.Z;
}

void verCoordenadasVector(vector v)
{

    cout << "X:" << getX(v) << ", Y:" << getY(v) << ", Z:" << getZ(v) << endl;
}

double moduloVector(vector v)
{
    return (sqrt((v.X * v.X) + (v.Y * v.Y) + (v.Z * v.Z)));
}

vector normalizarVector(vector v)
{
    v.X = getX(v) / moduloVector(v);
    v.Y = getY(v) / moduloVector(v);
    v.Z = getZ(v) / moduloVector(v);
    return v;
}

double productoEscalarVectores(vector v1, vector v2)
{
    return ((v1.X * v2.X) + (v1.Y * v2.Y) + (v1.Z * v2.Z));
}

vector productoVectorialVectores(vector v1, vector v2)
{
    vector v;

    v.X = v1.Y * v2.Z - v1.Z * v2.Y;
    v.Y = v1.Z * v2.X - v1.X * v2.Z;
    v.Z = v1.X * v2.Y - v1.Y * v2.X;

    return v;
}

vector productoEscalarVector(double escalar, vector v)
{
    v.X = escalar * getX(v);
    v.Y = escalar * getY(v);
    v.Z = escalar * getZ(v);

    return v;
}

vector perpendicular(vector v1)
{
    vector v;
    v.X = -getY(v1);
    v.Y = getX(v1);
    v.Z = 0;

    return v;
}

vector sumaVectores(vector v1, vector v2)
{
    vector v;
    v.X = getX(v1) + getX(v2);
    v.Y = getY(v1) + getY(v2);
    v.Z = getZ(v1) + getZ(v2);

    return v;
}



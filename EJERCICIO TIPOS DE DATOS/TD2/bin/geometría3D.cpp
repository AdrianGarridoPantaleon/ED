#include <iostream>
#include <stdlib.h>
#include <stdio.h>
//#include "TDPunto.hpp"
//#include "TDVector.hpp"
#include "TDRecta.hpp"

using namespace std;

int main()
{
    //! TD PUNTO

    punto p1, p2;

    p1 = valoresCoordenadasPunto(4.2, 6, 5.88);
    cout << "p1= ";
    verCoordenadasPunto(p1);

    p2 = valoresCoordenadasPunto(7, 3, -6);
    cout << "p2= ";
    verCoordenadasPunto(p2);

    cout << "La distancia entre (p1,p2)= " << distanciaEuclidea(p1, p2) << endl;

    //! TD VECTOR

    vector v1, v2, v3, v4;

    v1 = crearVectorPuntos(p1, p2);
    cout << "v1= ";
    verCoordenadasVector(v1);
    cout << "El modulo de v1 es: " << moduloVector(v1) << endl;

    cout << endl;

    v1 = normalizarVector(v1);
    cout << "v1= ";
    verCoordenadasVector(v1);
    cout << "El vector normalizado de v1 es: ";
    normalizarVector(v1);
    cout << "El modulo de v1 es: " << moduloVector(v1) << endl;
    /*cout << "El producto escalar de v1 y v2 es: " << productoEscalarVectores (v1,v2)*/

    punto p3;
    p3 = valoresCoordenadasPunto(8, 4, -8);
    v2 = crearVectorPuntos(p2, p3);
    cout << "v2= ";
    verCoordenadasVector(v2);
    cout << "El modulo de v2 es: " << moduloVector(v2) << endl;
    cout << "Modulo(v1*v2)= " << moduloVector(productoVectorialVectores(v1, v2)) << endl;

    v3 = perpendicular(v2);
    cout << "v3= ";
    verCoordenadasVector(v3);
    cout << "Producto escalar(v2*v3)= " << productoEscalarVectores(v2, v3) << endl;

    v4 = productoEscalarVector(5, v2);
    cout << "v4= ";
    verCoordenadasVector(v4);

    //! TD RECTA

    recta r1, r2;
    r1 = crearRectaPuntoVector(p1, v2);
    r2 = crearRectaPuntoVector(p3, v3);

    switch (posicionRelativaRecta(r1, r2))
    {
    case 1:
        cout << "r1 y r2 son coincidentes" << endl;
        break;
    case 2:
        cout << "r1 y r2 son paralelas" << endl;
        break;
    case 3:
        cout << "r1 y r2 son secantes" << endl;
        break;
    case 4:
        cout << "r1 y r2 se cruzan" << endl;
        break;
    }

    //! TD PLANO
}

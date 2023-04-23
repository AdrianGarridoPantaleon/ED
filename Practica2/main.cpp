#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <ctime>
//#include <windows.h>
#include "Cosmo.hpp"
#include "Arbol.hpp"

using namespace std;

#define INT_MAX 9999
#define NULO -1
#define n 11

void dijkstra(int matriz[n][n], int salida, int destinacion);

int main(int argc, char *argv[])
{
    int distancia, matriz[n][n] = {{0, 0, 0, 0, 0, 422, 75, 0, 166, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 349, 0, 296},
                                   {0, 0, 0, 0, 644, 0, 0, 0, 0, 280, 324},
                                   {0, 0, 0, 0, 0, 297, 0, 264, 0, 325, 0},
                                   {0, 0, 644, 0, 0, 0, 0, 0, 0, 518, 0},
                                   {422, 0, 0, 297, 0, 0, 401, 538, 352, 193, 325},
                                   {75, 0, 0, 0, 0, 401, 0, 534, 0, 0, 0},
                                   {0, 0, 0, 264, 0, 538, 534, 0, 0, 0, 0},
                                   {166, 349, 0, 0, 0, 352, 0, 0, 0, 0, 0},
                                   {0, 0, 280, 325, 518, 193, 0, 0, 0, 0, 0},
                                   {0, 296, 324, 0, 0, 325, 0, 0, 0, 0, 0}};

    srand(time(NULL));
    int datos;
    int numero;
    string opcion;
    string eleccion;

    arbol AN = CrearArbol();
    arbol CE = CrearArbol();
    arbol VL = CrearArbol();
    arbol LE = CrearArbol();

    cout << "Escoge una opcion(A,B,C,D,E,F o G): " << endl;
    cout << "A. Introducir manualmente un cuerpo en cualquier ABB: AN,CE,VL,LE" << endl;
    cout << "B. Buscar cualquier cuerpo celeste en el ABB que se indique y mostrar sus datos." << endl;
    cout << "C. Imprimir los cuerpos de cualquier ABB recorridos de cualquier forma: anchura, profundidad (PRE, IN, POST ORDEN)." << endl;
    cout << "D. Borrar un cuerpo celeste, introducido por teclado, si existe en el correspondiente ABB." << endl;
    cout << "E. Introducir un numero y crear dicha cantidad de cuerpos celestes de cualquier galaxia, que se generaran al azar y se guardarán en el correspondiente ABB." << endl;
    cout << "F. Introducir un numero y generar al azar dicha cantidad de cuerpos de cualquier galaxia y borrarlos, si existen, de los correspondientes ABB." << endl;
    cout << "G. Iniciar la simulacion." << endl;
    cout << "H. Determinar si existe un camino minimo entre un par de estrellas introducidas por el usuario y mostrar sus etapas, conforme a la tabla que aparece abajo." << endl;
    cout << "I. Salir de la aplicacion." << endl;

    while (1)
    {
        string tel;
        cout << "\nIntroduce la opcion:";
        cin >> opcion;

        if (opcion == "A")
        {

            cout << "Elija el ABB (AN,CE,VL,LE): " << endl;
        A:
            cin >> eleccion;
            if (eleccion == "AN")
            {
                InsertarNodoArbol(AN, CrearNombre(eleccion), CrearMasa(), CrearDistancia());
            }
            else if (eleccion == "CE")
            {
                InsertarNodoArbol(CE, CrearNombre(eleccion), CrearMasa(), CrearDistancia());
            }
            else if (eleccion == "VL")
            {
                InsertarNodoArbol(VL, CrearNombre(eleccion), CrearMasa(), CrearDistancia());
            }
            else if (eleccion == "LE")
            {
                InsertarNodoArbol(LE, CrearNombre(eleccion), CrearMasa(), CrearDistancia());
            }
            else if (eleccion != "AN" || eleccion != "CE" || eleccion != "VL" || eleccion != "LE")
            {
                cout << "El nombre de la galaxia debe ser AN, CE, VL o LE." << endl;
                goto A;
            }
            cin.clear();
            cout << endl;
        }
        else if (opcion == "B")
        {

            cout << "Elija el ABB (AN,CE,VL,LE): " << endl;
        B:
            cin >> eleccion;
            if (eleccion == "AN")
            {
                cout << "Introduzca el cuerpo a buscar: " << endl;
                cin >> eleccion;
                if (BusquedaNodoABB(AN->raiz, eleccion))
                {
                    cout << "El cuerpo se ha encontrado" << endl;
                }
                else
                    cout << "El cuerpo no se ha encontrado" << endl;
            }
            else if (eleccion == "CE")
            {
                cout << "Introduzca el cuerpo a buscar: " << endl;
                cin >> eleccion;
                if (BusquedaNodoABB(CE->raiz, eleccion))
                {
                    cout << "El cuerpo se ha encontrado" << endl;
                }
                else
                    cout << "El cuerpo no se ha encontrado" << endl;
            }
            else if (eleccion == "VL")
            {
                cout << "Introduzca el cuerpo a buscar: " << endl;
                cin >> eleccion;
                if (BusquedaNodoABB(VL->raiz, eleccion))
                {
                    cout << "El cuerpo se ha encontrado" << endl;
                }
                else
                    cout << "El cuerpo no se ha encontrado" << endl;
            }
            else if (eleccion == "LE")
            {
                cout << "Introduzca el cuerpo a buscar: " << endl;
                cin >> eleccion;
                if (BusquedaNodoABB(LE->raiz, eleccion))
                {
                    cout << "El cuerpo se ha encontrado" << endl;
                }
                else
                    cout << "El cuerpo no se ha encontrado" << endl;
            }
            else if (eleccion != "AN" || eleccion != "CE" || eleccion != "VL" || eleccion != "LE")
            {
                cout << "El nombre de la galaxia debe ser AN, CE, VL o LE." << endl;
                goto B;
            }
            cin.clear();
            cout << endl;
        }
        else if (opcion == "C")
        {

            cout << "De que galaxia desea hacer el recorrido (AN, CE, VL, LE)? " << endl;
        C:
            cin >> eleccion;
            if (eleccion == "AN")
            {
                cout << "Como desea que se recorra el arbol (PRE, IN, POST, ANCHO)? " << endl;
            C1:
                cin >> eleccion;

                if (eleccion == "PRE")
                {
                    PreOrden(AN->raiz);
                    cout << endl;
                }
                else if (eleccion == "IN")
                {
                    EntreOrdenArbol(AN->raiz);
                    cout << endl;
                }
                else if (eleccion == "POST")
                {
                    PostOrden(AN->raiz);
                    cout << endl;
                }
                else if (eleccion == "ANCHO")
                {
                    RecorridoAnchuraArbol(AN->raiz);
                    cout << endl;
                }
                else if (eleccion != "PRE" || eleccion != "IN" || eleccion != "POST" || eleccion != "ANCHO")
                {
                    cout << "El nombre del recorrido debe ser PRE, IN, POST o ANCHO." << endl;
                    goto C1;
                }
            }
            else if (eleccion == "CE")
            {
                cout << "Como desea que se recorra el arbol (PRE, IN, POST, ANCHO)? " << endl;
            C2:
                cin >> eleccion;

                if (eleccion == "PRE")
                {
                    PreOrden(CE->raiz);
                    cout << endl;
                }
                else if (eleccion == "IN")
                {
                    EntreOrdenArbol(CE->raiz);
                    cout << endl;
                }
                else if (eleccion == "POST")
                {
                    PostOrden(CE->raiz);
                    cout << endl;
                }
                else if (eleccion == "ANCHO")
                {
                    RecorridoAnchuraArbol(CE->raiz);
                    cout << endl;
                }
                else if (eleccion != "PRE" || eleccion != "IN" || eleccion != "POST" || eleccion != "ANCHO")
                {
                    cout << "El nombre del recorrido debe ser PRE, IN, POST o ANCHO." << endl;
                    goto C2;
                }
            }
            else if (eleccion == "VL")
            {
                cout << "Como desea que se recorra el arbol (PRE, IN, POST, ANCHO)? " << endl;
            C3:
                cin >> eleccion;

                if (eleccion == "PRE")
                {
                    PreOrden(VL->raiz);
                    cout << endl;
                }
                else if (eleccion == "IN")
                {
                    EntreOrdenArbol(VL->raiz);
                    cout << endl;
                }
                else if (eleccion == "POST")
                {
                    PostOrden(VL->raiz);
                    cout << endl;
                }
                else if (eleccion == "ANCHO")
                {
                    RecorridoAnchuraArbol(VL->raiz);
                    cout << endl;
                }
                else if (eleccion != "PRE" || eleccion != "IN" || eleccion != "POST" || eleccion != "ANCHO")
                {
                    cout << "El nombre del recorrido debe ser PRE, IN, POST o ANCHO." << endl;
                    goto C3;
                }
            }
            else if (eleccion == "LE")
            {
                cout << "Como desea que se recorra el arbol (PRE, IN, POST, ANCHO)? " << endl;
            C4:
                cin >> eleccion;

                if (eleccion == "PRE")
                {
                    PreOrden(LE->raiz);
                    cout << endl;
                }
                else if (eleccion == "IN")
                {
                    EntreOrdenArbol(LE->raiz);
                    cout << endl;
                }
                else if (eleccion == "POST")
                {
                    PostOrden(LE->raiz);
                    cout << endl;
                }
                else if (eleccion == "ANCHO")
                {
                    RecorridoAnchuraArbol(LE->raiz);
                    cout << endl;
                }
                else if (eleccion != "PRE" || eleccion != "IN" || eleccion != "POST" || eleccion != "ANCHO")
                {
                    cout << "El nombre del recorrido debe ser PRE, IN, POST o ANCHO." << endl;
                    goto C4;
                }
            }
            else if (eleccion != "AN" || eleccion != "CE" || eleccion != "VL" || eleccion != "LE")
            {
                cout << "El nombre de la galaxia debe ser AN, CE, VL o LE." << endl;
                goto C;
            }
            cin.clear();
            cout << endl;
        }
        else if (opcion == "D")
        {
            cout << "En que galaxia desea borrar el cuerpo (AN, CE, VL, LE)?" << endl;
        D:
            cin >> eleccion;
            if (eleccion == "AN")
            {
                cout << "Introduce el nombre del cuerpo a eliminar: " << endl;
                cin >> eleccion;
                cout << "EntreOrden antes: ";
                EntreOrdenArbol(AN->raiz);
                cout << endl;
                eliminarNodo(AN->raiz, eleccion);
                cout << "EntreOrden despues: ";
                EntreOrdenArbol(AN->raiz);
                cout << endl;
            }
            else if (eleccion == "CE")
            {
                cout << "Introduce el nombre del cuerpo a eliminar: " << endl;
                cin >> eleccion;
                cout << "EntreOrden antes: ";
                EntreOrdenArbol(CE->raiz);
                cout << endl;
                eliminarNodo(CE->raiz, eleccion);
                cout << "EntreOrden despues: ";
                EntreOrdenArbol(CE->raiz);
                cout << endl;
            }
            else if (eleccion == "VL")
            {
                cout << "Introduce el nombre del cuerpo a eliminar: " << endl;
                cin >> eleccion;
                cout << "EntreOrden antes: ";
                EntreOrdenArbol(VL->raiz);
                cout << endl;
                eliminarNodo(VL->raiz, eleccion);
                cout << "EntreOrden despues: ";
                EntreOrdenArbol(VL->raiz);
                cout << endl;
            }
            else if (eleccion == "LE")
            {
                cout << "Introduce el nombre del cuerpo a eliminar: " << endl;
                cin >> eleccion;
                cout << "EntreOrden antes: ";
                EntreOrdenArbol(LE->raiz);
                cout << endl;
                eliminarNodo(LE->raiz, eleccion);
                cout << "EntreOrden despues: ";
                EntreOrdenArbol(LE->raiz);
                cout << endl;
            }
            else if (eleccion != "AN" || eleccion != "CE" || eleccion != "VL" || eleccion != "LE")
            {
                cout << "El nombre de la galaxia debe ser AN, CE, VL o LE." << endl;
                goto D;
            }
            cin.clear();
            cout << endl;
        }
        else if (opcion == "E")
        {
            string nombre, valor;

            cout << "Introduce el numero de cuerpos aleatorios que quieres crear: " << endl;
            cin >> numero;
            for (int i = 0; i < numero; i++)
            {
                nombre = nombreAleatorio();
                valor = nombre.substr(0, 2);

                if (valor == "AN")
                {
                    InsertarNodoArbol(AN, nombre, masaAleatoria(), distanciaAleatoria());
                }
                else if (valor == "CE")
                {
                    InsertarNodoArbol(CE, nombre, masaAleatoria(), distanciaAleatoria());
                }
                else if (valor == "VL")
                {
                    InsertarNodoArbol(VL, nombre, masaAleatoria(), distanciaAleatoria());
                }
                else if (valor == "LE")
                {
                    InsertarNodoArbol(LE, nombre, masaAleatoria(), distanciaAleatoria());
                }
            }
            cin.clear();
            cout << endl;
        }
        else if (opcion == "F")
        {
            string nombre, valor;

            cout << "Introduce el numero de cuerpos aleatorios que quieres crear: " << endl;
            cin >> numero;
            for (int i = 0; i < numero; i++)
            {
                nombre = nombreAleatorio();
                valor = nombre.substr(0, 2);

                if (valor == "AN")
                {
                    eliminarNodo(AN->raiz, nombre);
                }
                else if (valor == "CE")
                {
                    eliminarNodo(CE->raiz, nombre);
                }
                else if (valor == "VL")
                {
                    eliminarNodo(VL->raiz, nombre);
                }
                else if (valor == "LE")
                {
                    eliminarNodo(LE->raiz, nombre);
                }
            }
            cin.clear();
            cout << endl;
        }
        else if (opcion == "G")
        {
            string telescopio;
            string valor;
            nodoArbol nodoAux = new nodoA;

            for (int i = 0; i < 12; i++)
            {
                telescopio = nombreAleatorio();
                //Sleep(5000);
                numero = rand() % 100;
                valor = telescopio.substr(0, 2);

                if (numero <= 40)
                {
                    if (valor == "AN")
                    {
                        InsertarNodoArbol(AN, telescopio, masaAleatoria(), distanciaAleatoria());
                    }
                    else if (valor == "CE")
                    {
                        InsertarNodoArbol(CE, telescopio, masaAleatoria(), distanciaAleatoria());
                    }
                    else if (valor == "VL")
                    {
                        InsertarNodoArbol(VL, telescopio, masaAleatoria(), distanciaAleatoria());
                    }
                    else if (valor == "LE")
                    {
                        InsertarNodoArbol(LE, telescopio, masaAleatoria(), distanciaAleatoria());
                    }

                    cout << "Llegada " << telescopio << " .\n";
                }

                else if (numero >= 65)
                {

                    cout << "Procesamiento  " << telescopio << " OK .\n";

                    if (valor == "AN")
                    {
                        if (BusquedaNodoABB(AN->raiz, telescopio))
                        {
                            eliminarNodo(AN->raiz, telescopio);
                        }
                        else
                            cout << "El nodo " << telescopio << " no se encuentra en el arbol" << endl;
                    }
                    else if (valor == "CE")
                    {
                        if (BusquedaNodoABB(CE->raiz, telescopio))
                        {
                            eliminarNodo(CE->raiz, telescopio);
                        }
                        else
                            cout << "El nodo " << telescopio << " no se encuentra en el arbol" << endl;
                    }

                    else if (valor == "VL")
                    {
                        if (BusquedaNodoABB(VL->raiz, telescopio))
                        {
                            eliminarNodo(VL->raiz, telescopio);
                        }
                        else
                            cout << "El nodo " << telescopio << " no se encuentra en el arbol" << endl;
                    }

                    else if (valor == "LE")
                    {
                        if (BusquedaNodoABB(LE->raiz, telescopio))
                        {
                            eliminarNodo(LE->raiz, telescopio);
                        }
                        else
                            cout << "El nodo " << telescopio << " no se encuentra en el arbol" << endl;
                    }
                }
                else
                {
                    cout << "Procesamiento  " << telescopio << " KO. \n";
                    if (valor == "AN")
                    {
                        if (BusquedaNodoABB(AN->raiz, telescopio))
                        {
                            eliminarNodo(AN->raiz, telescopio);
                            InsertarNodoArbol(AN, telescopio, masaAleatoria(), distanciaAleatoria());
                        }
                        else
                            cout << "El nodo " << telescopio << " no se encuentra en el arbol" << endl;
                    }
                    else if (valor == "CE")
                    {
                        if (BusquedaNodoABB(CE->raiz, telescopio))
                        {
                            eliminarNodo(CE->raiz, telescopio);
                            InsertarNodoArbol(CE, telescopio, masaAleatoria(), distanciaAleatoria());
                        }
                        else
                            cout << "El nodo " << telescopio << " no se encuentra en el arbol" << endl;
                    }
                    else if (valor == "VL")
                    {
                        if (BusquedaNodoABB(VL->raiz, telescopio))
                        {
                            eliminarNodo(VL->raiz, telescopio);
                            InsertarNodoArbol(VL, telescopio, masaAleatoria(), distanciaAleatoria());
                        }
                        else
                            cout << "El nodo " << telescopio << " no se encuentra en el arbol" << endl;
                    }
                    else if (valor == "LE")
                    {
                        if (BusquedaNodoABB(LE->raiz, telescopio))
                        {
                            eliminarNodo(LE->raiz, telescopio);
                            InsertarNodoArbol(LE, telescopio, masaAleatoria(), distanciaAleatoria());
                        }
                        else
                            cout << "El nodo " << telescopio << " no se encuentra en el arbol" << endl;
                    }

                }


                cout << "COLA ANDROMEDA: ";
                EntreOrdenArbol(AN->raiz);
                cout << endl;
                cout << "COLA CENTAURO: ";
                EntreOrdenArbol(CE->raiz);
                cout << endl;
                cout << "COLA VIA LACTEA: ";
                EntreOrdenArbol(VL->raiz);
                cout << endl;
                cout << "COLA LEO: ";
                EntreOrdenArbol(LE->raiz);
                cout << endl;
                clock_t start_time = clock();
                clock_t end_time = 5 * 1000 + start_time;
                while (clock() != end_time);

            }

        }
        else if (opcion == "H")
        {
            int salida, destinacion;

            cout << "Introduce la estrella desde el cual desea partir(Altair(0), Bellatrix(1), Betelegeuse(2), Canopus(3), Capella(4), Mimosa(5), Mirach(6), Sirius(7), Vega(8), Vertex(9) o Zaniah(10))\n";
            cin >> salida;
            cout << "Hacia donde quiere ir?(Altair(0), Bellatrix(1), Betelegeuse(2), Canopus(3), Capella(4), Mimosa(5), Mirach(6), Sirius(7), Vega(8), Vertex(9) o Zaniah(10))\n";
            cin >> destinacion;
            dijkstra(matriz, salida, destinacion);
        }
        else if (opcion == "I")
        {
            break;
        }
        else
        {
            cout << "La opcion no es la valida";
        }
    }
}

int distanciaMinima(int dist[], bool set[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (set[v] == false &&
            dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printPath(int padre[], int j)
{

    if (padre[j] == -1)
        return;

    printPath(padre, padre[j]);

    printf("%d ", j);
}

int solucion(int dist[], int salida, int destiancion, int padre[])
{
    printf("--------------------------------");
    printf("\nVertice\t Distancia\tCamino");
    printf("\n%d -> %d \t %d\t\t%d ",
           salida, destiancion, dist[destiancion], salida);
    printPath(padre, destiancion);
}

void dijkstra(int grafo[n][n], int salida, int destinacion)
{
    int dist[n];
    bool set[n];
    int padre[n];

    for (int i = 0; i < n; i++)
    {
        padre[0] = -1;
        dist[i] = INT_MAX;
        set[i] = false;
    }

    dist[salida] = 0;

    for (int count = 0; count < n - 1; count++)
    {

        int u = distanciaMinima(dist, set);
        set[u] = true;

        for (int v = 0; v < n; v++)

            if (!set[v] && grafo[u][v] &&
                dist[u] + grafo[u][v] < dist[v])
            {
                padre[v] = u;
                dist[v] = dist[u] + grafo[u][v];
            }
    }

    solucion(dist, salida, destinacion, padre);
}

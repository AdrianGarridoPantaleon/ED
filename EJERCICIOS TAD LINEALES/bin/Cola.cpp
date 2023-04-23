#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct nodoC
{
    int valor;
    struct nodoC *sig;
} elnodoc;

typedef struct Cola
{
    struct nodoC *primero, *ultimo;
} * lacola;

lacola CreateCola()
{
    lacola co = new struct Cola;
    co->primero = new struct nodoC;
    co->ultimo = new struct nodoC;
    co->ultimo = NULL;
    co->primero->sig = NULL;

    return co;
}

bool EmptyCola(lacola co)
{
    if (co->primero->sig == NULL)
    {
        cout << "La cola esta vacia" << endl;
    }
    else
    {
        cout << "La cola no esta vacia" << endl;
    }
}

void InCola(lacola co, int v)
{
    struct nodoC *nodoAux;
    nodoAux = new struct nodoC;
    nodoAux->valor = v;

    if (co->primero->sig == NULL)
    {
        co->primero->sig = nodoAux;
        co->ultimo = nodoAux;
        co->ultimo->sig = NULL;
    }
    else
    {
        co->ultimo->sig = nodoAux;
        co->ultimo = nodoAux;
        co->ultimo->sig = NULL;
    }
}

void ViewCola(lacola co)
{
    struct nodoC *nodoAux;
    cout << "_______________________________________________" << endl;
    nodoAux = new struct nodoC;
    nodoAux = co->primero->sig;
    while (nodoAux != NULL)
    {
        cout << nodoAux->valor << endl;
        nodoAux = nodoAux->sig;
    }
}

int FirstCola(lacola co)
{
    if (co->primero->sig == NULL)
    {
        cout << "La cola esta vacia" << endl;
        return -1;
    }
    else
    {
        return (co->primero->sig->valor);
    }
}

int LastCola(lacola co)
{
    if (co->primero->sig == NULL)
    {
        cout << "La cola esta vacia" << endl;
        return -1;
    }
    else
    {
        return (co->ultimo->valor);
    }
}

int LongCola(lacola co)
{
    struct nodoC *nodoAux;
    int cont = 0;
    nodoAux = new struct nodoC;
    nodoAux = co->primero->sig;
    while (nodoAux != NULL)
    {
        cont++;
        nodoAux = nodoAux->sig;
    }
    return cont;
}

int main(int argc, char *argv[])
{
    lacola co = CreateCola();
    EmptyCola(co);
    //! insertamos valores en la cola
    InCola(co, 5);
    InCola(co, 3);
    InCola(co, 9);
    InCola(co, 12);
    ViewCola(co);
    cout << "La longitud de la cola es de: " << LongCola(co) << endl;
    cout << "La primero de la cola es: " << FirstCola(co) << endl;
    cout << "El ultimo de la cola es: " << LastCola(co) << endl;
}
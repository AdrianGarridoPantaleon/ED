#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

typedef struct nodoA
{
    string nombre;
    int masa;
    double distancia;
    struct nodoA *izq, *der;
} * nodoArbol;

typedef struct Tree
{
    struct nodoA *raiz;
} * arbol;

typedef struct nodoC
{
    struct nodoA *dato;
    struct nodoC *sig;
} elnodoc;

typedef struct Cola
{
    struct nodoC *primero, *ultimo;

} * lacola;

//!Galaxias
lacola Andromeda;
lacola Centauro;
lacola ViaLactea;
lacola Leo;
string telescopios[4] = {"AN", "CE", "VL", "LE"};
string cuerposCelestes[3] = {"S", "P", "M"};

lacola CreateCola()
{
    lacola co = new struct Cola;
    co->primero = new struct nodoC;
    co->ultimo = new struct nodoC;
    co->ultimo = NULL;
    co->primero->sig = NULL;

    return co;
}

arbol CrearArbol()
{
    arbol ar = new struct Tree;
    ar->raiz = new struct nodoA;
    ar->raiz->nombre = "";
    ar->raiz->masa = -1;
    ar->raiz->distancia = -1;

    ar->raiz->izq = ar->raiz->der = NULL;
    return ar;
}

bool ArbolVacio(arbol ar)
{
    if (ar->raiz->nombre == "")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void InCola(lacola co, nodoArbol ar)
{
    struct nodoC *nodoAux;
    nodoAux = new struct nodoC;
    nodoAux->dato = ar;

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

nodoArbol ExtraerCuerpo(lacola co)
{
    struct nodoC *nodoAux = new struct nodoC;
    nodoAux = co->primero->sig;
    co->primero->sig = nodoAux->sig;

    if (nodoAux == NULL)
    {
        co->ultimo->sig = NULL;
    }
    return nodoAux->dato;
}

void InsertarNodoArbol(arbol ar, string nombre, int masa, double distancia)
{
    struct nodoA *nodoPadre, *nodoAux;
    nodoPadre = new struct nodoA;
    nodoAux = new struct nodoA;
    nodoPadre = NULL;
    nodoAux = ar->raiz;

    if (ArbolVacio(ar))
    {
        nodoAux->nombre = nombre;
        nodoAux->masa = masa;
        nodoAux->distancia = distancia;
        cout << nodoAux->nombre << endl;
        return;
    }

    //! RRECORRER EL ARBOL HASA INSERTARLO
    while ((nodoAux != NULL) && (nodoAux->nombre != nombre))
    {
        nodoPadre = nodoAux;
        if (nombre < nodoAux->nombre)
        {
            nodoAux = nodoAux->izq;
        }
        else
        {
            nodoAux = nodoAux->der;
        }
    }

    //! SI SE HA ENCONTRADO EL ELEMENTO REGRESAR SIN INSERTAR
    if (nodoAux != NULL)
    {
        cout << "El " << nombre << " no se puede insertar pues ya existe" << endl;
        return;
    }

    if (nombre < nodoPadre->nombre)
    {
        struct nodoA *nodo;
        nodo = new struct nodoA;
        nodoPadre->izq = nodo;
        nodo->nombre = nombre;
        nodo->masa = masa;
        nodo->distancia = distancia;
        nodo->der = nodo->izq = NULL;
        cout << nodo->nombre << endl;
    }
    else
    {
        struct nodoA *nodo;
        nodo = new struct nodoA;
        nodoPadre->der = nodo;
        nodo->nombre = nombre;
        nodo->masa = masa;
        nodo->distancia = distancia;
        nodo->der = nodo->izq = NULL;
        cout << nodo->nombre << endl;
    }
}

bool BusquedaNodoABB(nodoArbol nodo, string nombre)
{
    bool fin = false;
    bool encontrado = true;

    while (!fin)
    {
        if (nodo == NULL)
        {
            encontrado = false;
            fin = true;
        }
        else if (nodo->nombre == nombre)
        {
            encontrado = true;
            fin = true;
        }
        else
        {
            if (nodo->nombre < nombre)
            {
                nodo = nodo->der;
            }
            else
            {
                nodo = nodo->izq;
            }
        }
    }
    return encontrado;
}

void RecorridoAnchuraArbol(nodoArbol ar)
{
    if (ar == NULL)
        return;

    queue<nodoArbol> cola;

    cola.push(ar);

    while (cola.empty() == false)
    {
        nodoArbol nodo = cola.front();
        cout << nodo->nombre << " ";
        cola.pop();

        if (nodo->izq != NULL)
        {
            cola.push(nodo->izq);
        }
        if (nodo->der != NULL)
        {
            cola.push(nodo->der);
        }
    }
}

void PreOrden(nodoArbol nodo)
{
    if (nodo)
    {
        cout << nodo->nombre << " ";
        PreOrden(nodo->izq);
        PreOrden(nodo->der);
    }
}

void EntreOrdenArbol(nodoArbol nodo)
{
    if (nodo)
    {
        EntreOrdenArbol(nodo->izq);
        cout << nodo->nombre << " ";
        EntreOrdenArbol(nodo->der);
    }
}

void PostOrden(nodoArbol nodo)
{
    if (nodo)
    {
        PostOrden(nodo->izq);
        PostOrden(nodo->der);
        cout << nodo->nombre << " ";
    }
}

nodoArbol obtenerValorMinimo(nodoArbol aux)
{
    while (aux->izq != NULL)
    {
        aux = aux->izq;
    }
    return aux;
}

void buscarValor(nodoArbol &aux, string nombre, nodoArbol &nodoPadre)
{
    while (aux != NULL && aux->nombre != nombre)
    {
        nodoPadre = aux;

        if (nombre < aux->nombre)
        {
            aux = aux->izq;
        }
        else
        {
            aux = aux->der;
        }
    }
}

void eliminarNodo(nodoArbol &raiz, string nombre)
{
    nodoArbol nodoPadre = NULL;

    nodoArbol aux = raiz;
    buscarValor(aux, nombre, nodoPadre);

    if (aux == NULL)
    {
        return;
    }

    if (aux->izq == NULL && aux->der == NULL)
    {
        if (aux != raiz)
        {
            if (nodoPadre->izq == aux)
            {
                nodoPadre->izq = NULL;
            }
            else
            {
                nodoPadre->der = NULL;
            }
        }
        else
        {
            raiz = NULL;
        }

        free(aux);
    }

    else if (aux->izq && aux->der)
    {
        nodoArbol successor = obtenerValorMinimo(aux->der);

        string val = successor->nombre;

        eliminarNodo(raiz, successor->nombre);

        aux->nombre = val;
    }

    else
    {
        nodoArbol hijo = (aux->izq) ? aux->izq : aux->der;

        if (aux != raiz)
        {
            if (aux == nodoPadre->izq)
            {
                nodoPadre->izq = hijo;
            }
            else
            {
                nodoPadre->der = hijo;
            }
        }

        else
        {
            raiz = hijo;
        }
        free(aux);
    }
}

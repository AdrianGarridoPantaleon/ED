#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct nodoA
{
    int valor;
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
    ar->raiz->valor = -1;
    ar->raiz->izq = ar->raiz->der = NULL;
    return ar;
}

bool ArbolVacio(arbol ar)
{
    if (ar->raiz->valor == -1)
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

void InsertarValorArbol(arbol ar, int valor)
{
    struct nodoA *nodoPadre, *nodoAux;
    nodoPadre = new struct nodoA;
    nodoAux = new struct nodoA;
    nodoPadre = NULL;
    nodoAux = ar->raiz;

    if (ArbolVacio(ar))
    {
        nodoAux->valor = valor;
        return;
    }

    //! RRECORRER EL ARBOL HASA INSERTARLO
    while ((nodoAux != NULL) && (nodoAux->valor != valor))
    {
        nodoPadre = nodoAux;
        if (valor < nodoAux->valor)
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
        //cout << "El " << valor << " no se puede insertar pues ya existe" << endl;
        return;
    }

    if (valor < nodoPadre->valor)
    {
        struct nodoA *nodo;
        nodo = new struct nodoA;
        nodoPadre->izq = nodo;
        nodo->valor = valor;
        nodo->der = nodo->izq = NULL;
    }
    else
    {
        struct nodoA *nodo;
        nodo = new struct nodoA;
        nodoPadre->der = nodo;
        nodo->valor = valor;
        nodo->der = nodo->izq = NULL;
    }
}

bool BusquedaValorArbol(nodoArbol nodo, int valor)
{
    if (nodo == NULL)
    {
        return false;
    }
    if (nodo->valor = valor)
    {
        return true;
    }
    else
    {
        if (nodo->valor < valor)
        {
            return BusquedaValorArbol(nodo->der, valor);
        }
        else
        {
            return BusquedaValorArbol(nodo->izq, valor);
        }
    }
}

void RecorridoAnchuraArbol(arbol ar)
{
    struct nodoA *nodoAux = ar->raiz;
    struct Cola *cola = CreateCola();
    while (nodoAux)
    {
        cout << nodoAux->valor << " ";

        if (nodoAux->izq)
        {
            InCola(cola, nodoAux->izq);
        }
        if (nodoAux->der)
        {
            InCola(cola, nodoAux->der);
        }
        nodoAux = ExtraerCuerpo(cola);
    }
}

void PreOrden(nodoArbol nodo)
{
    if (nodo)
    {
        cout << nodo->valor << " ";
        PreOrden(nodo->izq);
        PreOrden(nodo->der);
    }
}

void EntreOrdenArbol(nodoArbol nodo)
{
    if (nodo)
    {
        EntreOrdenArbol(nodo->izq);
        cout << nodo->valor << " ";
        EntreOrdenArbol(nodo->der);
    }
}

void PostOrden(nodoArbol nodo)
{
    if (nodo)
    {
        PostOrden(nodo->izq);
        PostOrden(nodo->der);
        cout << nodo->valor << " ";
    }
}

bool BorrarValorArbol(nodoArbol ar, int valor)
{
    //! Creamos variables para saber si tiene hijos izquierdo y derecho

    bool tieneNodoDerecha = ar->der != NULL ? true : false;
    bool tieneNodoIzquierda = ar->izq != NULL ? true : false;

    //! El nodo no tiene nodos hijos

    if (!tieneNodoDerecha && !tieneNodoIzquierda)
    {
        return BorrarValorArbol1(ar,valor);
    }

    //! El nodo tiene 1 hijo

    if (tieneNodoDerecha && !tieneNodoIzquierda)
    {
        return BorrarValorArbol2(nodo);
    }
    if (!tieneNodoDerecha && tieneNodoIzquierda)
    {
        return BorrarValorArbol2(nodo);
    }
    //! El nodo tiene 2 hijos

    if (tieneNodoDerecha && tieneNodoIzquierda)
    {
        return BorrarValorArbol3(nodo);
    }

    return false;
}

bool BorrarValorArbol1(arbol ar)
{
    Nodo hijoIzquierdo = nodo.getPadre().getHojaIzquierda();
    Nodo hijoDerecho = nodo.getPadre().getHojaDerecha();

    if (hijoIzquierdo == nodo)
    {
        nodo.getPadre().setHojaIzquierda(NULL);
        return true;
    }

    if (hijoDerecho == nodo)
    {
        nodo.getPadre().setHojaDerecha(NULL);
        return true;
    }

    return false;
}

bool BorrarValorArbol2(arbol ar)
{
    Nodo hijoIzquierdo = nodo.getPadre().getHojaIzquierda();
    Nodo hijoDerecho = nodo.getPadre().getHojaDerecha();

    //! Buscamos el hijo existente del nodo que queremos eliminar

    Nodo hijoActual = nodo.getHojaIzquierda() != NULL ? nodo.getHojaIzquierda() : nodo.getHojaDerecha();

    if (hijoIzquierdo == nodo)
    {
        nodo.getPadre().setHojaIzquierda(hijoActual);

        //! Eliminando todas las referencias hacia el nodo
        hijoActual.setPadre(nodo.getPadre());
        nodo.setHojaDerecha(NULL);
        nodo.setHojaIzquierda(NULL);

        return true;
    }

    if (hijoDerecho == nodo)
    {
        nodo.getPadre().setHojaDerecha(hijoActual);

        //! Eliminando todas las referencias hacia el nodo
        hijoActual.setPadre(nodo.getPadre());
        nodo.setHojaDerecha(NULL);
        nodo.setHojaIzquierda(NULL);

        return true;
    }

    return false;
}

bool BorrarValorArbol3(arbol ar)
{
    //! Tomar el hijo derecho del Nodo que queremos eliminar
    Nodo nodoMasALaIzquierda = recorrerIzquierda(nodo.getHojaDerecha());
    if (nodoMasALaIzquierda != NULL)
    {
        /*
         * Reemplazamos el valor del nodo que queremos eliminar por el nodo que encontramos 
         */
        nodo.setValor(nodoMasALaIzquierda.getValor());
        /* 
         * Eliminar este nodo de las formas que conocemos ( caso 1, caso 2 ) 
         */
        BorrarValorArbol(nodoMasALaIzquierda);
        return true;
    }
    return false;
}

//! Recorrer de forma recursiva hasta encontrar el nodo más a la izquierda
Nodo recorrerIzquierda(Nodo nodo)
{
    if (nodo.getHojaIzquierda() != NULL)
    {
        return recorrerIzquierda(nodo.getHojaIzquierda());
    }
    return nodo;
}

/*void BorrarValorSubArbol(arbol ar, int valor)
{
}

bool ArbolesIguales(arbol arbol1, arbol arbol2)
{
}

int GradoArbol(arbol ar)
{
}

int AlturaArbol(arbol ar)
{
}*/

int main(int argc, char *argv[])
{
    arbol elArbol;
    elArbol = CrearArbol();
    //!PARA SABER SI EL ARBOL ESTA VACIO
    /*if (ArbolVacio(elArbol))
    {
        cout << "El arbol esta vacio" << endl;
    }
    else
    {
        cout << "El arbol no esta vacio" << endl;
    }*/

    InsertarValorArbol(elArbol, 10);
    InsertarValorArbol(elArbol, 2);
    InsertarValorArbol(elArbol, 7);
    InsertarValorArbol(elArbol, 5);
    InsertarValorArbol(elArbol, 18);
    InsertarValorArbol(elArbol, 15);
    InsertarValorArbol(elArbol, 19);
    cout << "RecorridoAnchura: ";
    RecorridoAnchuraArbol(elArbol);
    cout << "\nPreOrden: ";
    PreOrden(elArbol->raiz);
    cout << "\nEntreOrden: ";
    EntreOrdenArbol(elArbol->raiz);
    cout << "\nPostOrden: ";
    PostOrden(elArbol->raiz);
    //!PARA SABER SI UN VALOR ESTÁ EN EL ARBOL
    /*int num = 15;
    if (BusquedaValorArbol(elArbol->raiz, num))
        cout << "Existe en el arbol" << endl;
    else
        cout << "No existe en el arbol" << endl;*/
}
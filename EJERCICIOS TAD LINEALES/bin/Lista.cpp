#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

typedef struct nodoL
{
    int valor;
    struct nodoL *sig;
} * Lista;

Lista CreateList()
{
    Lista list;
    list = new struct nodoL;
    list->sig = NULL;
    return list;
}
void InsertElementList(Lista l, int v)
{
    struct nodoL *nodoAux;
    Lista laux = CreateList();
    //! hay que encontrar donde posicionar el puntero conforme al orden de la lista
    laux = l;
    while ((laux->sig != NULL) && (laux->sig->valor < v))
    {
        laux = laux->sig;
    }
    nodoAux = new struct nodoL;
    nodoAux->valor = v;
    nodoAux->sig = laux->sig;
    laux->sig = nodoAux;
}
void InsertElementFirstList(Lista l, int v)
{
    struct nodoL *nodoAux;
    nodoAux = new struct nodoL;
    nodoAux->valor = v;
    nodoAux->sig = l->sig;
    l->sig = nodoAux;
}
void InsertValueList(Lista l, long int v)
{
    srand(time(NULL));
    for (long int i = 1; i < v; i++)
    {
        InsertElementList(l, rand() % 10000);
    }
}
void InsertValueFirstList(Lista l, long int v)
{
    srand(time(NULL));
    for (int i = 1; i < v; i++)
    {
        InsertElementFirstList(l, rand() % 10000);
    }
}
void ViewList(Lista l)
{
    //! Lista donde almacenamos los valores sin ordenar
    cout << "_______________________________________________" << endl;
    Lista laux = CreateList();
    laux = l->sig;

    int cont = 1;
    while (laux != NULL)
    {
        cout << laux->valor << "---------------------------------------------" << cont++ << endl;
        laux = laux->sig;
    }
    cout << endl;
}
long CountElementList(Lista l, int v)
{
    Lista laux = CreateList();
    laux = l->sig;
    long cont = 0;
    //! While (laux!=NULL) && (laux->valor<=v)

    while (laux != NULL)
    {
        if (laux->valor == v)
            cont++;
        laux = laux->sig;
    }
    return cont;
}
Lista FindElementList(Lista, int v)
{
}
int LongList(Lista l)
{
    long cont = 0;
    Lista laux = CreateList();
    laux = l->sig;

    while (laux != NULL)
    {
        cont++;
        laux = laux->sig;
    }
    return cont;
}
bool EmptyList(Lista l)
{
    if (l->sig == NULL)
    {
        cout << "La lista esta vacia" << endl;
        return true;
    }
    else
        cout << "La lista no esta vacia" << endl;
    return false;
}
bool EraseElementList(Lista l, int v)
{
    Lista laux = CreateList();
    laux = l;
    while ((laux->sig != NULL) && (laux->sig->valor < v))
    {
        laux = laux->sig;
    }
    if ((laux->sig == NULL) || (laux->sig->valor != v))
    {
        return false;
    }
    else
    {
        struct nodoL *nodoAux;
        nodoAux = new struct nodoL;
        nodoAux = laux->sig;
        laux->sig = laux->sig->sig;
        delete nodoAux; //! Cuidado con el destructor
        return true;
    };
}
int main(int argc, char *argv[])
{
    Lista l;
    l = CreateList();
   /* InsertElementList(l, 8);
    InsertElementList(l, 5);
    InsertElementList(l, 2);
    InsertElementList(l, 7);
    ViewList(l);
    //EraseElementList(l, 5);
    ViewList(l);*/
    /*  cout << "Principio de insercion: " << endl;
    InsertValueFirstList(l, 10000);
    ViewList(l);
    cout << "Fin de insercion: " << endl;
    cout << "El numero 8 aparece " << CountElementList(l, 70) << " veces" << endl;*/
    /* //! Ordenado
    InsertElementList(l, 8);
    InsertElementList(l, 5);
    InsertElementList(l, 2);
    InsertElementList(l, 7);*/
    //! Sin ordenar
    InsertElementFirstList(l, 5);
    InsertElementFirstList(l, 1);
    InsertElementFirstList(l, 8);
    InsertElementFirstList(l, 8);
    ViewList(l);

    /* cout << "El numero de nodos de la lista es de: " << LongList(l) << endl;
    EmptyList(l);
    cout << "El numero 8 aparece " << CountElementList(l, 8) << " veces" << endl;*/
}

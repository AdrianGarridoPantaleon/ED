#include <cstdlib>
#include <iostream>
#include <time.h>
#include <sstream>
#include <ctime>
#include <windows.h>

using namespace std;

typedef struct cuerpoC
{
    struct cuerpoC *sig;
    string nombre;
    string tipo;
    int masa;
    double distancia;

} elcuerpo;

typedef struct Galaxia
{
    struct cuerpoC *primero, *ultimo;
} * laGalaxia;

//!Galaxias
laGalaxia Andromeda;
laGalaxia Centauro;
laGalaxia ViaLactea;
laGalaxia Leo;
string telescopios[4] = {"AN", "CE", "VL", "LE"};
string cuerposCelestes[3] = {"S", "P", "M"};

//! Opciones
void opcionesMenu();
void menu();
string selecionarTel();
string insertarNombre(laGalaxia ga, string cCelestes, string telescopio);
string opcion;

//! Colas
laGalaxia CreateGalaxia()
{
    laGalaxia ga = new struct Galaxia;
    ga->primero = new struct cuerpoC;
    ga->ultimo = new struct cuerpoC;
    ga->ultimo = NULL;
    ga->primero->sig = NULL;

    return ga;
}

bool EmptyGalaxia(laGalaxia ga)
{
    if (ga->primero->sig == NULL)
    {
        cout << "La Galaxia esta vacia" << endl;
        return true;
    }
    else
    {
        cout << "La Galaxia no esta vacia" << endl;
        return false;
    }
}

bool BuscarGalaxia(laGalaxia ga, string nombre)
{
    struct cuerpoC *nodoAux;
    nodoAux = ga->primero->sig;

    while (nodoAux != NULL)
    {
        if (nodoAux->nombre == nombre)
        {
            return true;
        }
        nodoAux = nodoAux->sig;
    }
    return false;
}

string nombreAzar(string cuerpo, string telescopio)
{
    string numeroAzar;
    stringstream num;
    num << rand() % 999;
    num >> numeroAzar;
    if (numeroAzar.length() == 2)
    {
        numeroAzar = "0" + numeroAzar;
    }
    if (numeroAzar.length() == 1)
    {
        numeroAzar = "00" + numeroAzar;
    }
    return telescopio + numeroAzar + cuerpo;
}

void menu()
{

    cout << "Opciones: \n";
    cout << "A. Introducir mAndromedaualmente un cuerpo.\n";
    cout << "B. Extraer el primer cuerpo del telescopio deseado.\n";
    cout << "C. Mostrar los cuerpos celestes deseados.\n";
    cout << "D. Consultar los cuerpos del inicio o del final del telescopio.\n";
    cout << "E. Insertar n cuerpos al azar en el telescopio indicado.\n";
    cout << "F. Iniciar la simulacion\n";
    cout << "G. Salir de la aplicacion.\n";
}

string tipoCuerpo()
{
    string cuerpo;

    do
    {
        cout << "\nIntroduce el tipo de cuerpo: ";
        cin >> cuerpo;
        if (cuerpo == cuerposCelestes[0])
        {
            return cuerposCelestes[0];
        }
        else if (cuerpo == cuerposCelestes[1])
        {

            return cuerposCelestes[1];
        }
        else if (cuerpo == cuerposCelestes[2])
        {

            return cuerposCelestes[2];
        }

        else
        {
            cout << "\nTipo de cuerpo no valido";
        }
    } while (0 == 0);
}

elcuerpo datos(laGalaxia ga, string telescopio)
{
    string nombre, cuerposCelestes;
    int m;
    double d;
    elcuerpo *nodoAux = new cuerpoC;

    if (opcion == "F" || opcion == "f")
    {

        cuerposCelestes = cuerposCelestes[rand() % 3];
        d = rand() % 1000 + 1;
        m = rand() % 20 + 1;
    }
    else
    {

        cuerposCelestes = tipoCuerpo();

        cout << "Introduce la masa: ";
        cin >> m;
        cout << "Introduce la distancia :";
        cin >> d;
    }

    nodoAux->nombre = insertarNombre(ga, cuerposCelestes, telescopio);
    nodoAux->tipo = cuerposCelestes;
    nodoAux->masa = m;
    nodoAux->distancia = d;

    return *nodoAux;
}

void InGalaxia(laGalaxia ga, string telescopio)
{
    elcuerpo *nodoAux = new cuerpoC;

    *nodoAux = datos(ga, telescopio);

    if (ga->primero->sig == NULL)
    {
        ga->primero->sig = nodoAux;
        ga->ultimo = nodoAux;
        ga->ultimo->sig = NULL;
    }
    else
    {
        ga->ultimo->sig = nodoAux;
        ga->ultimo = nodoAux;
        ga->ultimo->sig = NULL;
    }
}

void ViewGalaxia(laGalaxia ga)
{
    struct cuerpoC *nodoAux;
    cout << "_______________________________________________" << endl;
    nodoAux = new struct cuerpoC;
    nodoAux = ga->primero->sig;
    while (nodoAux != NULL)
    {
        cout << nodoAux->nombre << endl;
        nodoAux = nodoAux->sig;
    }
    delete nodoAux;
}

string FirstGalaxia(laGalaxia ga)
{
    if (ga->primero->sig == NULL)
    {

        return "La Galaxia esta vacia";
    }
    else
    {
        return (ga->primero->sig->nombre);
    }
}

string LastGalaxia(laGalaxia ga)
{
    if (ga->primero->sig == NULL)
    {

        return "La Galaxia esta vacia";
    }
    else
    {
        return (ga->ultimo->nombre);
    }
}

elcuerpo *ExtraerCuerpo(laGalaxia ga)
{
    struct cuerpoC *nodoAux = new struct cuerpoC;
    nodoAux = ga->primero->sig;
    ga->primero->sig = nodoAux->sig;

    if (nodoAux == NULL)
    {
        ga->ultimo->sig = NULL;
    }
    return nodoAux;
}

laGalaxia Tel(string telescopio)
{

    if (telescopio == telescopios[0])
    {

        return Andromeda;
    }
    else if (telescopio == telescopios[1])
    {
        return Centauro;
    }
    else if (telescopio == telescopios[2])
    {
        return ViaLactea;
    }
    else if (telescopio == telescopios[3])
    {
        return Leo;
    }
}

string selecionarTel()
{
    int cont = 0;
    string telescopio;
    do
    {
        cout << "\nIntroduce el telescopio: ";
        cin >> telescopio;
        if (telescopio == telescopios[0])
        {
            return telescopios[0];
        }
        else if (telescopio == telescopios[1])
        {
            return telescopios[1];
        }
        else if (telescopio == telescopios[2])
        {
            return telescopios[2];
        }
        else if (telescopio == telescopios[3])
        {
            return telescopios[3];
        }
        else
        {
            cout << "Telescopio incorrecto";
            cout << "\nIntroduce de nuevo el telescopio: ";
            cin >> telescopio;
            cont = 1;
        }
    } while (cont = !0);
}

string insertarNombre(laGalaxia ga, string cCelestes, string telescopio)
{
    string nombre;
    elcuerpo *nodoAux = new cuerpoC;
    int cont = 0;
    nombre = nombreAzar(cCelestes, telescopio);

    if (cont > 0)
    {
        insertarNombre(ga, cCelestes, telescopio);
    }
    else
    {
        return nombre;
    }
}

void simulacion()
{
    string telescopio;
    elcuerpo *nodoAux = new cuerpoC;
    int numero;
    for (int i = 0; i < 12; i++)
    {
        Sleep(5000);
        numero = rand() % 100;
        telescopio = telescopios[rand() % 4];

        if (numero <= 40)
        {
            InGalaxia(Tel(telescopio), telescopio);
            cout << "Llegada " << Tel(telescopio)->ultimo->nombre << " .\n";
        }

        else if (numero >= 65)
        {

            cout << "Procesamiento  " << Tel(telescopio)->primero->nombre << " OK .\n";
            ExtraerCuerpo(Tel(telescopio));
        }
        else
        {
            cout << "Procesamiento  " << Tel(telescopio)->primero->nombre << " KO. \n";
            nodoAux->nombre = Tel(telescopio)->primero->nombre;
            nodoAux->tipo = Tel(telescopio)->primero->tipo;
            nodoAux->masa = Tel(telescopio)->primero->masa;
            nodoAux->distancia = Tel(telescopio)->primero->distancia;
            nodoAux->sig = NULL;

            ExtraerCuerpo(Tel(telescopio));

            Tel(telescopio)->ultimo->sig = nodoAux;
            Tel(telescopio)->ultimo = nodoAux;
        }

        for (int j = 0; j < 4; j++)
        {
            ViewGalaxia(Tel(telescopios[j]));
            cout << endl;
        }
    }
}

    void opcionesMenu()
    {

        int datos;
        int numero;

        laGalaxia Andromeda = CreateGalaxia();
        laGalaxia Centauro = CreateGalaxia();
        laGalaxia ViaLactea = CreateGalaxia();
        laGalaxia Leo = CreateGalaxia();

        laGalaxia galAux;
        menu();
        while (1)
        {
            string tel;
            cout << "\nIntroduce la opcion:";
            cin >> opcion;

            if (opcion == "A")
            {
                tel = selecionarTel();
                InGalaxia(Tel(tel), tel);
            }
            else if (opcion == "B")
            {
                ExtraerCuerpo(Tel(selecionarTel()));
            }
            else if (opcion == "C")
            {

                ViewGalaxia(Tel(selecionarTel()));
            }
            else if (opcion == "D")
            {

                FirstGalaxia(Tel(selecionarTel()));
                LastGalaxia(Tel(selecionarTel()));
            }
            else if (opcion == "E")
            {
                int n;
                cout << "Introduce el numero de cuerpos deseado :";
                cin >> n;
            }
            else if (opcion == "F")
            {
                simulacion();
            }
            else if (opcion == "G")
            {
                break;
            }
            else
            {
                cout << "La opcion no es la valida";
            }
        }
    }

    void intCuerpos(int n)
    {
        string telescopio;
        for (int i = 0; i < n; i++)
        {
            telescopio = telescopios[rand() % 4];
            InGalaxia(Tel(telescopio), telescopio);
        }
    }
int main (int argc,char *argv[])
{

}

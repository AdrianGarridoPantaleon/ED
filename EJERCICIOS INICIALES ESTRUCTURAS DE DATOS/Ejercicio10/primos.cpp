 #include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    // Variables a utilizar en el programa
    int numero=0;
    int divisores=0;
    int primo=0; // primo = 0 no primo = 1
    // Solicitar numero entero hasta valor -1

    do
    {
       cout<<"\nIntroduce un numero: "<<endl;
       cin>>numero;
        if(numero!=-1 && numero>0)
        {
            // el numero es valido comprobar si es primo
            primo=0;
            divisores=2;
            while(divisores<numero  && primo!=1)
            {
                if(numero%divisores==0) primo=1;
                divisores++;
            }
            // Si primo vale 0 es que el numero es primo
            if (primo==0)
            {
                cout<<"\nEl numero"<<" "<<numero<<" es primo"<<endl;

            }
            else
            {
                 cout<<"\nEl numero"<<" "<<numero<<" no es primo"<<endl;

            }
        }
    } while(numero!=-1);
    return 0;
}

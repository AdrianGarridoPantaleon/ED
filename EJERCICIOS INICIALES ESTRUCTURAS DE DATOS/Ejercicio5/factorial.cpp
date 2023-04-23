#include <iostream>

using namespace std;

int main()
{
    int numero;
    int resultado;
    int aux;
    int condicion;

    cout<<"introduce el numero a calcular: ";
    cin>>numero;

    condicion=numero;
    aux=numero-1;

    for(int i=0; i<condicion-1; i++){
        numero=numero*aux;
        aux--;

    }

    cout<<"\t"<<condicion<<"!= "<<numero<<endl;

    return 0;
}

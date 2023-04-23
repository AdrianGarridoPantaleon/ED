#include <iostream>

using namespace std;

int main()
{
    double radio;
    double longitud;
    double superficie;
    double pi=3.141592;

    cout<<"Introduce el radio: "<<endl;
    cin>>radio;

    longitud=2*pi*radio;
    superficie=pi*(radio*radio);

    cout<<"El valor de la longitud es de: "<<longitud<<" Unidades"<<endl;
    cout<<"El valor de la superficie es de: "<<superficie<<" Unidades^2"<<endl;

    return 0;
}

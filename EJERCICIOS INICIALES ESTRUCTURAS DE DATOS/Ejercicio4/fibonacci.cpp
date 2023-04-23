#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int numeroTerminos;
    int x1=1;
    int x2=1;
    int aux;

    cout<<"Introduce el numero de terminos deseado: "<<endl;
    cin>>numeroTerminos;
    cout<<endl;

    cout<<x1<<endl;
    for(int i=0; i<=numeroTerminos; i++){

       cout<<x1<<endl;
       aux=x1;
       x1=x1+x2;
       x2=aux;


    }

    return 0;
}

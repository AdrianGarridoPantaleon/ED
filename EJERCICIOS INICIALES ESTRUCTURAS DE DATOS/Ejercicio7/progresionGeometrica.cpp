#include <iostream>

using namespace std;

int main()
{
    int termino;
    int razon;
    int resultado;
    int numeroTermino;

    cout<<"Introduce el termino:"<<endl;
    cin>>termino;
    cout<<"Introduce la razon:"<<endl;
    cin>>razon;
    cout<<"Introduce el numero de terminos deseados:"<<endl;
    cin>>numeroTermino;
    cout<<endl;

    cout<<termino<<endl;
    for(int i=0; i<numeroTermino; i++){

        resultado=termino*razon;
        termino=resultado;

        cout<<termino<<endl;

    }
    return 0;
}

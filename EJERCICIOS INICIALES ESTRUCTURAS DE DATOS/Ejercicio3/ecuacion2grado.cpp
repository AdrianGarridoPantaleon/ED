#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a;
    int b;
    int c;

    cout<<"Introduce el valor del parametro 1"<<endl;
    cin>>a;
    cout<<"Introduce el valor del parametro 2"<<endl;
    cin>>b;
    cout<<"Introduce el valor del parametro 3"<<endl;
    cin>>c;

    double x1=((-b+sqrt(((b*b)-4*a*c)))/(2*a));
    double x2=((-b-sqrt(((b*b)-4*a*c)))/(2*a));

    if(((b*b)-4*a*c)<0){

        cout<<"La ecuacion NO tiene solucion"<<endl;
    }else if(2*a==0){

    cout<<"La ecuacion tiende a infinito"<<endl;

    }else{

    cout<<"El valor de x1= "<<x1<<endl;
    cout<<"El valor de x2= "<<x2<<endl;
    }

    return 0;
}

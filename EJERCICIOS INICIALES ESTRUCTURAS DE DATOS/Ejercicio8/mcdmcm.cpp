#include <iostream>

using namespace std;

int mcd(int a,int b){
    int resultado=1;
    for(int i=1;i<=a;i++){
        if((a%i==0) && (b%i==0)){
            resultado=i;
        }
    }
    return resultado;
}
int mcm(int a,int b){

    return ((a*b)/mcd(a,b));
}
int main()
{
    int a;
    int b;

    cout<<"Introduce el valor de a: "<<endl;
    cin>>a;
    cout<<endl;
    cout<<"Introduce el valor de b: "<<endl;
    cin>>b;
    cout<<endl;

    int resultado=mcd(a,b);
    cout<<"El maximo comun divisor de "<<a<<" y "<<b<<" es: "<<resultado<<endl;
    cout<<endl;
    int n=mcm(a,b);
    cout<<"El minimo comun multiplo de "<<a<<" y "<<b<<" es: "<<n<<endl;


    return 0;
}

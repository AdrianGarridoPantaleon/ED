#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int numeros[]={8,7,9,1,3,6,2,10,4,5};
    int i,j,aux;

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(numeros[j]>numeros[j+1]){
                aux=numeros[j];
                numeros[j]=numeros[j+1];
                numeros[j+1]=aux;
            }
        }
    }
    cout<<"El array ordenado se quedaria de la siguiente forma: "<<endl;
    for(i=0;i<10;i++){
        cout<<numeros[i];
    }


    return 0;
}

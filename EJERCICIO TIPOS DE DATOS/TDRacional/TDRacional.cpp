#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct RACIONAL{

int numerador;
int denominador;

}racional;

racional introducirRacional(RACIONAL r);

bool equivalencia(RACIONAL r1,RACIONAL r2);

racional simplificacion(RACIONAL r);

void orden(RACIONAL r1, RACIONAL r2);

int suma (RACIONAL r1,RACIONAL r2);

int resta (RACIONAL r1,RACIONAL r2);

int multiplicacion (RACIONAL r1,RACIONAL r2);

int division (RACIONAL r1,RACIONAL r2);

int mcd(int a,int b);


int main()
{
    racional r1,r2;
    r1=introducirRacional(r1);
    r1=simplificacion(r1);
    r2=introducirRacional(r2);
    r2=simplificacion(r2);
    //orden de los racionales
   // orden(r1,r2);
   //suma de los racionales
   // cout<<"El resulado de la suma es: "<<suma(r1, r2)<<endl;
   //equivalencia
  /*  if(equivalencia(r1,r2)){
        cout<<"Son equivalentes"<<endl;
    }else{
    cout<<"No son equivalentes"<<endl;
    }*/
    //simplificacion
    /*racional simplificado;
    simplificado = simplificacion(r1);
    cout << simplificado.numerador <<"/" <<simplificado.denominador;*/
    //resta de los racionales
      cout<<"El resulado de la resta es: "<<resta(r1,r2)<<endl;
    //multiplicacion
    // cout<<"El resulado de la multiplicacion es: "<<multiplicacion(r1,r2)<<endl;


    return 0;
}

int mcd(int a,int b){
    int temp;
    while(b != 0){
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;

}

racional introducirRacional(RACIONAL r){
    cout<<"Introduce el numerador: "<<endl;
    cin>>r.numerador;

    cout<<"Introduce el denominador: "<<endl;
    cin>>r.denominador;


    return r;

}

bool equivalencia(RACIONAL r1,RACIONAL r2){

    if((r1.numerador*r2.denominador)==(r1.denominador*r2.numerador)){

        return true;

    }else{

        return false;

    }

}

racional simplificacion(RACIONAL r){
    if((r.numerador>0)&&(r.denominador>0)){
        int Mcd=mcd(r.numerador,r.denominador);
        r.numerador=r.numerador/Mcd;
        r.denominador=r.denominador/Mcd;

    }
    else{
        r.numerador=r.numerador*(-1);
        r.denominador=r.denominador*(-1);

    }
    return r;
}


void orden(RACIONAL r1,RACIONAL r2){
    if((r1.numerador*r2.denominador)<(r1.denominador*r2.numerador)){
        cout<<"El primer racional es menor que el segundo racional"<<endl;

    }else{
        cout<<"El primer racional es mayor que el segundo racional"<<endl;

    }

}

int suma(RACIONAL r1, RACIONAL r2){
    int sum;
    sum=((r1.numerador*r2.denominador)+(r1.denominador*r2.numerador))/(r1.denominador*r2.denominador);
    return sum;

}

int resta(RACIONAL r1, RACIONAL r2){
    int res;
    res=((r1.numerador*r2.denominador)-(r1.denominador*r2.numerador))/(r1.denominador*r2.denominador);
    return res;

}

int multiplicacion(RACIONAL r1, RACIONAL r2){
    int mul;
    mul=(r1.numerador/r1.denominador)*(r2.denominador/r2.numerador);
    return mul;

}

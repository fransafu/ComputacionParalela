//Tarea 5 


// Integral de una función polinómica con openMP

#include <iostream>
#include <stdio.h>
#include <math.h>
#include "omp.h"



using namespace std;

int main() {

    //definiendo variables
    int n = 4;
    int i, nth;
    double integral=0;
    double max  = pow(2,64)-1; 

   
    int Grados[n];
    Grados[0]=10;
    Grados[1]=1;
    Grados[2]=2;
    Grados[3]=3;
    Grados[4]=4;


//Inicio de paralelizacion
     #pragma omp parallel
    nth = omp_get_num_threads();
    cout << "Hilos  maximos : " << nth << endl; //Numero de hilos que aguanta el procer

    cout<< "El Polinimio es : " << endl;
    cout << "P(x)= 4X^4 + 3X^3 + 2X^2 + X + 10 "<<endl;
    cout << endl;
    cout << "La integral de P(X) es : " << endl;

     #pragma omp for schedule(static,1)    
    
    for(i=0; i<=n; i++){
        cout<<1.0*Grados[i]/(i+1)<<"x^"<<i+1<<" ";
    }

    cout<<endl<<endl;
    cout<<" Evaluando entre 0 y "<<max<<" es: " << endl;


//calculo de integral 
     #pragma omp for schedule(static,1)   
    for(i=0; i<=n; i++){
        integral=integral + (1.0*Grados[i]/(i+1))*pow(max,i+1);
    }
    cout<<integral;
    return 0;
}
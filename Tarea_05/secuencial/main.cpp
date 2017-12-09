
//Tarea 5 


// Integral de una función polinómica de manera secuencial

#include <iostream>
#include <stdio.h>
#include <math.h>



using namespace std;

int main() {

    //definiendo variables
    int n = 4;
    int i;
    double integral=0;
    double max  = pow(2,64)-1; 

   
    int Grados[n];
    Grados[0]=10;
    Grados[1]=1;
    Grados[2]=2;
    Grados[3]=3;
    Grados[4]=4;
    
    cout<< "El Polinimio es : " << endl;
    cout << "P(x)= 4X^4 + 3X^3 + 2X^2 + X + 10 "<<endl;
    cout << endl;
    cout << "La integral de P(X) es : " << endl;
    for(i=0; i<=n; i++){
        cout<<1.0*Grados[i]/(i+1)<<"x^"<<i+1<<" ";
    }

    cout<<endl<<endl;
    cout<<" Evaluando entre 0 y "<<max<<" es: " << endl;
   
    for(i=0; i<=n; i++){
        integral=integral + (1.0*Grados[i]/(i+1))*pow(max,i+1);
    }
    cout<<integral;
    return 0;
}
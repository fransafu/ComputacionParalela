#include <iostream>
#include <math.h>
#include "mpi.h"

using namespace std;
long double f1(long double x)
{
    return 4.0*pow(x, 4) + 3.0*pow(x, 3) + 2.0*pow(x, 2) + x + 10.0;
}

/*
* Parametros ingresados:
*	1) Funcion a calcular
* 	2) Limite inferior de la integral
* 	3) Limite superior de la integral
* 	4) Numero de segmentación por area calculada (basicamente es la precision, entre mas divisiones mas precision)
*/
long double integral(long double(*f)(long double x), long double a, long double b, long long int n) {
    long double step = (b - a) / n;
    long double area = 0.0;
    for (int i = 0; i < n; i ++) {
        area += f(a + (i + 0.5) * step) * step;
    }
    return area;
}


int main() {

    MPI::Init(); // inicializa en mpi
    int rank = MPI::COMM_WORLD.Get_rank(); // se trae el rank en el que se esta ejecutando
    int size = MPI::COMM_WORLD.Get_size(); // el tamaño que trae desde terminal
    cout.precision(7);
    long double(*f2)(long double x);
    f2 = f1;
    long double intervalo = 0;
    long double bordeSuperior = (pow(2, 64));
    long double resultadoTotal;
    intervalo = bordeSuperior / size;
    MPI_Bcast(&intervalo, 1, MPI_LONG_DOUBLE, 0, MPI_COMM_WORLD);



    long double integralParcial = integral(f2, (intervalo*rank), ((intervalo*rank)+intervalo-1), 10000*10000);

    MPI_Reduce(&integralParcial, &resultadoTotal, 1, MPI_LONG_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0){
        cout<< "El resultado es :" << resultadoTotal<<endl;
    }

    MPI::Finalize(); // cierra el proceso MPI

}
#include <iostream>
#include <math.h>

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

int main()
{
    cout.precision(7);
    long double(*f2)(long double x);
    f2 = f1;
    cout << "Integral a calcular: 4*x^4 + 3*x^3 + 2*x^2 + x + 10" << endl;
    cout << integral(f2, 0, (pow(2, 64) - 1), 1000*1000*1000*2) << endl;
    return 0;
}

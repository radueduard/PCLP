#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

double integrala(double (*func)(double x), double a, double b, int n)
{
    double s = 0;
    double pas = (b - a) / n;
    for (int i = 0; i < n; i++)
    {
        s += (func(i * pas) + func((i + 1) * pas)) * pas / 2;
    }
    return s;
}

int main()
{
    printf("%lf\n%lf", integrala(sin, 0, M_PI, 500), integrala(cos, 0, M_PI, 500));
    return 0;
}
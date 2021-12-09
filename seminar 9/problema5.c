#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    double real;
    double imaginar;
} complex_nr;

typedef struct
{
    int *v;
    int cap;
    int n;
} vector;

void init_vector(vector *a, int n)
{
    a->cap = n;
    a->v = (int *)malloc(a->cap * sizeof(int));
}

void adauga_vector(vector *a, int nr)
{
    a->v[a->n] = nr;
    a->n++;
}

void scrie_vector(vector *a, char *nr)
{
    for (int i = 0; i < a->n - 1; i++)
    {
        printf("%d*(%s)^%d + ", a->v[i], nr, a->cap - i - 1);
    }
    printf("%d = ", a->v[a->cap - 1]);
}

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int combinari(int n, int m)
{
    return factorial(n) / (factorial(m) * factorial(n - m));
}

double string_to_double(char *numar)
{
    double nr = 0, p = 1;
    char intreg[50], fractionar[50];
    strcpy(intreg, strtok(numar, "."));
    strcpy(fractionar, strtok(NULL, "\0"));
    int var = 1;
    for (int i = strlen(intreg) - 1; i >= 0; i--)
    {
        if (intreg[i] == '-')
        {
            var = -1;
            p++;
        }
        else
        {
            nr += (intreg[i] - '0') * pow(10, p);
            p++;
        }
    }
    p = 0;
    for (int i = 0; i < strlen(fractionar); i++)
    {
        nr += pow(10, p) * (fractionar[i] - '0');
        p--;
    }
    nr *= var;
    return nr / 10;
}

complex_nr ridicare_la_putere(complex_nr a, int n)
{
    complex_nr rez;
    rez.real = 0;
    rez.imaginar = 0;
    for (int i = 0; i <= n; i += 2)
    {
        rez.real += pow(-1, i / 2) * combinari(n, i) * pow(a.real, n - i) * pow(a.imaginar, i);
    }
    for (int i = 1; i <= n; i += 2)
    {
        rez.imaginar += pow(-1, (i - 1) / 2) * combinari(n, i) * pow(a.real, n - i) * pow(a.imaginar, i);
    }
    return rez;
}

complex_nr calcul_polinom(complex_nr nr, vector a)
{
    complex_nr polinom;
    polinom.real = 0;
    polinom.imaginar = 0;
    for (int i = 0; i < a.cap; i++)
    {
        polinom.real += a.v[i] * ridicare_la_putere(nr, a.cap - i - 1).real;
        polinom.imaginar += a.v[i] * ridicare_la_putere(nr, a.cap - i - 1).imaginar;
    }
    return polinom;
}

int main()
{
    char numar_s[1000], numar_s_c[1000], re_nr[500], im_nr[500];
    int grad, nr;
    vector coeficienti;
    printf("Introdu numerul complex: ");
    scanf("%s", numar_s);
    strcpy(numar_s_c, numar_s);
    strcpy(re_nr, strtok(numar_s, "+"));
    strcpy(im_nr, strtok(NULL, "i"));
    complex_nr numar;
    printf("Introdu gradul polinomului: ");
    scanf("%d", &grad);
    init_vector(&coeficienti, grad + 1);
    printf("Introdu coeficientii polinomului: ");
    for (int i = 0; i < coeficienti.cap; i++)
    {
        scanf("%d", &nr);
        adauga_vector(&coeficienti, nr);
    }
    numar.real = string_to_double(re_nr);
    numar.imaginar = string_to_double(im_nr);

    scrie_vector(&coeficienti, numar_s_c);

    printf("%.2lf %.2lfi", calcul_polinom(numar, coeficienti).real, calcul_polinom(numar, coeficienti).imaginar);
    return 0;
}
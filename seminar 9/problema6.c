#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char cuv[30];
    int ap;
} cuvant;

typedef struct
{
    cuvant *v;
    int cap;
    int n;
} vector;

void init_vector(vector *a, int n)
{
    a->cap = n;
    a->v = (cuvant *)malloc(a->cap * sizeof(cuvant));
}

void adauga_vector(vector *a, char *cuv)
{
    int ok = 1;
    for (int i = 0; i < a->n; i++)
    {
        if (strcmp(cuv, a->v[i].cuv) == 0)
        {
            a->v[i].ap++;
            ok = 0;
        }
    }
    if (ok == 1)
    {
        a->v[a->n].ap = 0;
        a->n++;
        strcpy(a->v[a->n - 1].cuv, cuv);
        a->v[a->n - 1].ap++;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    char cuvant[30];
    vector cuvinte;
    cuvinte.n = 0;
    init_vector(&cuvinte, n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", cuvant);
        adauga_vector(&cuvinte, cuvant);
    }

    for (int i = 0; i < cuvinte.n; i++)
    {
        printf("%s: %d\n", cuvinte.v[i].cuv, cuvinte.v[i].ap);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

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
    if (a->n == a->cap)
    {
        a->cap++;
        a->v = (int *)realloc(a->v, a->cap * sizeof(int));
    }
    a->v[a->n] = nr;
    a->n++;
}

void scrie_vector(vector *a)
{
    for (int i = 0; i < a->n; i++)
    {
        printf("%d ", a->v[i]);
    }
    printf("\n");
}

int main()
{
    vector arr;
    arr.n = 0;
    int nr;
    scanf("%d", &nr);
    init_vector(&arr, nr);
    for (int i = 0; i <= 100; i++)
    {
        adauga_vector(&arr, i);
        scrie_vector(&arr);
    }
    return 0;
}

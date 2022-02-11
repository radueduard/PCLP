#include <stdio.h>

typedef struct
{
    char nume[20];
    double pret;
    double cantitate;
} Produs;

typedef struct
{
    char *id;
    int nr;
    Produs *prod;
} Magazin;

int cmpProduse(const void *a, const void *b)
{
    Produs *x = (Produs *)a;
    Produs *y = (Produs *)b;
    if (strcmp(x->nume, y->nume) > 0)
        return 1;
    else if (strcmp(x->nume, y->nume) == 0)
        if (x->pret < y->pret)
            return 1;
    return 0;
}

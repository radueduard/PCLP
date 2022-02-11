#include "Produs.h"

void creare_fisier(char *nume_fisier)
{
    FILE *file = fopen(nume_fisier, "wb");
    for (int i = 0; i < 100; i++)
    {
        Produs prod;
        int X = rand();
        sprintf(prod.nume_produs, "Produs%d", X);
        prod.cantitate = X % 100;
        prod.pret_produs = X <= 100 ? X : X % 100;
        fwrite(&prod, sizeof(Produs), 1, file);
    }
    fclose(file);
}

void afisare_ecran(char *nume_fisier)
{
    FILE *file = fopen(nume_fisier, "rb");
    Produs prod;
    for (int i = 0; i < 100; i++)
    {
        fread(&prod, sizeof(Produs), 1, file);
        fwrite(&prod, sizeof(Produs), 1, stdout);
        printf("\n");
    }
    fclose(file);
}

void quick_sort(Produs *produse, int lowIndex, int highIndex)
{
    int pivot = highIndex;
    int lp = lowIndex;
    int rp = highIndex;
    while (lp != rp)
    {
        while (strcmp(produse[lp].nume_produs, produse[pivot].nume_produs) <= 0 && lp < rp)
        {
            lp++;
        }
        while (strcmp(produse[rp].nume_produs, produse[pivot].nume_produs) >= 0 && lp < rp)
        {
            rp--;
        }
        Produs swap;
        swap = produse[lp];
        produse[lp] = produse[rp];
        produse[rp] = swap;
    }
    Produs swap;
    swap = produse[lp];
    produse[lp] = produse[pivot];
    produse[pivot] = swap;

    quick_sort(produse, lowIndex, lp - 1);
    quick_sort(produse, lp + 1, highIndex);
}

int main(int argc, char *argv[])
{
    // creare_fisier("file.bin");
    afisare_ecran("file.bin");
    return 0;
}
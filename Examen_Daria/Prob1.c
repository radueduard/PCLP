#include <stdio.h>

int contine_cifra(int a, int c)
{
    while (a != 0)
    {
        if (a % 10 == c)
            return 1;
        a /= 10;
    }
    return 0;
}

void extrage_nr(int a[100][100], int n, int v[100], int c, int *ct)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (contine_cifra(a[i][j], c))
            {
                v[*ct] = a[i][j];
                *ct = *ct + 1;
            }
        }
    }
}

int main()
{
    int n;
    int mat[100][100];
    int v[100];
    int ct = 0;
    int c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    scanf("%d", &c);
    extrage_nr(mat, n, v, c, &ct);
    for (int i = 0; i < ct; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
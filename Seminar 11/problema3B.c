#include <stdio.h>
#include <string.h>

void make_lower_case(char *text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] += 32;
        }
    }
}

int main(int argc, char *argv[])
{
    int nr_param = argc - 3;

    char fisier[20];
    char cautat[40];
    strcpy(fisier, argv[argc - 2]);
    strcpy(cautat, argv[argc - 1]);

    char line[50];
    char copie_linie[50], copie_cautat[40];
    int nr_line = 1;
    int index = 0, insensitive = 0, nr_total = 0;

    FILE *in = fopen(fisier, "r");
    printf("%d\n", nr_param);
    for (int i = 1; i <= nr_param; i++)
    {
        if (argv[i][0] == 'i')
        {
            insensitive = 1;
        }
        if (argv[i][0] == 'n')
        {
            index = 1;
        }
        if (argv[i][0] == 'c')
        {
            nr_total = 1;
        }
    }

    int place = 1;
    while (fgets(line, 50, in) != NULL)
    {
        strcpy(copie_linie, line);
        make_lower_case(copie_linie);
        strcpy(copie_cautat, cautat);
        make_lower_case(copie_cautat);
        if (index == 1)
        {
            printf("[%d] ", place);
        }
        if (insensitive == 1)
        {
            if (strstr(copie_linie, copie_cautat) != NULL)
            {
                printf("%s", line);
                place++;
            }
        }
        else
        {
            if (strstr(line, cautat) != NULL)
            {
                printf("%s", line);
                place++;
            }
        }
    }

    if (nr_total == 1)
    {
        printf("Numar total de linii: %d", place - 1);
    }

    return 0;
}
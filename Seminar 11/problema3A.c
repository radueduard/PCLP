#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char fisier[20];
    char cautat[40];
    strcpy(fisier, argv[1]);
    strcpy(cautat, argv[2]);

    char line[50];

    FILE *in = fopen(fisier, "r");

    while (fgets(line, 50, in) != NULL)
    {
        if (strstr(line, cautat) != NULL)
        {
            printf("%s", line);
        }
    }

    return 0;
}
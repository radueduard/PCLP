#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char in[20], out[20], tab[30];
    char decod[50];
    strcpy(in, argv[1]);
    strcpy(out, argv[2]);
    strcpy(tab, argv[3]);

    FILE *f_in = fopen(in, "r");
    FILE *f_out = fopen(out, "w");
    FILE *f_tab = fopen(tab, "r");

    char line[5];
    while (fgets(line, 5, f_tab) != NULL)
    {
        decod[line[0] - 'a'] = line[2];
        decod[line[0] - 'A' + 25] = line[2] - 25;
    }
    char c;
    while ((c = fgetc(f_in)) != EOF)
    {
        if (c >= 'a' && c <= 'o')
        {
            fputc(decod[c - 'a'], f_out);
            printf("%c", decod[c - 'a']);
        }
        else if (c >= 'A' && c <= 'O')
        {
            fputc(decod[c - 'A'] - 32, f_out);
            printf("%c", decod[c - 'A'] - 32);
        }
        else
        {
            fputc(c, f_out);
            printf("%c", c);
        }
    }
    fclose(f_in);
    fclose(f_out);
    fclose(f_tab);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <time.h>

char *atribuire_timp(struct tm t, char *time)
{
    char transformare[3];
    transformare[2] = '\0';
    transformare[1] = '0' + t.tm_hour % 10;
    t.tm_hour /= 10;
    transformare[0] = '0' + t.tm_hour % 10;
    strcpy(time, transformare);
    strcat(time, ":");
    transformare[1] = '0' + t.tm_min % 10;
    t.tm_min /= 10;
    transformare[0] = '0' + t.tm_min % 10;
    strcat(time, transformare);
    strcat(time, ":");
    transformare[1] = '0' + t.tm_sec % 10;
    t.tm_sec /= 10;
    transformare[0] = '0' + t.tm_sec % 10;
    strcat(time, transformare);
}

int main()
{
    char timp[9];
    const time_t secunde = time(NULL);
    struct tm *t = localtime(&secunde);
    atribuire_timp(*t, timp);
    printf("%s\n", timp);
    return 0;
}
#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
    time_t curent_time;
    curent_time = time(NULL);
    char timp[20];
    strcpy(timp, ctime(&curent_time));
    printf("%s", timp);
    return 0;
}
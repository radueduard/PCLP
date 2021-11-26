#include <stdio.h>
#include <string.h>

char *substr(char *src, int n, char *dest){
    for(int i = 0; i <= n; i++){
        if(i!=n){
            dest[i] = src[i];
        }
        else{
            dest[i] = '\0';
        }
    }
}

int main(){
    int nr, poz;
    char sir[100];
    char dest[100];

    scanf("%s", sir);
    printf("%s", sir);
    scanf("%d%d", &nr, &poz);
    substr(sir + nr, poz, dest);
    printf("%s", dest);
}
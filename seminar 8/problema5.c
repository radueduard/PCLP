#include <stdio.h>
#include <string.h>



int main(){
    char string[1001], cp[11];
    int n;
    scanf("%d", &n);
    fgets(string, 1000, stdin);
    fgets(string, 1000, stdin);
    strcpy(cp, strtok(string, " "));
    printf("%s-", cp);
    n--;
    char a, b, c, d;
    a = cp[strlen(cp)-2];
    if (a<'a'){
        a+=32;
    }
    b = cp[strlen(cp)-1];
    if (b<'a'){
        b+=32;
    }
    while(n!=0){
        strcpy(cp, strtok(NULL, " \n"));
        c = cp[0];
        if (c<'a'){
            c+=32;
        }
        d = cp[1];
        if (d<'a'){
            d+=32;
        }
        if(a==c && b==d){
            if (n!=1)
                printf("%s-", cp);
            else
                printf("%s", cp);
            a = cp[strlen(cp)-2];
            if (a<'a'){
                a+=32;
            }
            b = cp[strlen(cp)-1];
            if (b<'a'){
                b+=32;
            }
        }
        n--;
    }
    return 0;
}
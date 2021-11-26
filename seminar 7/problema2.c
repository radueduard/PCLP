#include <stdio.h>

void count(int n, int *v, int *zero, int *poz, int *neg){
    *zero = 0;
    *poz = 0;
    *neg = 0;
    for(int i = 0; i < n; i++){
        if(*(v + i)>0){
            *poz = *poz + 1;
        }
        else if(v[i]<0){
            *neg = *neg + 1;
        }
        else{
            *zero = *zero + 1;
        }
    }
}

int main(){

    int n, zero, poz, neg, v[100];

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    count(n, v, &zero, &poz, &neg);

    printf("nule: %d\npozitive: %d\nnegative: %d", zero, poz, neg);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(){

    int *v;
    int cap=5;
    v = (int *)malloc(cap*sizeof(int));
    int n=0;
    while(1){
        if(cap==n){
            cap++;
            v = (int *)realloc(v, cap*sizeof(int));
        }
        scanf("%d", &v[n]);
        if(v[n]==0){
            break;
        }
        n++;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    free(v);
    return 0;
}
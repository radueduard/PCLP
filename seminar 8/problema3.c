#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    char cuvant[11];
    char *cuvinte[11];
    int *ct;
    scanf("%s", cuvant);
    int x = strlen(cuvant)+1;
    cuvinte[0] = (char *)malloc(x*sizeof(char));
    ct = (int *)malloc(sizeof(int));
    strcpy(cuvinte[0], cuvant);
    int k = 0;
    ct[k]=1;
    for(int i = 1; i < n; i++){
        int ok = 1;
        scanf("%s", cuvant);
        for(int j = 0; j <= k; j++){
            if(strcmp(cuvant, cuvinte[j])==0){
                ok=0;
                ct[j]++;
            }
        }
        if(ok==1){
            k++;
            x = strlen(cuvant)+1;
            cuvinte[k] = (char *)malloc(x*sizeof(char));
            strcpy(cuvinte[k], cuvant);
            ct = (int *)realloc(ct, (k+1)*sizeof(int));
            ct[k]=1;
        }
    }

    for(int i = 0; i <= k; i++){
        printf("%s: %d\n", cuvinte[i], ct[i]);
    }

    for(int i = 0; i<=k; i++)
        free(cuvinte[k]);
    free(ct);

    return 0;
}
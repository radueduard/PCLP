#include <stdio.h>
#include <string.h>

int main(){
    int N;
    char cuvant[100];
    char cuvinte1[100][100];
    char cuvinte2[100][100];
    double grad[100];
    scanf("%d", &N);
    scanf("%s", cuvant);
    for(int i =0; i< N; i++){
        scanf("%s", cuvinte1[i]);
        scanf("%s", cuvinte2[i]);
        strcpy(cuvant, cuvinte1[i]);
        strcpy(cuvinte1[i], cuvinte2[i]);
        strcpy(cuvinte2[i], cuvant);
    }
}
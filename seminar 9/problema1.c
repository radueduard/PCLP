#include <stdio.h>

typedef struct{
    float x, y;
}punct;

int main(){
    punct P;
    printf("Introduceti x: ");
    scanf("%f", &P.x);
    printf("Introduceti y: ");
    scanf("%f", &P.y);
    printf("(%.2f, %.2f)\n", P.x, P.y);
    return 0;
}
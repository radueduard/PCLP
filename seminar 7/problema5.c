#include <stdio.h>
#include <math.h>
#include <limits.h>

void panta(int x1, int y1, int x2, int y2, float *m, float *n){
    if(x1!=x2){
        *m = (float)(y1-y2)/(x1-x2);
    }
    else{
        *m = INT_MAX;
    }
    *n = (x1*y2+y1*x2 - 2*(y2-y1)/(x2-x1)*x1*x2)/(x1+x2);
}

int main(){
    int x1,x2,y1,y2,x3,y3;
    float m, n;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    panta(x1,y1,x2,y2,&m, &n);
    if(fabs(y3 - m*x3 - n)<= 0.001){
        printf("DA");
    }
    else{
        printf("NU");
    }
    return 0;
}
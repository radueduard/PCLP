#include <stdio.h>


struct multime
{
    unsigned int n;
    unsigned char *a;
};

void init(struct multime *m){
    m->n = 1;
    m->a = (unsigned char *)malloc(m->n * sizeof(unsigned char));
}               
void add(struct multime *m, int x){
    int vect = x / 8 + 1;
    if(vect > m->n)
        m->n = vect;
    m->a = (unsigned char *)realloc(m->a, m->n * sizeof(unsigned char));
    
    m->a[m->n] = m->a[m->n] | (1<<x);    
}
void del(struct multime *m, int x){
    m->a = m->a - (1 << x);
}     
int contains(struct multime *m, int x){
    struct multime cp;
    cp = *m;
    add(&cp, x);
    if(cp.a == m->a){
        return 1;
    }
    return 0;
}
void print(struct multime *m){
    for (int i = 0; i < 8; i++){
        if(contains(m, i)){
            printf("%d ", i);
        }
    }
}

int main()
{
    struct multime m;
    
    int n;
    scanf("%d", &n);
    char instructiune;
    int x;
    for (int i = 0; i < n; i++){
        scanf("%c", &instructiune);
        if(instructiune=='A'){
            scanf("%d", &x);
        }
        else if (instructiune == 'D'){

        }
        else if (instructiune == 'C'){

        }
        else if (instructiune == 'P'){

        }
        else{
            printf("EROARE!");
        }
    }
    return 0;
}
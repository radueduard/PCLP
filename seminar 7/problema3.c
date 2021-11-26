#include <stdio.h>
#include <string.h>

char *strdel(char *p, int n){
    strcpy(p, p+n);
}

char *strins(char *p, char *s){

}

int main(){
    char sir[3000];
    char inlocuit[20];
    char inlocuitor[20];
    char copie[3000];
    
    fgets(sir, 3000, stdin);
   
    scanf("%s %s", inlocuit, inlocuitor);
    
        strcpy(copie, strdel(strstr(sir, inlocuit), strlen(inlocuit)));
        
        strdel(strstr(sir, copie), strlen(copie));
        
        strcat(sir, inlocuitor);
        
        strcat(sir, copie);
    
    

    printf("%s", sir);

    return 0;
}
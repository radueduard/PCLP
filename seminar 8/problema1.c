#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_replace(char *s, char *s1, char *s2){
    char *v;
    int ct=0;
    v=(char *)malloc((strlen(s)-strlen(s1)+strlen(s2)+1)*sizeof(char)); 
    for(int i=0; i<strstr(s, s1)-s; i++){
        v[ct++]=s[i];
    }
    for(int i=0; i<strlen(s2); i++){
        v[ct++]=s2[i];
    }
    for(int i=strstr(s, s1)-s+strlen(s1); i<strlen(s); i++){
        v[ct++]=s[i];
    }
    v[ct]='\0';
    strcpy(s,v);
    free(v);
}

int main(){
    char s[100], s1[100], s2[100];
    scanf("%s%s", s1, s2);
    fgets(s, 100, stdin);
    fgets(s, 100, stdin);
    while(strstr(s,s1)){
        my_replace(s, s1, s2);
    }
    printf("%s", s);
    return 0;
}
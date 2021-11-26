#include <string.h>
#include <stdio.h>

char *next (char *from, char *word){
    int i = 0;
    while((from[i+1]>='A')&&(from[i+1]<'a')){
        i++;
        if(from[i]=='\0'){
            break;
        }
    }
    
    if((from[i+1]<'A')&&(from[i+1]>='a')){
        i++;
        int j = 0;
        while((from[i+1]<'A')&&(from[i+1]>='a')&&(from[i]!='\0')){
            word[j]=from[i];
            i++;
            j++;
        }
        word[j]='\0';
    }
}
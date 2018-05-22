
#include <stdio.h>
#include <stdlib.h>

int main(void) {


    char string[30],caracter;
    int i=0, step;
    printf("Cadena original: ");
    gets(string);
    printf("Desplazamiento: ");
    scanf("%d", &step);

    while(string[i]){
        string[i]=toupper(string[i]);
        i++;
    }

    for(int i=0; string[i]!='\0'; i++){
        if(string[i]>='A' && string[i]<='Z' ){
            if(string[i]+step>'Z') string[i]+=(step-26);
            else string[i]+=step;
        } 
    }
    
    printf("Cadena cifrada: ");
    puts(string);
}

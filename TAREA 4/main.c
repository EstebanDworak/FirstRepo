#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


#define SIGN_PLUS 43
#define SIGN_MINUS 45
#define SIGN_MULTIPLY 42
#define SIGN_DIVIDE 47

#define SIGN_PAI 40
#define SIGN_PAD 41


bool hasHigherPrecedence(char a, char b){

    if(b==SIGN_PLUS){
        if(a==SIGN_MULTIPLY)return 1;
        else if(a==SIGN_DIVIDE) return 1;
    }
    if(b==SIGN_MINUS){
        if(a==SIGN_MULTIPLY)return 1;
        else if(a==SIGN_DIVIDE) return 1;
    }
    return 0;
}

char *appendchar(char *szString, size_t strsize, char c)
{
    size_t len = strlen(szString);
    if((len+1) < strsize)
    {
        szString[len++] = c;
        szString[len] = '\0';
        return szString;
    }
    return NULL;
}

char* InfixToPosfix(char *exp){
    Stack fila = createStack();
    Stack pila = createStack();

    for(int i=0;exp[i]!=NULL;i++){

        //OPERANDOS
        if((exp[i]>=48 &&exp[i]<=57)) push(fila, exp[i]);

        //PARENTESIS IZQUIERDO
        if(exp[i]==SIGN_PAI) push(pila, exp[i]);

        //PARENTESIS DERECHO
        if(exp[i]==SIGN_PAD){
            while(isEmpty(pila)==0 && top(pila)!=SIGN_PAI) push(fila,pop(pila));
            pop(pila);
        }

        //OPERATORS
        if(exp[i]==SIGN_PLUS || exp[i]==SIGN_MINUS || exp[i]==SIGN_DIVIDE || exp[i]==SIGN_MULTIPLY){

            while(isEmpty(pila)==0 && top(pila)!=SIGN_PAI){
               if(hasHigherPrecedence(top(pila),exp[i])==0) push(fila,pop(pila));
            }
            push(pila,exp[i]);
        }

    }

    while(isEmpty(pila)==0) push(fila,pop(pila));


    char *str;
    int size = getSize(fila)*2;
    str = (char *)malloc(sizeof(char)*size);

    for(int j=0;j<size;j+=2){
        *(str+size-j-2) = pop(fila);
        *(str+size-j-2+1) = ' ';
    }
    *(str+size) = '\0';

    return str;

}


bool balancedBrackets(char *exp){

    Stack pila = createStack();
    for(int i=0;exp[i]!=NULL;i++){

        if(exp[i]=='(' || exp[i]=='[') push(pila,exp[i]);

        if(exp[i]==')' || exp[i]==']'){
            if(isEmpty(pila)==1) return false;
        }

        if(exp[i]==')' && pop(pila)!='(') return false;

        if(exp[i]==']' && pop(pila)!='[') return false;
    }

    if(isEmpty(pila)==1) return true;

    else return false;





}

int main()
{


    char *name[100];
    printf("Ingrese expresion infix:\n");
    scanf ("%[^\n]%*c", name);


    printf("\n\nEl resultado posfix es:\n");
    printf("%s",InfixToPosfix(name));


    printf("\n\nIngrese expresion de parenthesis:\n");
    scanf ("%[^\n]%*c", name);

    if(balancedBrackets(name)==1){
        printf("\nLa expresion es correcta");
    }else{
        printf("\nLa expression es incorrecta");
    }





}

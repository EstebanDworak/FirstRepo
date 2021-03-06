#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//Represent a node
struct strNode
{
    Type data;  //The information store in the node
    struct strNode *prior;  //The address of the previous node (the one in top)
};

typedef struct strNode Node;

//Represent a Stack
struct strStack
{
    Node *top; //A pointer to the top NODE
    int size; //Size of the stack
};

//Creating a new stack
Stack createStack()
{
    Stack new = (Stack)malloc(sizeof(struct strStack));
    if(new == NULL)
        return NULL;
    new -> top = NULL;  //Initializing in NULL = Our stack is empty
    new -> size = 0;
    return new;
}

void destroyStack(Stack who)
{
    Type temp;
    while(isEmpty(who) != true)
        temp=pop(who);
    free(who);
}

//Inserting a new node into the stack
bool push(Stack who, Type data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode==NULL)
        return false;
    newNode -> prior = NULL; //Address of the previous node is NULL because newNode is the top
    newNode -> data = (Type)malloc(sizeof(Type)); //Allocating memory for the data type
    newNode -> data = data;

    newNode->prior = who->top;

    who -> size+=1; //Increase the size of the stack
    who -> top=newNode; //now the top of the stack is the new node we created

    return true;
}

//Taking away
Type pop(Stack who)
{
    if(who->top==NULL) //If the top is NULL = stack is empty
        return NULL;

    Node *tempNode= who->top;
    Type temp = who->top->data;

    who->size--;
    who->top=who->top->prior;
    free(tempNode);

    return temp; //we send the data store at the top
}

Type top(Stack who)
{
    if(who->top==NULL) //If top is NULL = Stack is empty
        return NULL;
    return who->top->data; //Else, return the data at the top
}

bool isEmpty(Stack who)
{
    if(who->size==0)
        return true;
    else
        return false;
}



long getSize(Stack who){
    return who->size;
}

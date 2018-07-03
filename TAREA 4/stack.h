#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef void *Type;
typedef struct strStack *Stack;
typedef enum {false, true} bool;

Stack createStack();
void destroyStack(Stack);
bool push(Stack, Type);
Type pop(Stack);
Type top(Stack);
bool isEmpty(Stack);
long getSize(Stack);

#endif // STACK_H_INCLUDED

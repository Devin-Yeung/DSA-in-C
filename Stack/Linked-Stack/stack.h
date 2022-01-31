#ifndef _STACK_H_
#define _STACK_H_



typedef struct Elem {
    int val;
    struct Elem * next;
} Elem;



typedef struct Stack {
    Elem * top;
    int size;
} Stack;



void initStack (Stack * S);
void push(int val, Stack * S);
bool pop(int * val, Stack * S);
int peek(const Stack * S);
void destoryStack (Stack * S);



#endif
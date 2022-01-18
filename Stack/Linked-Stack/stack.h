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



void InitStack (Stack * S);
void push(int val, Stack * S);
bool pop(int * val, Stack * S);
void destoryStack (Stack * S);



#endif
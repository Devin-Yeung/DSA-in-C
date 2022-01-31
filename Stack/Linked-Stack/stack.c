#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"



void initStack (Stack * S){
    S -> top = NULL;
    S -> size = 0;
    return;
}



void push(int val, Stack * S){
    // set up elem
    Elem * pnew = (Elem*)malloc(sizeof(Elem));
    pnew -> val = val;

    // set the next of new element
    pnew -> next = S -> top;
    // reset the top
    S -> top = pnew;
    S -> size += 1;
    return;
}


bool pop(int * val, Stack * S){
    // check if stack if empty
    if(S -> size == 0){
        return 0;
    }
    // copy the top of stack
    *val = S -> top -> val;
    // store the original top
    Elem * ptmp = S -> top;
    // reset the top of stack
    S -> top = S -> top -> next;
    free(ptmp);
    S -> size -= 1;
    return 1;
}



int peek (const Stack * S){
    return S -> top -> val;
}



void destoryStack (Stack * S){
    int tmp;
    while(pop(&tmp,S) != 0);
    return;
}



// print out the stack from the top
void printStack(Stack * S){
    Elem * pscan = S -> top;
    printf("TOP - ");
    while(pscan != NULL){
        printf("%d - ",pscan -> val);
        pscan = pscan -> next;
    }
    printf("BOTTOM\n");
    return;
}



int main(void){
    Stack S;
    int tmp;
    InitStack(&S);
    printf("@@@@@ TEST START @@@@@\n\n");

    printf("@@@@@ Push Test @@@@@\n");
    push(1,&S);
    printStack(&S);
    push(3,&S);
    push(5,&S);
    printStack(&S);
    puts("");

    printf("@@@@@ Peek Test @@@@@\n");
    printf("%d\n",peek(&S));
    puts("");

    printf("@@@@@ Pop Test @@@@@\n");
    pop(&tmp,&S);
    printStack(&S);
    puts("");
    
    printf("@@@@@ Destroy Stack Test @@@@@\n");
    destoryStack(&S);
    if(pop(&tmp,&S) == 0){
        fprintf(stderr,"Nothing to pop\n");
        fflush(stderr);
    }
    printStack(&S);
    puts("");
    return 0;
}
#ifndef _ARRAY_H_
#define _ARRAY_H_



typedef int Data;

typedef struct Array{
    Data * data;
    int size; // give the current size of array
    int capacity; //give the total capacity of array
} Array;



void initArray (Array * arr, int capacity);
bool resize (Array * arr, int capacity);
void addLast (Array * arr, Data data);
void removeLast (Array * arr);
void printArray (Array * arr);
void destoryArray (Array * arr);



#endif
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
void checkUsage (Array * arr);
static void shift (Array * arr, int index, int num);
void insert (Array * arr, int index, Data data);
void swap (Array * arr, int a, int b);
void addFirst (Array * arr, Data data);
void addLast (Array * arr, Data data);
void removeLast (Array * arr);
void printArray (Array * arr);
void destoryArray (Array * arr);



#endif
#ifndef _ARRAY_H_
#define _ARRAY_H_



typedef int Data;

typedef struct Array{
    Data * data;
    int size; // give the current size of array
    int capacity; //give the total capacity of array
} Array;



void initArray (Array * arr, int capacity);
Data get (const Array * arr, int index);
int size (const Array * arr);
bool resize (Array * arr, int capacity);
void checkUsage (Array * arr);
static void shift (Array * arr, int index, int num);
void insert (Array * arr, int index, Data data);
void swap (Array * arr, int a, int b);
void addFirst (Array * arr, Data data);
void addLast (Array * arr, Data data);
Data removeLast (Array * arr);
void toArray (Array * arr, const Data * data, int size);
void printArray (Array * arr);
void destoryArray (Array * arr);



#endif
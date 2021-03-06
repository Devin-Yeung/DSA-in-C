#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"



void initArray (Array * arr, int capacity){
    arr -> data = (Data *)malloc(capacity * sizeof(Data));
    arr -> size = 0;
    arr -> capacity = capacity;
}



Data get (const Array * arr, int index){
    if(index < 0 || index >= size(arr)){
        fprintf(stderr,"get: index out of range.\n");
    }
    return(arr -> data[index]);
}



int size (const Array * arr){
    return arr -> size;
}



// if success return 1, else 0;
bool resize (Array * arr, int capacity){
    puts("resize triggered!");

    Data * old = arr -> data;
    arr -> data = (Data *)malloc(capacity * sizeof(Data));

    // check if malloc successfully
    if(arr -> data == NULL){
        fprintf(stderr,"resize: fail to malloc memory\n");
        fflush(stderr);
        return 0;
    }

    // update capacity
    arr -> capacity = capacity;
    
    // copy old array to new array
    for(int i = 0; i < arr -> size; i++){
        arr -> data[i] = old[i];
    }

    free(old);
    return 1;
}



void checkUsage (Array * arr){
    float usageRatio = 1.0 * arr -> size / arr -> capacity;
    if(usageRatio <= 0.25 && arr -> capacity >= 16){
        resize(arr, 0.5 * arr -> capacity);
    }
}



// shift the array from the given index
static void shift (Array * arr, int index, int num){
    if(num <= 0){
        fprintf(stderr,"shift: invalid number (left shifting is not supported)\n");
        return;
    }

    // check capacity
    if(arr -> size + num >= arr -> capacity){
        // resize 2 * capacity as default, if it can not be allocated, resize (capacity + 1)
        resize(arr, 2 * arr -> capacity) ? : resize(arr, arr -> capacity + 1);
    }

    for(int i = arr -> size - 1; index <= i; i--){
        // move the elem
        arr -> data[i + 1] = arr -> data[i];
    }
}



void insert (Array * arr, int index, Data data){
    shift(arr, index, 1);
    arr -> data[index] = data;
    arr -> size += 1;
}



void swap (Array * arr, int a, int b){
    Data tmp;
    tmp = arr -> data[a];
    arr -> data[a] = arr -> data[b];
    arr -> data[b] = tmp;
}



void addFirst (Array * arr, Data data){
    shift(arr,0,1);
    arr -> data[0] = data;
    arr -> size += 1;
}



void addLast (Array * arr, Data data){
    if(arr -> size == arr -> capacity){
        // resize 2 * capacity as default, if it can not be allocated, resize (capacity + 1)
        resize(arr, 2 * arr -> capacity) ? : resize(arr, arr -> capacity + 1);
    }
    arr -> data[arr -> size] = data;
    arr -> size += 1;
}



Data removeLast (Array * arr){
    Data data = get(arr,size(arr) - 1);
    arr -> size -= 1;
    checkUsage(arr);
    return data;
}



void toArray (Array * arr, const Data * data, int size){
    for(int i = 0; i < size; i++){
        addLast(arr,data[i]);
    }
}



void printArray (Array * arr){
    for(int i = 0; i < arr -> size; i++){
        // modify here according to your data types
        printf("%d -> ",arr -> data[i]);
    }
    puts("END");
}



void destoryArray (Array * arr){
    free(arr -> data);
    arr -> size = 0;
    arr -> capacity = 0;
}



int main(void){
    Array arr;
    initArray(&arr,8);
    for(int i = 0; i < 100; i++){
        addLast(&arr,i);
    }
    for(int i = 0; i < 90; i++){
        removeLast(&arr);
    }
    addFirst(&arr,64);
    insert(&arr,0,-64);
    printArray(&arr);
    printf("size:%d\n",arr.size);
    printf("capacity: %d\n",arr.capacity);
    printf("Usage: %f",1.0 * arr.size / arr.capacity);
    destoryArray(&arr);
    initArray(&arr,8);
    int dataArray[] = {1,2,3,4,5,6,7,8,9};
    toArray(&arr,dataArray,9);
    printArray(&arr);
    return 0;
}
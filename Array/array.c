#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"



void initArray (Array * arr, int capacity){
    arr -> data = (Data *)malloc(capacity * sizeof(Data));
    arr -> size = 0;
    arr -> capacity = capacity;
}



// if success return 1, else 0;
bool resize (Array * arr, int capacity){
    puts("resize triggered!");

    Data * old = arr -> data;
    arr -> data = (Data *)malloc(capacity * sizeof(Data));

    // check if malloc successfully
    if(arr -> data == NULL){
        fprintf(stderr,"resize: fail to malloc memory");
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



static void shift (Array * arr, int num){
    if(num <= 0){
        fprintf(stderr,"shift: invalid number (left shifting is not supported)");
        return;
    }

    // check capacity
    if(arr -> size + num >= arr -> capacity){
        // resize 2 * capacity as default, if it can not be allocated, resize (capacity + 1)
        resize(arr, 2 * arr -> capacity) ? : resize(arr, arr -> capacity + 1);
    }

    for(int i = arr -> size - 1; 0 <= i; i--){
        // move the elem
        arr -> data[i + 1] = arr -> data[i];
    }
}



void addFirst (Array * arr, Data data){
    shift(arr,1);
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



void removeLast (Array * arr){
    arr -> size -= 1;
    checkUsage(arr);
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
    printArray(&arr);
    printf("size:%d\n",arr.size);
    printf("capacity: %d\n",arr.capacity);
    printf("Usage: %f",1.0 * arr.size / arr.capacity);
    destoryArray(&arr);
    return 0;
}
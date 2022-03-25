#include <stdlib.h>
#include <string.h>
#include "bubble.h"

void swap(void *a, void *b, unsigned elementSize){
    void *aux = malloc(elementSize);
    memcpy(aux, a, elementSize);
    memcpy(a, b, elementSize);
    memcpy(b, aux, elementSize);
    free(aux);
}

void bubbleSort(void *array, unsigned long size, unsigned elementSize, int (*cmp)(const void *a, const void *b)){
    
    int cont;
    
    while(1){

        cont = 0;

        for(unsigned long i = 1; i < size; i++){
            if(cmp(array + (i - 1) * elementSize, array + i * elementSize) > 0){
                swap(array + (i - 1) * elementSize, array + i * elementSize, elementSize);
                cont = 1;
            }   
        }

        if(!cont)
            break;
    }

}
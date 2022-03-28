#include <stdlib.h>
#include <string.h>
#include "insertion.h"

void swap(void *a, void *b, unsigned elementSize){
    void *aux = malloc(elementSize);
    memcpy(aux, a, elementSize);
    memcpy(a, b, elementSize);
    memcpy(b, aux, elementSize);
    free(aux);
}

void insertionSort(void *array, unsigned long size, unsigned elementSize, int (*cmp)(const void *a, const void *b)){
    
    int j;
    
    for(unsigned long i = 1; i < size; i++){
        j = i - 1;

        while(j >= 0 && cmp((array + (j + 1) * elementSize), (array + j * elementSize)) <= 0){
            swap((array + (j + 1) * elementSize), (array + j * elementSize), elementSize);
            j--;
        }
    }

}
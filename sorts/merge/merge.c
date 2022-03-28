#include <stdlib.h>
#include <string.h>
#include "merge.h"

void merge(void *array, unsigned beg, unsigned mid, unsigned end, unsigned elementSize, int (*cmp)(const void *a, const void *b)){

    int n1 = mid - beg + 1;
    int n2 = end - mid;

    void *aLeft = malloc(elementSize * n1);
    void *aRight = malloc(elementSize * n2);

    for(int i = 0; i < n1; i++)
        memcpy(aLeft + i * elementSize, array + (beg + i) * elementSize, elementSize);
    for(int i = 0; i < n2; i++)
        memcpy(aRight + i * elementSize, array + (mid + 1 + i) * elementSize, elementSize);

    int i, j, k;
    i = j = 0;
    k = beg;

    while(i < n1 && j < n2){
        if(cmp(aLeft + i * elementSize, aRight + j * elementSize) <= 0){
            memcpy(array + k * elementSize, aLeft + i * elementSize, elementSize);
            i++;
        }else{
            memcpy(array + k * elementSize, aRight + j * elementSize, elementSize);
            j++;
        }
        k++;
    }

    while(i < n1){
        memcpy(array + k * elementSize, aLeft + i * elementSize, elementSize);
        i++;
        k++;
    }

    while(j < n2){
        memcpy(array + k * elementSize, aRight + j * elementSize, elementSize);
        j++;
        k++;
    }

    free(aLeft);
    free(aRight);

}

void mergeSortPrivate(void *array, unsigned beg, unsigned end, unsigned elementSize, int (*cmp)(const void *a, const void *b)){
    if(beg < end){
        unsigned mid = (beg + end) / 2;
        mergeSortPrivate(array, beg, mid, elementSize, cmp);
        mergeSortPrivate(array, (mid + 1), end, elementSize, cmp);
        merge(array, beg, mid, end, elementSize, cmp);
    }
}

void mergeSort(void *array, unsigned long size, unsigned elementSize, int (*cmp)(const void *a, const void *b)){
    mergeSortPrivate(array, 0, (size - 1), elementSize, cmp);
}
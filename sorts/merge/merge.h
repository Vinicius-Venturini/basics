#ifndef MERGE_H
#define MERGE_H

void mergeSort(void *array, unsigned long size, unsigned elementSize, int (*cmp)(const void *a, const void *b));

#endif
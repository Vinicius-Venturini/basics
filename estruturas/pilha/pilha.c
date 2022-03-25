#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int resize(stack *s, int max){
    item *temp = (item*)malloc(sizeof(item)*max);
    if(temp == NULL) return 0;
    for(int i = 0; i < s->top; i++)
        temp[i] = s->array[i];
    free(s->array);
    s->array = temp;
    s->nmax = max;
    return 1;
}

int full(stack *s){
    if(s->top == s->nmax) return 1;
    else return 0;
}

int empty(stack *s){
    if(s->top == 0) return 1;
    else return 0;
}

int push(stack *s, void *data){
    if(full(s) && !resize(s, s->nmax * 2)) return 0;
    void *newData = malloc(s->sizeType);
    if(newData == NULL)
        return 0;
    memcpy(newData, data, s->sizeType);
    s->array[s->top].data = newData;
    s->top++;
    return 1;
}

int pop(stack *s){
    if(!empty(s)){
        s->top--;
        free(s->array[s->top].data);
        if(s->top > 0 && s->top <= (s->nmax / 4))
            resize(s, s->nmax/2);
        return 1;
    }
    return 0;
}

int rtop(stack *s, void *data){
    if(s->top > 0){
        void *returnData = malloc(s->sizeType);
        if(returnData == NULL)
            return 0;
        memcpy(data, s->array[s->top - 1].data, s->sizeType);
        return 1;
    }
    return 0;
}

stack *initialize_stack(unsigned sizeType){
    stack *s;
    s = (stack*) malloc(sizeof(stack));
    if(s == NULL)
        return s;
    s->sizeType = sizeType;
    s->array = (item*) malloc(sizeof(item)*2);
    s->top = 0;
    s->nmax = 2;
    s->full = full;
    s->empty = empty;
    s->push = push;
    s->pop = pop;
    s->rtop = rtop;
    return s;
}

void free_stack(stack *s){
    for(int i = 0; i < s->top; i++)
        free(s->array[i].data);
    free(s->array);
}

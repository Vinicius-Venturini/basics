#include <stdlib.h>
#include <string.h>
#include "fila.h"

int empty(queue *q){
    if(q->qtd == 0) return 1;
    return 0;
}

int insert(queue *q, void *data){
    node *n = (node*)malloc(sizeof(node));
    if(n == NULL)
        return 0;
    void *newData = malloc(q->sizeType);
    if(newData == NULL)
        return 0;
    memcpy(newData, data, q->sizeType);
    n->data = newData;
    n->link = NULL;
    if(q->last) q->last->link = n;
    else q->first = n;
    q->last = n;
    q->qtd++;
    return 1;
}

void rmv(queue *q){
    if(!empty(q)){
        node *n = q->first;
        q->first = n->link;
        free(n->data);
        free(n);
        if(q->first == NULL) q->last = NULL;
        q->qtd--;
    }
}

int rfirst(queue *q, void *data){
    if(!empty(q)){
        void *returnData = malloc(q->sizeType);
        if(returnData == NULL)
            return 0;
        memcpy(data, q->first->data, q->sizeType);
        return 1;
    }
    return 0;
}

queue *initialize_queue(unsigned sizeType){
    queue *q = (queue*) malloc(sizeof(queue));
    if(q == NULL)
        return q;
    q->sizeType = sizeType;
    q->first = q->last = NULL;
    q->qtd = 0;
    q->empty = empty;
    q->insert = insert;
    q->remove = rmv;
    q->rfirst = rfirst;
}

void free_queue(queue *q){
    while(!empty(q))
        rmv(q);
}

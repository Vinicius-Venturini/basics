#ifndef FILA_H
#define FILA_H

struct node {
  void *data;
  struct node *link;
};
typedef struct node node;

typedef struct _queue{
  node *first, *last;
  unsigned qtd, sizeType;
  int (*empty)(struct _queue *q);
  int (*insert)(struct _queue *q, void *data);
  void (*remove)(struct _queue *q);
  int (*rfirst)(struct _queue *q, void *data);
} queue;

queue *initialize_queue(unsigned sizeType);
void free_queue(queue *q);

#endif

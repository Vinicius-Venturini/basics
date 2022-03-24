#ifndef PILHA_H
#define PILHA_H

typedef struct {
  void *data;
} item;

typedef struct _stack{
  unsigned top;
  unsigned nmax;
  unsigned sizeType;
  item *array;
  int (*full)(struct _stack *s);
  int (*empty)(struct _stack *s);
  int (*push)(struct _stack *s, void *data);
  int (*pop)(struct _stack *s);
  int (*rtop)(struct _stack *s, void *data);
} stack;

stack *initialize_stack(unsigned sizeType);
void free_stack(stack *s);

#endif

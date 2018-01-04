#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t_ {
    int val;
    struct node_t_ *next;
} node_t;

typedef struct stack_t_ {
    int count;
    node_t *s;
} stack_t;

stack_t *stack_init(void);
void stack_destroy(stack_t *);
bool stack_is_empty(stack_t *);
int stack_get_count(stack_t *);
int stack_peek(stack_t *);
bool stack_push(stack_t *, int);
int stack_pop(stack_t *);

#endif //STACK_H_

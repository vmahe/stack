/*
 * stack.c
 */
#include "stack.h"
#include <assert.h>

stack_t *stack_init (void)
{
    stack_t *obj = calloc(1, sizeof(stack_t));
    if (!obj) return (NULL);
    obj->count = 0;
    obj->s = NULL;
    return (obj);
}

void stack_destroy (stack_t *obj)
{
    if (obj) {
        if (obj->s) free(obj->s);
        free(obj);
    }
}

bool stack_is_empty (stack_t *obj)
{
    assert(obj);
    return (obj->count == 0);
}


int stack_get_count (stack_t *obj)
{
    assert(obj);
    return (obj->count);
}


int stack_peek (stack_t *obj)
{
    int item;

    assert(obj);
    assert(obj->count);
    item = obj->s->val;

    return(item);
}


bool stack_push (stack_t *obj, int val)
{
    node_t *new;

    assert(obj);
    new = calloc(1, sizeof(node_t));
    if (!new) return (false);

    new->val = val;
    new->next = obj->s;
    obj->s = new;
    obj->count++;

    return (true);
}


int stack_pop (stack_t *obj)
{
    int item;
    node_t *tmp = NULL;

    assert(obj);
    assert(obj->count);
    tmp = obj->s;
    obj->s = tmp->next;
    obj->count--;
    item = tmp->val;
    free(tmp);

    return (item);
}

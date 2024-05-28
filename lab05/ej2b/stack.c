#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "stack.h"

typedef struct _s_stack {
    stack_elem value;
    struct _s_stack *next;
    size_t size;
} node;


bool invrep (stack s) {
    bool b;
    b = s->size == stack_size(s);
    return b;
}                                 // Este sera mi invariante de representacion

void stack_print(stack s) {
  if (stack_is_empty(s)) {
    printf("El stack es vacío\n");
  } else {
    stack_elem *array = stack_to_array(s);
    for (unsigned int i = 0 ; i < stack_size(s); i++) {
      printf("   · %d\n", array[i]);
    }
    free(array);
  }
}



stack stack_empty() {
    node *s = malloc(sizeof(node));
    s->size = 0;
    s->next = NULL;

    assert(invrep(s));
    return s;
}

stack stack_push(stack s, stack_elem e) {
    assert(invrep(s));

    node *p = NULL;
    p = malloc(sizeof(node));
    p->value = e;
    p->next = s;
    p->size = s->size + 1;

    assert(invrep(p)); 
    return p;
}

stack stack_pop(stack s) {
    assert(invrep(s));
    stack p = s;
    stack q = p->next;
    s ->size  = s->size-1;
    free(p);
    assert(invrep(s));

  return q;
}


unsigned int stack_size(stack s) { return s->size; }



stack_elem stack_top(stack s) {
    assert(invrep(s));
    if (stack_is_empty(s)) {
        printf("Error: La pila está vacía\n");
        exit(EXIT_FAILURE);
    }
        assert(invrep(s));

    return s->value;
}

bool stack_is_empty(stack s) {
    assert(invrep(s));
    return s->size == 0;
}

stack_elem *stack_to_array(stack s) {
    assert(invrep(s));
    if (stack_is_empty(s)) {
        return NULL;
    }
    unsigned int size = stack_size(s);
    stack_elem *array = (stack_elem*)malloc(size * sizeof(stack_elem));
    if (array == NULL) {
        return NULL;//exit(EXIT_FAILURE);
    }

    for ( int i = size -1 ; i >= 0; i--) {
        array[i] = s->value;
        s = s->next;
    }
    return array;
    assert(invrep(s));
}

stack stack_destroy(stack s) {
    assert(invrep(s));
    while (!stack_is_empty(s)) {
        s = stack_pop(s);
    }

    s = NULL;          
    assert(invrep(s));      

    return s;
}


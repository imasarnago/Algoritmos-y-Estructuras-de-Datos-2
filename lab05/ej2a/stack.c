#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "stack.h"

typedef struct _s_stack {
    stack_elem value;
    struct _s_stack *next;
} node;




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
    return NULL;
}

stack stack_push(stack s, stack_elem e) {
    node *p= NULL;    
    p = malloc(sizeof(*p));

    p->value = e;
    p->next = s;
    return p;
}


stack stack_pop(stack s) {
    stack p = s;
    stack q = p->next;
    free(p);

  return q;
}

unsigned int stack_size(stack s) {
    unsigned int len = 0;
    node *current = s;
    while (current != NULL) {
        len++;
        current = current->next;
    }
    return len;
}

stack_elem stack_top(stack s) {
    if (stack_is_empty(s)) {
        printf("Error: La pila está vacía\n");
        exit(EXIT_FAILURE);
    }
    return s->value;
}

bool stack_is_empty(stack s) {
    return s == NULL;
}

stack_elem *stack_to_array(stack s) {
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
}

void stack_destroy(stack s) {
    assert(!stack_empty(s));
    while (!stack_is_empty(s)) {
        s = stack_pop(s);
    }
}




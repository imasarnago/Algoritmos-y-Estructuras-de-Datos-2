#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"


#define CAPACIDAD_ORIGINAL 20u


struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

bool invrep (stack s){
    bool b = s->size == stack_size(s) && s->size <= s->capacity;
    return b;
}


stack stack_empty() {
    stack s = malloc(sizeof(*s));
    s->elems = malloc(CAPACIDAD_ORIGINAL * sizeof(stack_elem));
    s->size=0;
    s->capacity = CAPACIDAD_ORIGINAL;
    invrep(s);
    return s;
}


stack stack_push(stack s, stack_elem e) {
    assert(invrep(s));

    if (stack_size(s) == s->capacity) {
        size_t new_capacity = CAPACIDAD_ORIGINAL * 2;
        s->elems = realloc (s->elems, new_capacity);
    }
    if (stack_size(s) > s->capacity){
        printf ("Ha ocurrido un error. El tamaño supera la capacidad");
    }

    for (unsigned int i = s->size; i > 0; i--) {
        s->elems[i] = s->elems[i - 1];
    }

    s->elems[0] = e;
    s->size++;

    assert(invrep(s));
    return s;
}

stack stack_pop(stack s) {

    assert(invrep(s));
    assert(!stack_is_empty(s));

    for (unsigned int i = 0; i < s->size - 1; i++) {
        s->elems[i] = s->elems[i + 1];
    }
    s->size--;
    assert(invrep(s));
    return s;
}



unsigned int stack_size(stack s) {
    //assert(invrep(s));
    return s->size;
    }



stack_elem stack_top(stack s) {
    assert(invrep(s));
    if (stack_is_empty(s)) {
        printf("Ha ocurrido un error. La pila es vacia '\n");
        assert(invrep(s));
        return EXIT_FAILURE;
    }
    else { 
        assert(invrep(s));
        
        return s->elems[0];
    }
}


bool stack_is_empty(stack s) {
    assert(invrep(s));
    bool b;
    b = s->size == 0;
    assert(invrep(s));
    return b;
}


stack_elem *stack_to_array(stack s) {
    assert(invrep(s));
    stack_elem *new_array = NULL;
    new_array = malloc(sizeof(stack_elem)*s->size);
    for (unsigned int i = 0; i<s->size;i++) {
        new_array[i] = s->elems[i];
    }
    assert(invrep(s));
    return new_array; // ES UN ARREGLO DINAMICO. DEBERE LIBERARLO LUEGO DE USARLO !
}


stack stack_destroy(stack s) {
    assert(invrep(s));
    free(s->elems);
    s->elems = NULL;
    free(s);
    s = NULL;
    return s;
}

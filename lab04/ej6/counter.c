#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};



counter counter_init(void) {
    counter new_pair = (counter)malloc(sizeof(counter));
    new_pair->count = 0;
    return new_pair;
}

void counter_inc(counter c) {
    assert (c!= NULL);
    c->count = c->count+1;    
}

bool counter_is_init(counter c) {
    bool b;
    return b = (c->count==0);
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count = c->count-1;
}

counter counter_copy(counter c) {
    assert (c != NULL);
    counter np = (counter)malloc(sizeof(*np));    
    np->count = c->count;
    return np;
}

void counter_destroy(counter c) {
    free (c);
}

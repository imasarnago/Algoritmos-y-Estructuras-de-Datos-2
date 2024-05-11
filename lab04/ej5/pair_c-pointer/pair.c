#include <stdio.h>
#include <stdlib.h>

#include "pair.h"

pair_t pair_new(int x, int y) {
    pair_t p = malloc(sizeof(pair_t));
    p->fst = x;
    p->snd = y;
    return p;
}

int pair_first(pair_t p) {
    assert (p != NULL);
    return p->fst;
}

int pair_second (pair_t p) {
    assert (p != NULL);

    return p->snd;
}

pair_t pair_swapped(pair_t p) {
    assert (p != NULL);

    pair_t np = pair_new(p->fst,p->snd);
    int tmp = p->fst;
    np->fst = p->snd;
    np->snd = tmp;
    return np;
}
    

pair_t pair_destroy(pair_t p) {
    assert (p != NULL);
    free(p);
    return NULL;    
}


/*estaría aún mas encapsulado si el usuario del codigo no tuviera ninguna forma de 
ver su implementación. En este caso, como se asume el rol de implementador y usuario al mismo tiempo,
es posible saber cómo se encuentra implementado el código, de algún modo "rompiendo la abstracción"*/
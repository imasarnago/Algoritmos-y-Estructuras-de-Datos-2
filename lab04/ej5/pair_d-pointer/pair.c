#include <stdio.h>
#include <stdlib.h>

#include "pair.h"

typedef struct s_pair_t {
    int fst;
    int snd;
} s_pair_t; 



pair_t pair_new(int x, int y) {
    pair_t new_pair = (pair_t)malloc(sizeof(s_pair_t));
    new_pair->fst = x;
    new_pair->snd= y;
    return new_pair;
    
}

int pair_first(pair_t p) {
    return p->fst;
}

int pair_second (pair_t p) {
    return p->snd;
}

pair_t pair_swapped(pair_t p) {
    pair_t np = pair_new(p->fst,p->snd);
    int tmp = p->fst;
    np->fst = p->snd;
    np->snd = tmp;
    return np;
}

pair_t pair_destroy(pair_t p) {
    free(p);
    return NULL;    
}


/*
En este caso el codigo se encuentra bien encapsulado. Si el usuario sólo ve su especificación
(el archivo .h), no podrá deducir nada sobre cómo ha sido implementado el TAD y, más aún, 
no podrá modificar el estado del TAD sino a través de los operadores y constructores allí definidos.
*/
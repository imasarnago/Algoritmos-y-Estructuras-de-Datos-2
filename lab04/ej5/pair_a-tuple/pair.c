#include <stdio.h>
#include <stdlib.h>
#include "pair.h"

pair_t pair_new(int x, int y) {
    pair_t par;
    par.fst=x;
    par.snd = y;
    return par;
}

int pair_first(pair_t p) {
    return p.fst;
}

int pair_second(pair_t p){
    return p.snd;
}


pair_t pair_swapped(pair_t p) {
    pair_t np  =  pair_new (p.fst,p.snd);
    int tmp;
    tmp = p.fst;
    np.fst = p.snd;
    np.snd = tmp; 
    return np;

}

pair_t pair_destroy(pair_t p) {
    return p;
}


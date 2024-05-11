#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pair.h"


pair_t pair_new(int x, int y) {
    pair_t np;
    np.values[0] = x;
    np.values[1] = y;
    return np;
}

int pair_first(pair_t p) {
    return p.values[0];
    
}

int pair_second (pair_t p) {
    return p.values [1];
}

pair_t pair_swapped(pair_t p) {
    pair_t np = pair_new(p.values[0],p.values[1]);
    int tmp = np.values[0];
    np.values[0] = np.values[1];
    np.values[1] = tmp;
    return np;
}

pair_t pair_destroy(pair_t p) {
    return p;
}

/* El programa compiló a la primera sin ningún problema. Y si, logra mantener el encapsulamiento
porque sólo se puede modificar y o acceder al estado del TAD mediante las operaciones
provistas en la especificación del mismo. El usuario puede no ver su implementación 
y aún así usar el TAD mediante sus operaciones.
Además se encuentra bien separado en modulos la especificación de la implementación. 
De todos modos estaría aún mas encapsulado si el usuario del codigo no tuviera ninguna forma de 
ver su implementación. En este caso, como se asume el rol de implementador y usuario al mismo tiempo,
es posible saber cómo se encuentra implementado el código, de algún modo "rompiendo la abstracción" */
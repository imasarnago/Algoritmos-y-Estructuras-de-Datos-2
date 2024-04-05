#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}



static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {

    unsigned int ppiv=izq;
    if (der>izq){ 
        ppiv = partition(a, izq, der);
        
        // quick_sort_rec(a,izq,ppiv-1); La alternativa (esta línea) es decir ppiv - 1, pero como ppiv puede ser 0 y 0-1 hace overflow, entonces hago:
        quick_sort_rec(a, izq, (ppiv == 0u) ? 0u : ppiv - 1u);
        
        quick_sort_rec(a, ppiv + 1, der);
    }

}


#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    /* needs implementation */

    /*proc insert (in/out a: array[1..n] of T, in i: nat)
        var j: nat
        j:= i
        do j > 1 ∧ a[j] < a[j − 1] → swap(a,j-1,j)
        j:= j-1
        od
    end proc*/

    unsigned int j =i;
    while (j>1 && a[j]<a[j-1]){
        swap(a,j-1,j);
        j = j-1;
    }


}

void insertion_sort(int a[], unsigned int length) {

    /*Invariante:
    el arreglo a es una permutación del original y
    un segmento inicial a[1,i) del arreglo está ordenado.
    (pero en general a[1,i) no contiene los mínimos del arreglo)
*/



    for (unsigned int i = 1u; i < length; ++i) {
        /* needs implementation */
        insert(a, i);
        assert(array_is_sorted);
    }
}

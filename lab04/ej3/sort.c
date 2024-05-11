/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    
    bool res;
    if (x->rank <= y->rank) { 
        res = true;
    }else { return res = false;}
    return res;

}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void swap(player_t a[], unsigned int i, unsigned int j) {
  player_t temp_i = a[i];
  a[i] = a[j];
  a[j] = temp_i;
}



static unsigned int partition(player_t a[], unsigned int izq,
                              unsigned int der) {
      unsigned int i;
      unsigned int j;
      unsigned int ppiv;
      ppiv = izq;
      i = izq + 1;
      j = der;

      while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
          i = i + 1;
        } else if (goes_before(a[ppiv], a[j])) {
          j = j - 1;
        } else if (!goes_before(a[i], a[ppiv]) && !goes_before(a[ppiv], a[j])) {
          swap(a, i, j);
          i = i + 1;
          j = j - 1;
        };
      };

      swap(a, ppiv, j);
      ppiv = j;

      return ppiv;
}

static void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv;
    if (der > izq) {
      ppiv = partition(a, izq, der);
      quick_sort_rec(a, izq, (ppiv == 0u) ? 0u : ppiv - 1u);
      quick_sort_rec(a, ppiv + 1, der);
    }
}






void sort(player_t a[], unsigned int length) {
    // completar aquí

      quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);

}




/*El beneficio de utilizar punteros a estructuras en vez de las estructuras en sí mismas, es que ya no tengo la necesidad
de pasar como argumento a las funciones toda una estructura ni tampoco devolverla completa como retorno de una función. 
Al manipular mediante punteros lo que hago es acceder (a través de su dirección de memoria) directamente a la estructura 
original y allí mismo modificar los valores contenidos en sus campos. */


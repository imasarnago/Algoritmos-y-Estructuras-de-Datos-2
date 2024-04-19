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
    // completar aquí
    bool res;
    if (x.rank <= y.rank) {
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







/* I'll use the "quick_sort" algorithm to sort the array given in this exercise. Nevertheless, it's important to point out that
   any of the sorting algorithms seen in class can be used to do the exact same thing.
*/


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


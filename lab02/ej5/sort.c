// #include <assert.h>
#include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>

// #include "array_helpers.h"
#include "fixstring.h"
#include "sort.h"
#include "sort_helpers.h"



static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {

  unsigned int ppiv = izq;
  unsigned int i = izq + 1;
  unsigned int j = der;

  while (i <= j) {
    if (goes_before_alpha(a[i], a[ppiv])) {
      i = i + 1;
    } else if (goes_before_alpha(a[ppiv], a[j])) {
      j = j - 1;
    } else  {
      swap(a, i, j);
      i = i + 1;
      j = j - 1;
    }
  }

  swap(a, ppiv, j);
  ppiv = j;

  return ppiv;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
  unsigned int ppiv;
  if (der > izq) {
    ppiv = partition(a, izq, der);
    quick_sort_rec(a, izq, (ppiv == 0u) ? 0u : ppiv - 1u);
    quick_sort_rec(a, ppiv + 1, der);
  }
}


void quick_sort(fixstring a[], unsigned int length) {
  quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}







static unsigned int partition_length(fixstring a[], unsigned int izq, unsigned int der) {

  unsigned int ppiv = izq;
  unsigned int i = izq + 1;
  unsigned int j = der;

  while (i <= j) {
    if (goes_before_length(a[i], a[ppiv])) { 
      i = i + 1;
    } else if (goes_before_length(a[ppiv], a[j])) {
      j = j - 1;
    } else if (goes_before_length(a[ppiv], a[i]) && goes_before_length(a[j], a[ppiv])) {
      swap(a, i, j);
      i = i + 1;
      j = j - 1;
    };
  };

  swap(a, ppiv, j);
  ppiv = j;

  return ppiv;
}

static void quick_sort_rec_length(fixstring a[], unsigned int izq, unsigned int der) {
  unsigned int ppiv;
  if (der > izq) {
    ppiv = partition_length(a, izq, der);
    quick_sort_rec_length(a, izq, (ppiv == 0u) ? 0u : ppiv - 1u);
    quick_sort_rec_length(a, ppiv + 1, der);
  }
}

void quick_sort_length(fixstring a[], unsigned int length) {
  quick_sort_rec_length(a, 0, (length == 0) ? 0 : length - 1);
}

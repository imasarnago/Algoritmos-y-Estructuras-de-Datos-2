/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "sort.h"
#include "sort_helpers.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
  /* Print the usage help of this program. */
  printf("Usage: %s <input file path>\n\n"
         "Sort an array given in a file in disk.\n"
         "\n"
         "The input file must have the following format:\n"
         " * The first line must contain only a positive integer,"
         " which is the length of the array.\n"
         " * The second line must contain the members of the array"
         " separated by one or more spaces. Each member must be an integer."
         "\n\n"
         "In other words, the file format is:\n"
         "<amount of array elements>\n"
         "<array elem 1> <array elem 2> ... <array elem N>\n\n",
         program_name);
}

char *parse_filepath(int argc, char *argv[]) {
  /* Parse the filepath given by command line argument. */
  char *result = NULL;

  if (argc < 2) {
    print_help(argv[0]);
    exit(EXIT_FAILURE);
  }

  result = argv[1];

  return result;
}

int main(int argc, char *argv[]) {
  char *filepath = NULL;

  /* parse the filepath given in command line arguments */
  filepath = parse_filepath(argc, argv);

  /* create an array of MAX_SIZE elements */
  int array[MAX_SIZE];

  /* parse the file to fill the array and obtain the actual length */
  unsigned int length = array_from_file(array, MAX_SIZE, filepath);

  // sort
  /* create a copy of the array */
  int copy[MAX_SIZE];
  array_copy(copy, array, length);

  /* reset counters and set time */
  reset_comparisons_counter();
  reset_swaps_counter();
  set_current_time();

  /* do the actual sorting */
  selection_sort(copy, length);

  /* show statistics for selection_sort */
  printf("statistics for selection_sort\n");
  printf("time elapsed=%g,    comparisons: %10u,    swaps: %10u\n",
         calculate_elapsed_time(), comparisons_number(), swaps_number());

  /* create a copy of the array */
  array_copy(copy, array, length);

  /* reset counters and set time */
  reset_comparisons_counter();
  reset_swaps_counter();
  set_current_time();

  /* do the actual sorting */
  insertion_sort(copy, length);

  /* show statistics for insertion_sort */
  printf("statistics for insertion_sort\n");
  printf("time elapsed=%g,    comparisons: %10u,    swaps: %10u\n",
         calculate_elapsed_time(), comparisons_number(), swaps_number());

  /* create a copy of the array */
  array_copy(copy, array, length);

  /* reset counters and set time */
  reset_comparisons_counter();
  reset_swaps_counter();
  set_current_time();

  /* do the actual sorting */
  quick_sort(copy, length);

  /* show statistics for quick_sort */
  printf("statistics for quick_sort\n");
  printf("time elapsed=%g,    comparisons: %10u,    swaps: %10u\n",
         calculate_elapsed_time(), comparisons_number(), swaps_number());

  return EXIT_SUCCESS;
}

/* 
    Lo que notamos al correr todos estos algoritmos con un arreglo desordenado (unsorted.in), es que selection_sort demora 41 segundos más que
    los otros dos, que demoran exactamente lo mismo (0.002 segundos.). Además, el quick_sort realiza el doble de comparaciones que
    selection_sort

    Con un arreglo ordenado (sorted.in), todos los algoritmos demoran lo mismo y realizan la misma cantidad de comparaciones que en el caso 
    anterior. Selection_sort demoró 0.003 segundos más que antes.

    Con un arreglo totalmente vacío, observamos que quick_sort es bastante más rápido que todos los demás y que el más lento de los tres
    es el primer algoritmo (selection_sort).

    Con un arreglo ordenado de manera ascendente o descendente, el selection_sort realiza aproximadamente la mitad de comparaciones que quick_sort
    y además es mucho más rápido. 

*/
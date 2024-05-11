#include <stdbool.h>


typedef struct node *list;
typedef int elem;



list empty_list (void);
// This will create an empty list, and it's return value will be of type list.

list addl (elem e, list l);
// This function will return the same list given as a parameter, but with one element 
// added at the beginning (left side).

bool is_empty (list l);
// It returns true if the list is an empty list.

elem head (list l);
// It will return the first element of the list given as a parameter
// PRE: !is_empty(list l)

list tail (list l);
// It will drop the first element of the given list (the head) and it will
// return the list with the remaining elements
// PRE: !is_empty(list l)

unsigned int length_list (list l);
// It return the total amount of elemnts in the list


list addr (elem e, list l);
// It adds an element to the right side of the list.

list concat (list l, list t);
// It adds all the elements of t to the end of l (in the same order, of course)

elem index (list l, unsigned int n);
// It returns the element in the n position of the list.
// PRE: length (l)>n

list take (list l, unsigned int n);
// Deja en l sólo los primeros n
// elementos, eliminando el resto

list drop (list l, unsigned int n);
// Elimina los primeros n elementos de l

list copy_list (list l);
// Copia todos los elementos de l1 en la nueva lista l2

void destroy (list l);
// It frees memory if needed



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "list.h"

typedef struct node {
    elem elem;
    struct node *next;
} node;





list empty_list (void) {
    list l = NULL;
    return l;
}

list addl(elem e, list l) {
  node *p;
  p = malloc(sizeof(node));
  p->elem = e;
  p->next = l;
  l = p;
  return l;
}




bool is_empty (list l) {
    return l == NULL;
}

elem head (list l) {
    assert (!is_empty(l));
    elem h = l->elem;
    return h;
}

list tail (list l){ 
    assert (!is_empty(l));
    l = l;
    l = l->next;
    return l;
}

unsigned int length_list (list l) {
    node *p;
    unsigned int n = 0;
    p = l;
    while (p != NULL) {
        n = n + 1;
        p = p->next;
    }
    return n;
}



list addr(elem e, list l) { 
    node *p;
    node *q;

    q = malloc(sizeof(node));
    q->elem = e;
    q->next = NULL;

    if (!is_empty(l)) {
        p = l;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = q;
    } 
    else {l = q;}

    return l;
}




list concat (list l1, list l2){
    node *p  = l1;
    while (l1 ->next != NULL) {
        p = p->next;
    }
    p->next = l2;
    return l1;
}



elem index (list l, unsigned int n){
    assert (length_list(l)>n);
    node *p;
    p = malloc(sizeof(node));
    p = l;
    unsigned int i = 0;
    while (i<n) {
        p = p->next;
        i++;
    }
    return p->elem;
}


list take (list l, unsigned int n) {
    node *p,*q;
    unsigned int i  = 0;
    assert(length_list(l)>=n);

    if (l != NULL) {
        if (n>0){
            p = l;
            while (l != NULL && i<=n) {
                p = p->next;
            }
            while (p != NULL) {
                q = p;
                p = p->next;
                free (q);
            } 
        }
        else (printf("Ha ocurrido un error. El número debe ser mayor a 0"));
    }
    return l;
}



list drop (list l, unsigned int n) {
    node *p,*q;
    unsigned int i =0;
    assert(length_list(l)>=n);
    p = l;
    while (i<n) {
        q = p;
        p = p->next;
        free (q);
    }
    return l;
}





list copy_list (list l){

    node *l2 = malloc(sizeof(node));
    for (unsigned int i = 0;i<length_list(l);i++) {
        l2->elem = l->elem;
        l2->next = l->next;
        l = l->next;
        l2 = l2->next;
    }
    return l2;
}

void destroy(list l) {
  while (l != NULL) {
    list temp = l;
    l = l->next;
    free(temp);
  }
}


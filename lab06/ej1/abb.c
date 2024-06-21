#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool invrep(abb tree) {
    bool b;

    if (abb_is_empty(tree)) {
        b = true;
    }
    else {
        if (!abb_is_empty(tree->left)) {
            b = (!elem_less(tree->elem,tree->left->elem)) && invrep(tree->right);
        }
        if (!abb_is_empty(tree->right)){
            b = (elem_less(tree->elem,tree->right->elem)) && invrep(tree->left);
        }
    }

    return b;
}

abb abb_empty(void) {
    abb tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    
    if (abb_is_empty(tree)) {
        tree = malloc(sizeof(*tree));
        tree->elem=e;
        tree->left=NULL;
        tree->right=NULL;
    }
    else {
        if (elem_less(e,tree->elem)) {
            tree->left = abb_add(tree->left,e);
        }
        if (elem_less(tree->elem,e) && !elem_eq(e, tree->elem)) {
            tree->right = abb_add(tree->right,e);
        }
    }

    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    bool is_empty=false;
    assert(invrep(tree));
    is_empty = tree ==NULL;
    return is_empty;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    
    if (!abb_is_empty(tree)) {
        exists = elem_eq(e,tree->elem) || elem_eq(e,tree->left) || elem_eq(e,tree->right);
    }

    assert(abb_length(tree)!=0 || !exists);
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    
    if (!abb_is_empty(tree)) {
        length = 1 + abb_length(tree->left) + abb_length(tree->right);
    }

    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));

    if (!abb_is_empty(tree)) {

        if (elem_less(e, tree->elem)) {
            tree->left = abb_remove(tree->left,e);
        }
        else if (elem_less(tree->elem,e)) {
            tree->right = abb_remove(  tree->right,e);
        }
        else {
            abb aux = tree;
            if (tree->left==NULL) {
                tree = tree->right;
                free(aux);
            }
            else if (tree->right==NULL) {
                tree = tree->left;
                free(aux);
            }
            else {                  // Con las siguientes lineas de codigo del programa me ayudo un compañero. Es un codigo muy limpio y eficaz:
                aux = NULL;
                aux = tree->right;
                
                while (aux->left != NULL) {
                    aux = aux->left;
                }
                tree->elem = aux->elem;
                tree->right = abb_remove(tree->right,aux->elem);   // ESTO NO TERMINO DE ENTENDER POR QUE FUNCIONA
            }
        }
    }




    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    
    root = tree->elem;

    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));

    max_e = abb_is_empty(tree->right) ? tree->elem : abb_max(tree->right);

    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    
    min_e = abb_is_empty(tree->left) ? tree->elem : abb_min(tree->left);

    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree, abb_ordtype ord) {
    assert(invrep(tree) && (ord==ABB_IN_ORDER  || 
                            ord==ABB_PRE_ORDER ||
                            ord==ABB_POST_ORDER));
    /*
     * c) Needs implementation: use the dump order indicated by `ord`
     *
     */

    // Implementing in-order as default
    if (tree != NULL) {
        abb_dump(tree->left, ord);
        printf("%d ", tree->elem);
        abb_dump(tree->right, ord);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));

    if (!abb_is_empty(tree)) {
        abb_destroy(tree->left);
        abb_destroy(tree->right);
        free(tree);
        tree = NULL;
    }

    return tree;
}


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"


/*  Además se debe
modificar main.c para que no haya memory leaks.  */


struct s_queue {
    size_t size;
    struct s_node *first;
    struct s_node *last;
};

struct s_node {
    queue_elem elem;
    struct s_node *next;
};

static struct s_node *
create_node(queue_elem e) {
    struct s_node *new_node=malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;
    return new_node;
}

static struct s_node *
destroy_node(struct s_node *node) {
    node->next=NULL;
    free(node);
    node=NULL;
    return node;
}


static bool
invrep(queue q) {
    return q != NULL;
}

queue queue_empty(void) {
    queue q = malloc (sizeof(struct s_queue));
    if (q == NULL) {
        printf("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    q->first = NULL;
    q->size = 0;


    q->last = NULL;



    assert(invrep(q) && queue_is_empty(q));
    return q;
}

queue queue_enqueue(queue q, queue_elem e) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e);
    if (q->first==NULL) {
        q->first = new_node;
    } else {
        struct s_node *p = q->first;
        while (p->next != NULL) {
        p = p->next;
        }
        p->next = new_node;


        q->last = new_node;
    
    
    }
    q->size++; 
    assert(invrep(q) && !queue_is_empty(q));
    return q;
}

bool queue_is_empty(queue q) {
    assert(invrep(q));
    return q->first == NULL;
}

queue_elem queue_first(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    return q->first->elem;
}


unsigned int queue_size(queue q) {
    assert(invrep(q));
    unsigned int size=0;
    if (q->first==NULL) {
        q->size = 0;
        assert (q->size == 0);
    } else {
        struct s_node *p = q->first;
        size = size + 1;
        while (p->next != NULL) {
        p = p->next;
        size = size + 1;
        q->size = q->size + 1;
        }
    }
    return size;
}

queue queue_dequeue(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    struct s_node *killme=q->first;
    q->first = q->first->next;
    killme = destroy_node(killme);
    assert(invrep(q));
    return q;

}

queue queue_disscard(queue q, unsigned int n){
    assert(q != NULL && n < queue_size(q));
    struct s_node *p = q->first;
    if (n == 0) {
        q->first = q->first->next;
        destroy_node(p);
        p = q->first;
    }
    if (n>0) {
        for (unsigned int i = 0; i<n-1;i++) {
            p = p->next;
        }
    struct s_node *t = p->next;
    p->next = t->next;


    if (t == q->last) {
        q->last = p;
    }


    destroy_node(t);
    }
    q->size--;
    assert (q != NULL);
    return q;
}




void queue_dump(queue q, FILE *file) {
    file = file==NULL ? stdout: file;
    struct s_node *node=q->first;
    fprintf(file, "[ ");
    while(node!=NULL) {
        fprintf(file, "%d", node->elem);
        node = node->next;
        if (node != NULL) {
            fprintf(file, ", ");
        }
    }
    fprintf(file, "]\n");
}

queue queue_destroy(queue q) {
    assert(invrep(q));
    struct s_node *node=q->first;
    while (node != NULL) {
        struct s_node *killme=node;
        node = node->next;
        killme = destroy_node(killme);
    }
    free(q);
    q = NULL;
    return q;
}


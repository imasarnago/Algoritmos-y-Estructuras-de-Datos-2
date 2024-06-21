#include <assert.h>
#include "dict.h"
#include "key_value.h"
#include <stdlib.h>

struct _node_t {
    dict_t left;
    key_t key;
    value_t value;
    dict_t right;
};

static bool invrep(dict_t d) {
    bool b;

    if (d == NULL) {
        b = true;
    }
    else {
        if (d->left != NULL) {
            b = !(d->key < d->left->key) && invrep(d->right);
        }
        if (d->right!=NULL){
            b = (d->key > d->right->key)  && invrep(d->left);
        }
    }

    return b;
}

dict_t dict_empty(void) {
    dict_t dict = NULL;
    assert(invrep(dict) && dict_length(dict) == 0);
    return dict;
}

bool dict_is_empty(dict_t dict) {
    return dict ==NULL;
    }

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    if (dict_exists(dict,word)) {
        if (key_eq(dict->key,word)) {
            dict->value = def;
        }else {
            if (key_less(dict->key,word)) {
                dict->left = dict_add(dict->left,word,def);
            }else {
                dict->right = dict_add(dict->right,word,def);
            }
        }
    }  
    else {
        if (dict_is_empty(dict)) {
            dict = malloc(sizeof(*dict));
            dict->left = NULL;
            dict->key = word;
            dict->value = def;
            dict->right = NULL;
            } else {
                if (key_less(word, dict->key)) {
                    dict->left = dict_add(dict->left,word,def);
            } else {
                dict->right = dict_add(dict->right,word,def);
            }
    }
    }
    return dict;

}

value_t dict_search(dict_t dict, key_t word) {
    value_t def = NULL;
    if (dict_is_empty(dict) || !dict_exists(dict,word)) {
        def = NULL;
    }
    else {
        if (key_eq(dict->key,word)) {
            def = dict->key;
        } else {
            def = dict_search(dict->left,word);
            def = dict_search(dict->right,word);
        }
    }
    invrep(dict);
    return def;
}

bool dict_exists(dict_t dict, key_t word) {
    
    bool b=false;
    if(!dict_is_empty(dict)){
        if (key_eq(word,dict->key)){
            b = true;
        }
        b = dict_exists(dict->left,word) || dict_exists(dict->right,word);
    }

    return b;
}

unsigned int dict_length(dict_t dict) {
    unsigned int length=0;
    if (dict_is_empty(dict)){
        length = 0;
        }
    else{
        length = 1 + dict_length(dict->left) + dict_length(dict->right);
        }
    return length;
}

dict_t dict_remove(dict_t dict, key_t word) {
    if (!dict_is_empty(dict)) {

        if (key_less(word, dict->key)) {
            dict->left = dict_remove(dict->left,word);
        }
        else if (key_less(dict->key,word)) {
            dict->right = dict_remove(  dict->right,word);
        }
        else {
            dict_t aux = dict;
            if (dict->left==NULL) {
                dict = dict->right;
                free(aux);
            }
            else if (dict->right==NULL) {
                dict = dict->left;
                free(aux);
            }
            else {  
                aux = NULL;
                aux = dict->right;
                
                while (aux->left != NULL) {
                    aux = aux->left;
                }
                dict->key = aux->key;
                dict->right = dict_remove(dict->right,aux->key);   // ¡¿ESTO NO TERMINO DE ENTENDER POR QUE FUNCIONA?!
                key_destroy(dict->key);
                value_destroy(dict->value);
            }
        }
    }
    return dict;
}


dict_t dict_remove_all(dict_t dict) {
    if (!dict_is_empty(dict)) {
        dict = dict_remove_all(dict->left);
        dict = dict_remove_all(dict->right);
        dict = dict_remove(dict,dict->key);
    }
    assert(invrep(dict) && dict_length(dict) == 0);
    return dict;
}








void dict_dump(dict_t dict, FILE *file) {
  if (!dict_is_empty(dict)) {

    key_dump(dict->key, file);
    printf(": ");
    value_dump(dict->value, file);
    printf("\n");

    dict_dump(dict->left, file);

    dict_dump(dict->right, file);
  }
}












dict_t dict_destroy(dict_t dict) {

  dict = dict_remove_all(dict);
  assert(dict == NULL);

  return dict;
}



// tar -czvf lab06_Carrozzo_Sarnago_Imanol.tar.gz lab06


#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    /* copiá acá la implementación que hiciste en el ejercicio 0 */
    unsigned int contador = 0;
    while(s[contador]!='\0'){
        contador++;
    }
    return contador;    
}


bool fstring_eq(fixstring s1, fixstring s2) {
    /* copiá acá la implementación que hiciste en el ejercicio 0 */
    bool soniguales = true;
    int i = 0;
    while (soniguales && (s1[i]!='\0' && s2[i]!='\0')){
        soniguales = soniguales && s1[i] == s2[i];
        i++;
    }
   if (fstring_length(s1) != fstring_length(s2)) {
    soniguales = false;
  }
    
    return soniguales;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool menoroigual = true;
    int contador = 0;
    while (contador < FIXSTRING_MAX && s1[contador] == s2[contador]) {
        contador++;
    }
    if (contador < FIXSTRING_MAX && s1[contador] < s2[contador]) {
        menoroigual = true;
    } else {
        menoroigual = false;
    }
    return menoroigual;
}

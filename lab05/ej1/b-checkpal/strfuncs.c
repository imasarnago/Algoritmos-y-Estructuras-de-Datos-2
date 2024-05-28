#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

#include "strfuncs.h"




size_t string_length(const char *str) {
    size_t len = 0;
    while (str [len] != '\0') {
        len += 1; 
    }
    return len;
} /* calcula la longitud de la cadena apuntada por str */

char *string_filter(const char *str, char c) {
    size_t length_string = string_length(str);
    char *p = malloc (sizeof(char)*(length_string+1));
    size_t j = 0;
    for (size_t i= 0; i<length_string;i++) {
        if (str[i] != c) {
            p[j] = str[i];
            j++;
        }
    }
    p[j] = '\0';
    return p;
} /* Devuelve una nueva cadena en memoria dinámica que se obtiene tomando los caracteres de str
que son distintos del caracter c */







bool string_is_symmetric(const char *str){
    bool b = true;
    size_t len = string_length(str);

    unsigned int i,j;
    i = 0;
    j = len-1;
    while (i<=j && b){
        if (str[i] == str[j]){
            b = true;
        }
        else {
            b = false;
        }
        i++;
        j--;
    }
    return b;
}
/* indica si la cadena apuntada por str es simétrica en cuanto que el primer caracter coincide con el
último, el segundo con el penúltimo, etc; como por ejemplo las cadenas "aba", "abcba", "a", "".  */

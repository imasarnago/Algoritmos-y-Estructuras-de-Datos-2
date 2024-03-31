#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    /*
     La función fstring_length() devuelve la longitud de la cadena guardada en el parámetro s
     *
     */
    unsigned int contador = 0;
    while(s[contador]!='\0'){
        contador++;
    }
    return contador;    
}

bool fstring_eq(fixstring s1, fixstring s2) {
    /*
    

     la función fstring_eq() indica si las cadenas s1 y s2 son iguales (contienen la misma cadena)
     *
     */
    bool soniguales = true;
    int i = 0;
    while (soniguales && (s1[i]!='\0' || s2[i]!='\0')){
        soniguales = soniguales && s1[i] == s2[i];
        i++;
    }
    return soniguales;
    
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    /*
     *  indica si la cadena guardada en s1 es menor o igual que la guardada en s2 en el sentido del orden alfabético
     */
    bool menoroigual = true;
    int contador = 0;
    while (menoroigual&&(s1[contador]!='\0' || s2[contador]!='\0')){
        menoroigual = menoroigual && s1[contador] <= s2[contador];
        contador++;
    }
    return menoroigual;

}


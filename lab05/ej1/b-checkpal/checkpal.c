#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 20

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main(void) {
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.' }; 
    char *filtered=NULL;

    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: ", MAX_LENGTH);
    char *res = fgets (user_input, MAX_LENGTH, stdin);                 //scanf("%s", user_input);

    if (res == NULL) {
        printf("ERROR FATAL LEYENDO CARACTERES \n");
        return EXIT_FAILURE;
    }

    size_t len = string_length(user_input);
    if (len>0 && user_input[len-1] == '\n') {
        user_input[len-1] = '\0';
    }

    filtered = string_filter(user_input, ignore_chars[0]); // ¡¡ESTO ESTA ALOCANDO MEMORIA!!
    for (unsigned int i=0; i < SIZEOF_ARRAY(ignore_chars); i++) {
        char *p = filtered;
        filtered = string_filter(filtered, ignore_chars[i]);
        free (p);
    }


    printf("El texto:\n\n"
            "\"%s\" \n\n"
            "%s un palíndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es");


    free (filtered);
    return EXIT_SUCCESS;
}


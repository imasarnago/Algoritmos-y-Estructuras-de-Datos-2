#include "string.h"
#include <stdio.h>
#include <stdlib.h>


int main (void) {

    string string1 = string_create("String1");
    string string2 = string_create("String2");
    string string3 = string_create("String1");

    if (string_less(string1,string2)) {
        printf("The first string is alphabetically first than the second one");
    } else {
        printf("The first string is not alphabetically first than the second one");
    }

    if( string_eq(string1,string3)) {
        printf("The first string is equal to the third one");
    } else {
        printf("The first string is not equal to the third one");
    }
    string_destroy(string1);
    string_destroy(string2);
    string_destroy(string3);
    return 0;
}

/*
git remote add origin ____________
*/
#include <stdio.h>
//Para guardar un string en C, usamos el siguiente ARREGLO
char cadena[5]; // En este ejemplo, el arreglo puede guardar un string de hasta 4 caracteres de longitud, 
                //porque toda CADENA debe terminar con el caracter '\0', 
                //para poder saber donde terminar independientemente de la capacidad del arreglo
char cadena[5]={'h', 'o', 'l', 'a', '\0'};
/* ¡Con lo que no hay problema es con declarar una longitud mayor a la que realmente necesitamos! Allí solo se imprime los caracteres declarados */

// Tambien puedo hacer algo como esto:
char cadena[10]= "hola"; // En este caso el caracter "\0" se agrega implícitamente en el arreglo

// Para no tener que estar contando la cantidad de caracteres que necesitamos, se puede definir una cadena asi:
char cadena[] = "Hola mundo!"; // Aquí tambien se agrega implícitamente el caracter especial
/*Es importante mencionar que todas estas formas diferentes de armar strings solo son validas al momento de la inicializacion del arreglo. Sino vamos a tener un error de compilacion*/
/*En el ejercicio numero 1 trabajaremos con cadenas guardadas en arreglos que tienen un tamaño fijo. Vamos a definir un tipo para estas cadenas usando typedef*/
/*Le damos un nombre nuevo a un tipo que ya existe en C*/

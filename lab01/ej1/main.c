/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {

    //your code here!!!    EJERCICIO 1

    FILE *file = fopen(filepath, "r"); // Retorna NULL si no se puede abrir 
                                        // Leer un archivo en C hace que tomemos la informacion y la cargamos en nuestra memoria RAM (en alguna variable, arreglo, etc.)
    

    unsigned int longitud;
    fscanf(file, "%d", &longitud); // Esta ultima linea debe ser revisada y además debo vere si modificar la guarda del siguiente ciclo es correcto
    unsigned int contador = 0;
    while (contador < /*max_size*/longitud && fscanf(file, "%d", &array[contador]) == 1) { // El tercer argumento (&array[contador]) es la dirección de memoria 
                                                                              // de la posición actual del arreglo array, donde fscanf almacenará el valor leído del archivo.
        contador++;
    }

    



    if (file!= NULL) {
        printf ("Si se pudo abrir");
        fclose(file);
    }else {printf("NO se pudo abrir");}

    



    return contador;


}


void array_dump(int a[], unsigned int length) {
    //your code here!!!

    for (unsigned int i = 0;i<length;i++) {
        printf ("%d",a[i]);
    }


}


int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    printf("Hasta aqui me ejecuto!");
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;     //   O puedo poner 0
}

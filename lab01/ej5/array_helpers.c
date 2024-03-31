 /* First, the standard lib includes, alphabetically ordered */
 #include <assert.h>
 //#include <stdbool.h>     
 #include "array_helpers.h"      
 //#include "mybool.h" No es necesario incluirla porque ya viene de array_helpers.h. Además, en dicho archivo agregué la directiva de "#ifndef...#enfif"
 #include <stdio.h>
 #include <stdlib.h>

//  INCLUYO LOS PROTOTIPOS USANDO LA DIRECTIVA DEL PREPROCESADOR:




unsigned int array_from_file(int array[],
                              unsigned int max_size,
                              const char *filepath) {

     FILE *file = fopen(filepath, "r"); 
    
     unsigned int contador = 0;
     while (contador < max_size && fscanf(file, "%d", &array[contador]) == 1) { 
                                                                               
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

 mybool array_is_sorted(int a[], unsigned int length) {


    mybool ordenado = true;
    for (unsigned int i = 0; i<length;i++) {
        if ((a[i]<=a[i+1]) && ordenado){
            ordenado = true;
        }
    }
    return ordenado;



 }
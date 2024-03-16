#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


#define ARRAY_SIZE 4

void pedirArreglo(int a[], int n_max) {
  int i=0;
  while (i < n_max) {
    printf("Ingrese un elemento %d : \n", i);
    scanf("%d", &a[i]);
    i = i + 1;
  }
}


int pedir_entero() {
  int n;
  printf("Por favor, dame un entero para comparar con el arreglo que ingresaras a continuacion.\n");
  scanf("%d", &n);
  return n;
}



struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};



struct bound_data check_bound(int value, int arr[], unsigned int length) {
    
    struct bound_data resultado;
    resultado.is_upperbound = false;
    resultado.is_lowerbound = false;
    resultado.exists = false;
    resultado.where = 0;

    assert (length>0);
    
    int i=0;
    for (i=0;i<length; i++){
        if (value>=arr[i]){
            resultado.is_upperbound = true;
        }else {
            resultado.is_upperbound = false;
        }
        if (value<=arr[i]) {
            resultado.is_lowerbound=true;
        }else {
            resultado.is_lowerbound = false;
        }
        if (value==arr[i]){
            resultado.exists = true;
            resultado.where = i;
        }

        

    }



    return resultado;
}

int main(void) {
    int arreglo[ARRAY_SIZE] ;   // ={0, -1, 9, 4};
    int value = pedir_entero();
    //
    
    pedirArreglo(arreglo, ARRAY_SIZE);


    //
    struct bound_data result = check_bound(value, arreglo, ARRAY_SIZE);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    printf("Es cota superior  %d.\n", result.is_upperbound); // Imprime 1
    printf("Es cota inferior  %d.\n", result.is_lowerbound); // Imprime 0
    printf("Existe %u.\n", result.exists);        // Imprime 1
    printf("Posicion : %u.\n", result.where);         // Imprime 2

    return EXIT_SUCCESS;
}


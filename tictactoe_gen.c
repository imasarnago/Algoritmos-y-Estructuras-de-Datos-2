#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */
#include <assert.h>  /* assert() */





#define BOARD_LENGTH 4 // El tamaño de nuestro tablero de juego


#define CELL_MAX (4 * 4 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[BOARD_LENGTH][BOARD_LENGTH])
{
    int cell = 0;

    print_sep(4);
    for (int row = 0; row < BOARD_LENGTH; ++row) {
        for (int column = 0; column < BOARD_LENGTH; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(4);
    }
}



bool has_free_cell(char board[BOARD_LENGTH][BOARD_LENGTH])
{
    bool free_cell=true; // Siempre al empezar el juego, tengo celdas libres. Al menos una (?

    int fila = 0;
    int columna = 0;
    int ocupadas = 0;

    while (fila<BOARD_LENGTH && columna<BOARD_LENGTH) {
        if (board[fila][columna] != '-') {
            ocupadas++;
        }

        columna++;
        if (columna == BOARD_LENGTH -1) {
            columna = 0;
            fila++;
        }
    }

    if (ocupadas == BOARD_LENGTH * BOARD_LENGTH -1 ) {
        free_cell = false;
    }
    return free_cell;
}




char get_winner(char board[BOARD_LENGTH][BOARD_LENGTH])
{
    char winner = '-';
    bool ganando = true;
    int fila = 0;
    int columna = 0;
    
    // while (fila < BOARD_LENGTH) {
    //     columna = 0;
    //     while (columna<BOARD_LENGTH){
    //       if (board[fila][columna] == board[fila][columna+1]){

    //       }  
    //     }
    //     fila++;
    // }


    for (unsigned int i = 0; i<BOARD_LENGTH; i ++) {
        //      FILAS 
        for (unsigned int j = 0; j<BOARD_LENGTH; j++){
            ganando = ganando && (board[i][0]== board[i][j]);
        }
        if (ganando){
            winner = board [i][0];
            break;
        }
        
    }
    
    for (unsigned int j = 0; j<BOARD_LENGTH; j ++) {
        //      COLUMNAS
        for (unsigned int i = 0; i<BOARD_LENGTH; i++){
            ganando = ganando && (board[0][j]== board[i][j]);
        }
        if (ganando){
            winner = board [0][j];
            break;
        }
        
    }



    //
    return winner;
    }






int main(void)
{


    char board[BOARD_LENGTH][BOARD_LENGTH] = {
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {

        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_LENGTH;
            int colum = cell % BOARD_LENGTH;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}

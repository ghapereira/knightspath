/*****************************************************************************/
/* @project Knight's Path                                                    */
/* @name    lib.c                                                           */
/* @author  Gustavo H. Alves Pereira                                         */
/* @brief   TODO                                                             */
/* @date    Jan/2019                                                         */
/*****************************************************************************/

#include <stdlib.h>
#include "definitions.h"

void print_success(char *message) {
    printf(BLU "%s\n" RESET, message);
}

void print_error(char *message) {
    printf(RED "%s\n" RESET, message);
}

KPBoard KPallocateBoard() {
    KPBoard board;

    board = (KPBoard) calloc(BOARD_WIDTH, sizeof(KPLine));

    for(uint16_t i = 0; i < BOARD_WIDTH; i++) {
        board[i] = (KPLine) calloc(BOARD_HEIGHT, sizeof(KPSquare));
    }

    return board;
}

void KPfreeBoard(KPBoard board) {
    for(uint16_t i = 0; i < BOARD_WIDTH; i++) {
        free(board[i]);
    }

    free(board);
}

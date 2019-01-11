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

// Assuming board is already allocated
void KPinitializeBoard(KPBoard board) {
    for(uint16_t i = 0; i < BOARD_WIDTH; i++) {
        for(uint16_t j = 0; j < BOARD_HEIGHT; j++) {
            board[i][j] = nonvisited;
        }
    }

    board[INITIAL_POSITION_X][INITIAL_POSITION_Y] = visited;
}

bool KPisValidPosition(uint16_t x, uint16_t y) {
    return x >= 0 && y >= 0 && x < BOARD_WIDTH && y < BOARD_HEIGHT;;
}

int16_t KPnextMove() {
    return -1;
}

static void KPinitializeCoordinates(KPCoordinates * coordinates, uint16_t x, uint16_t y) {
    coordinates->x = x;
    coordinates->y = y;
}

KPGameStructure KPinitializeGame() {
    KPGameStructure game;
    game.board = KPallocateBoard();
    KPinitializeBoard(game.board);
    game.movementList = (KPMovement *)calloc(BOARD_HEIGHT * BOARD_WIDTH, sizeof(KPMovement));

    KPinitializeCoordinates(&game.currentCoordinates, INITIAL_POSITION_X, INITIAL_POSITION_Y);
    game.currentPosition = 0;
    game.movementList[game.currentPosition] = movementA;

    return game;
}

void KPcleanGame(KPGameStructure * game) {
    KPfreeBoard(game->board);
    free(game->movementList);
}

void KPbacktrack(KPGameStructure * game) {
    game->currentPosition = -1;
}

KPGameState KPmakeMove(KPGameStructure * game) {
    // find where we are
    // if the next movement is viable (as marked in the current position), do it
    // while (KPupdateMovement)
    // if not, can we update?
    //  if yes, update
    //  if no, return game infeasible
    // try to make the next move
    return gameInfeasible;
}

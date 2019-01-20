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

bool KPisValidPosition(KPCoordinates coordinates) {
    return coordinates.x >= 0 && coordinates.y >= 0
        && coordinates.x < BOARD_WIDTH && coordinates.y < BOARD_HEIGHT;
}

KPMovement KPnextMove(KPMovement currentMove) {
    return movementA;
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
    /*
    KPMovement currentMovement = game->movementList[game->currentPosition];
    KPCoordinates nextCoordinates;

    while(currentMovement != invalidMovement) {
        nextCoordinates = KPgetNextCoordinates(currentMovement, &game);
        bool isPositionValid = KPisValidPosition(nextCoordinates);
        bool isPositionUnvisited = KPisPositionUnvisited(nextCoordinates, &game);

        if (isPositionValid && isPositionUnvisited) {
            game->currentPosition++;
            if (game->currentPosition == BOARD_SIZE - 1) {
                return gameCompleted;
            }

            // Game still continues
            return gameContinues;
        }

        // update current movement
    }
    */

    // return current state

    return gameInfeasible;
}

#ifndef __DEFINITIONS__
#define __DEFINITIONS__

/*****************************************************************************/
/* @project Knight's Path                                                    */
/* @name    defintions.h                                                     */
/* @author  Gustavo H. Alves Pereira                                         */
/* @brief   Contains  projectwide defintions, constants and types            */
/* @date    Jan/2019                                                         */
/*****************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8
#define BOARD_SIZE (BOARD_WIDTH * BOARD_HEIGHT)

#define INITIAL_POSITION_X 0
#define INITIAL_POSITION_Y 0

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

// Represents a square status of nonvisited/visited
typedef enum KPSquareStatus {
    nonvisited,
    visited
} KPSquareStatus;

// Represents a square on the board
typedef KPSquareStatus KPSquare;

typedef KPSquare* KPLine;
typedef KPSquare** KPBoard;

// Represents possible movements
typedef enum KPMovement {
    movementA,
    movementB,
    movementC,
    movementD,
    movementE,
    movementF,
    movementG,
    movementH,
    invalidMovement
} KPMovement;

typedef struct KPCoordinates {
    uint16_t x;
    uint16_t y;
} KPCoordinates;

// Represents the game instance
typedef struct KPGameStructure {
    KPBoard board;
    KPMovement * movementList;
    // Represents the current position on the movementList
    int16_t currentPosition;
    // Represents the current Knight's coordinates on the game board
    KPCoordinates currentCoordinates;
} KPGameStructure;

typedef enum KPGameState {
    gameCompleted,
    gameInfeasible,
    gameContinues
} KPGameState;

#endif // __DEFINITIONS__

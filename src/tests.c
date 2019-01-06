/*****************************************************************************/
/* @project Knight's Path                                                    */
/* @name    tests.c                                                          */
/* @author  Gustavo H. Alves Pereira                                         */
/* @brief   Run projects tests                                               */
/* @date    Jan/2019                                                         */
/*****************************************************************************/

#include "definitions.h"
#include "lib.h"

uint16_t tests_run = 0;

static char * test_allocate_board() {
    KPBoard board = NULL;
    board = KPallocateBoard();
    mu_assert("error, board not allocated", board != NULL);

    KPfreeBoard(board);
    return 0;
}

static char * test_set_all_board_squares() {
    KPBoard board = KPallocateBoard();

    for (uint16_t i = 0; i < BOARD_WIDTH; i++) {
        for (uint16_t j = 0; i < BOARD_HEIGHT; i++) {
            board[i][j] = nonvisited;
            mu_assert("error, value not correctly set", board[i][j] == nonvisited);
        }
    }

    KPfreeBoard(board);
    return 0;
}

static char * test_board_initialization() {
    KPBoard board = KPallocateBoard();
    KPinitializeBoard(board);

    KPSquare initialPosition = board[INITIAL_POSITION_X][INITIAL_POSITION_Y];

    mu_assert("error, knight not at starting position", initialPosition == visited);

    for (uint16_t i = 0; i < BOARD_WIDTH; i++) {
        for (uint16_t j = 0; i < BOARD_HEIGHT; i++) {
            bool isInitialPosition = i == INITIAL_POSITION_X && j == INITIAL_POSITION_Y;
            if (isInitialPosition) {
                break;
            }
            board[i][j] = nonvisited;
            mu_assert("error, value not correctly set", board[i][j] == nonvisited);
        }
    }

    KPfreeBoard(board);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_allocate_board);
    mu_run_test(test_set_all_board_squares);
    return 0;
}

int main(int argc, char * argv[]) {
    char *result = all_tests();
    if (result != 0) {
        print_error(result);
    } else {
        // printf("ALL TESTS PASSED\n");
        print_success("ALL TESTS PASSED");
    }

    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

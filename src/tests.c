/*****************************************************************************/
/* @project Knight's Path                                                    */
/* @name    tests.c                                                          */
/* @author  Gustavo H. Alves Pereira                                         */
/* @brief   Run projects tests                                               */
/* @date    Jan/2019                                                         */
/*****************************************************************************/

#include "definitions.h"
#include "lib.h"
#include "minunit.h"

uint16_t tests_run = 0;
uint16_t tests_ok = 0;
uint16_t tests_fail = 0;

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
            bool isInitialPosition = (i == INITIAL_POSITION_X) && (j == INITIAL_POSITION_Y);
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

static char * test_valid_position_is_correct() {
    mu_assert("error, valid position shown as invalid", KPisValidPosition(0, 0));
    return 0;
}

static char * test_position_lesser_than_0_should_be_invalid() {
    mu_assert("error, invalid position shown as valid", !KPisValidPosition(-1, -1));
    return 0;
}

static char * test_position_X_above_max_should_be_invalid() {
    mu_assert("error, board position X above max", !KPisValidPosition(BOARD_WIDTH, 0));
    return 0;
}

static char * test_position_Y_above_max_should_be_invalid() {
    mu_assert("error, board position Y above max", !KPisValidPosition(0, BOARD_HEIGHT));
    return 0;
}

static char * test_position_above_max_should_be_invalid() {
    mu_assert("error, board position above max",
              !KPisValidPosition(BOARD_WIDTH, BOARD_HEIGHT));
    return 0;
}

static char * test_fail_condition_cannot_backtrack_more() {
    KPGameStructure game = KPinitializeGame();
    KPbacktrack(&game);
    mu_assert("error, should not be able to backtrack again", game.currentPosition == -1);
    return 0;
}

static char * test_initialize_game() {
    KPGameStructure game = KPinitializeGame();
    mu_assert("error, game not initialized", game.movementList[0] == movementA);
    mu_assert("error, game not initialized", game.currentPosition == 0);
    // TODO clean game
    return 0;
}

static char * test_first_movement_is_D() {
    KPGameStructure game = KPinitializeGame();
    KPtakeMove(&game);
    mu_assert("error, first movement wrong", game.movementList[1] == movementD);
    mu_assert("error, wrong position", game.currentPosition == 1);
}

static char * all_tests() {
    mu_run_test(test_allocate_board);
    mu_run_test(test_set_all_board_squares);
    mu_run_test(test_board_initialization);
    mu_run_test(test_valid_position_is_correct);
    mu_run_test(test_position_lesser_than_0_should_be_invalid);
    mu_run_test(test_position_above_max_should_be_invalid);
    mu_run_test(test_position_X_above_max_should_be_invalid);
    mu_run_test(test_position_Y_above_max_should_be_invalid);
    mu_run_test(test_fail_condition_cannot_backtrack_more);
    mu_run_test(test_initialize_game);
    mu_run_test(test_first_movement_is_D);
    return 0;
}

int main(int argc, char * argv[]) {
    char *result = all_tests();
    if (result != 0) {
        print_error(result);
    } else {
        print_success("ALL TESTS PASSED");
    }

    printf("Tests run: %d\n", tests_run);
    printf("Tests ok: %d\n", tests_ok);
    printf("Tests fail: %d\n", tests_fail);

    return result != 0;
}

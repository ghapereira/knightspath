/*****************************************************************************/
/* @project Knight's Path                                                    */
/* @name    lib.h                                                           */
/* @author  Gustavo H. Alves Pereira                                         */
/* @brief   TODO                                                             */
/* @date    Jan/2019                                                         */
/*****************************************************************************/
void print_error(char *message);
void print_success(char *message);

KPBoard KPallocateBoard();
void KPfreeBoard(KPBoard board);
void KPinitializeBoard(KPBoard board);
bool KPisValidPosition(uint16_t x, uint16_t y);

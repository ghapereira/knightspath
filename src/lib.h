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
bool KPisValidPosition(KPCoordinates coordinates);
int16_t KPnextMove();
KPGameStructure KPinitializeGame();
void KPbacktrack(KPGameStructure * game);
KPGameState KPmakeMove(KPGameStructure * game);
void KPcleanGame(KPGameStructure * game);

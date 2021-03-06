/*****************************************************************************/
/* @project Knight's Path                                                    */
/* @name    minunit.h                                                        */
/* @author  Gustavo H. Alves Pereira; taken from                             */
/*          http://www.jera.com/techinfo/jtns/jtn002.html                    */
/* @brief   Unit testing methods                                             */
/* @date    Jan/2019                                                         */
/*****************************************************************************/
 #define mu_assert(message, test) do { if (!(test)) return message; } while (0)
 #define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) { tests_fail++ ; return message; } \
                                else { tests_ok++ ;  } } while (0)

extern uint16_t tests_run;
extern uint16_t tests_ok;
extern uint16_t tests_fail;

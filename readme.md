# Knight's Path

## Gustavo H. Alves Pereira

### Introduction

The Knight's Path is a traditional computer science problem, usually employed to teach
backtracking. It consists in a chess Knight on a chessboard trying to cover all the squares
on the board from a starting point without stepping more than once at each square. The knight
has a 'L' shaped movement: any valid combination of two squares on the vertical/horizontal
plus one square in the complimentary vertical/horizontal. The following diagram shows it:

      .A.B.         Fig. 1: Possible movements for the Knight (K) on a chessboard
      H...C
      ..K..
      G...D
      .F.E.

From the Knight's starting point at 'K' it can move to the 8 possible points marked as
A, B, ..., H.

### Algorithm

The algorithm I'm going to implement here is really naive. I am going to emulate a knight
starting from the chessboard's top-left corner (in matrix notation, (0,0)) and then trying
to move. Each movement will be registered as the corresponding letter on an array. At each
iteration of the algorithm it will be checked either the next movement is valid within the
board's limits or if it steps on a previously visited square. The next movement always start
trying to go to position 'A' according to Fig. 1, then if not available to 'B', and so on.
If it is already on 'H' and not valid the backtracking step will be activated. The current
movement will be erased from the array and the previous one will be the new current one. It
will be updated and then the algorithm will continue as planned. It has two stopping conditions:

1. When all squares are covered
2. When all possibilites are exhausted

Condition 1 means all squares are checked and the Knight could traverse all board without
needing to repeat a square. Condition 2 means it was impossible to do it.

Programwise, condition 1 is checked simply when the movement array is fully covered, and
condition 2 when in the first position the program tries to go to a movement after 'H'.


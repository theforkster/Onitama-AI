#include "AttackTables.h"

unsigned int AttackTables::getAttackFromSquare(unsigned int attack, int square) {

    // the middle square
    int middle = 12;
    int middleRow = 2;
    int middleCol = 2;

    int squareRow = square / 5;
    int squareCol = square % 5;


    // loop through the attack bits


    unsigned int newAttack = 0;

    while (attack) {
        int index = get_LS1B_index(attack);

        // calculate relative difference from bit to middle before moving

        int indexRow = index / 5;
        int indexCol = index % 5;

        int relativeRowDifferenceBefore = indexRow - middleRow;
        int relativeColDiffrenceBefore = indexCol - middleCol;


        // calcuate new index
        int newIndex = index - (middle - square);

        // calculate relative difference from bit to middle after moving

        int newIndexRow = newIndex / 5;
        int newIndexCol = newIndex % 5;

        int relativeRowDifferenceAfter = newIndexRow - squareRow;
        int relativeColDiffrenceAfter = newIndexCol - squareCol;


        // check if differences ar ethe same
        if (relativeRowDifferenceBefore == relativeRowDifferenceAfter
            && relativeColDiffrenceBefore == relativeColDiffrenceAfter )
        {
            if (newIndex <= 24) {
                set_bit(newAttack, newIndex);
            }
            
        }


        clear_bit(attack, index);
    }

    return newAttack;
}

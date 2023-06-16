#include <iostream>

#include "defs.h"
#include "helper.h"
#include "AttackTables.h"

int main() {

    //AttackTables tables;



    std::vector <std::vector <int> > vectorBitboard = rotateMatrix180(bitboardTo2DVector(attackCards[0]));

    unsigned int myRotatedBitboard = matrix2DToBitboard(vectorBitboard);

    PrintBitboard(myRotatedBitboard);


    return 0;
}

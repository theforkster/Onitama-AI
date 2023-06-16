#include <iostream>

#include "defs.h"
#include "helper.h"

int main()
{

    unsigned int test_board1 = 0;
    set_bit(test_board1, c4);
    set_bit(test_board1, a4);
    set_bit(test_board1, d2);
    set_bit(test_board1, e5);

    PrintBitboard(test_board1);

    unsigned int test_board2 = 0;
    set_bit(test_board2, c4);
    set_bit(test_board2, a4);
    set_bit(test_board2, d1);
    set_bit(test_board2, e3);

    PrintBitboard(test_board2);


    return 0;
}

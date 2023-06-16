#pragma once
#include <iostream>
#include "defs.h"
#include <vector>

void PrintBitboard(unsigned int bitboard);

std::vector <std::vector <int> > bitboardTo2DVector(unsigned int bitboard);

std::vector <std::vector <int> > rotateMatrix180(const std::vector <std::vector <int> >& matrix);

unsigned int matrix2DToBitboard(const std::vector <std::vector <int> >& matrix);

unsigned int rotateBitboard180(unsigned int bitboard);


inline int countBits(unsigned int bitboard)
{
	int count = 0;

	// clear LSB and count
	while (bitboard)
	{
		count++;
		bitboard &= bitboard - 1;
	}
	return count;
}



static const int index32[32] =
{
   0, 9, 1, 10, 13, 21, 2, 29, 11, 14, 16, 18, 22, 25, 3, 30,
  8, 12, 20, 28, 15, 17, 24, 7, 19, 27, 23, 6, 26, 5, 4, 31
};

// get least significant 1st bit index
inline int get_LS1B_index(unsigned int bitboard)
{
	// make sure bitboard is not equal to zero
	if (bitboard)
	{
		// count trailing bits before LS1B
		const unsigned int debruijn32 = (0x07C4ACDDU);

		bitboard |= bitboard >> 1; // first round down to one less than a power of 2 
		bitboard |= bitboard >> 2;
		bitboard |= bitboard >> 4;
		bitboard |= bitboard >> 8;
		bitboard |= bitboard >> 16;
		return index32[(bitboard * debruijn32) >> 27];
		//return countBits((bitboard & ((unsigned long long)0-bitboard)) - 1);
	}
	else
	{
		// return illegal index
		return -1;
	}
}



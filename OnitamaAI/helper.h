#pragma once
#include <iostream>
#include "defs.h"

void PrintBitboard(unsigned int bitboard) {
	// loop through bitboard
	std::cout << "Printing Board\n" << std::endl;
	for (int row = 4; row >= 0; row--) {

		std::cout << row + 1 << "   ";

		for (int col = 0; col < 5; col++) {
			// calculate sqare
			int square = row * 5 + col;

			// if bit exists at the square
			if (get_bit(bitboard, square)) {
				std::cout << "1 ";
			}
			else {
				std::cout << "0 ";
			}
		}

		std::cout << std::endl;
	}

	std::cout << "\n    A B C D E" << std::endl;
	std::cout << std::hex << "\n   Hex: 0x" << bitboard << std::dec << std::endl;

	std::cout << std::endl;
	std::cout << "Ending Printing Board" << std::endl;
}
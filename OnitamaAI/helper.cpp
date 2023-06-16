#include "helper.h"

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

std::vector<std::vector<int>> bitboardTo2DVector(unsigned int bitboard) {
	std::vector< std::vector <int> > myVector = {};

	for (int row = 0; row < 5; row++) {

		std::vector <int> myRow = {};

		for (int col = 0; col < 5; col++) {

			int index = row * 5 + col;

			if (get_bit(bitboard, index)) {
				myRow.push_back(1);
			} else {
				myRow.push_back(0);
			}
		}

		myVector.push_back(myRow);
	}

	return myVector;
}

std::vector<std::vector<int>> rotateMatrix180(const std::vector<std::vector<int>>& matrix) {
	std::vector< std::vector <int> > myVector = {};

	for (int row = 0; row < 5; row++) {

		std::vector <int> myRow = matrix[4-row];

		std::reverse(myRow.begin(), myRow.end());

		myVector.push_back(myRow);
	}

	return myVector;

}

unsigned int matrix2DToBitboard(const std::vector<std::vector<int>>& matrix) {

	unsigned int bitboard = 0;

	for (int row = 0; row < 5; row++) {

		for (int col = 0; col < 5; col++) {

			int index = row * 5 + col;

			if (matrix[row][col] == 1) {
				set_bit(bitboard, index);
			}
		}
	}

	return bitboard;
}

unsigned int rotateBitboard180(unsigned int bitboard)
{
	std::vector <std::vector <int> > vectorBitboard = rotateMatrix180(bitboardTo2DVector(bitboard));

	unsigned int myRotatedBitboard = matrix2DToBitboard(vectorBitboard);

	return myRotatedBitboard;

}


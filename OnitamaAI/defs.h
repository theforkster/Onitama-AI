#pragma once

//bit macros
#define get_bit(bitboard, square) ((bitboard) & ((unsigned int)1 << (square)))
#define set_bit(bitboard, square) ((bitboard) |= ((unsigned int)1 << (square)))
#define clear_bit(bitboard, square) ((bitboard) &= ~((unsigned int)1 << (square)))



enum {
	a1, b1, c1, d1, e1,
	a2, b2, c2, d2, e2,
	a3, b3, c3, d3, e3,
	a4, b4, c4, d4, e4,
	a5, b5, c5, d5, e5,
	noSquare
};
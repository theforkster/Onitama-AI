#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "helper.h"

const std::vector<unsigned int> attackCards {
	0x50080,
	0xa00004,
	0x24400,
	0x4540,
	0x88140
};

const std::vector<std::string> attackCardNames {
	"Mantis",
	"Kirin",
	"Crab",
	"Turtle",
	"Dragon",
};





class AttackTables {
public:
	unsigned int getAttackFromSquare(unsigned int attack, int square);



};


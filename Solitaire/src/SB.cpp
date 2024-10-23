//============================================================================
// Name        : SB.cpp
// Author      : Alessandro S.
// Version     :
// Copyright   : D.A.S.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "classes/SolitaireAlgo.h"


int main(/*int argc, char **argv*/) {
	cout << "main - begin" << std::endl;
	Board board;
	SolitaireAlgo logic;
	std::cout << "main - search" << std::endl;
	logic.search(board);
	std::cout << "main - end" << std::endl;
	return 0;
}

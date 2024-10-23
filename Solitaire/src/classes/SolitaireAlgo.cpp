/*
 * SolitaireAlgo.cpp
 *
 *  Created on: 9 oct. 2023
 *      Author: salsettia
 */

#include "SolitaireAlgo.h"
#include <iostream>
using namespace std;

static int solution = 0;
static int solution_central = 0;


SolitaireAlgo:: SolitaireAlgo() {

}


SolitaireAlgo::~SolitaireAlgo() {

}


#define TRY_AND_SET(dir) \
if ( board.dir(pawn.start.x, pawn.start.y) ) { \
	pawn.dir(pawn.start.x, pawn.start.y); \
	Board board2(board, pawn); \
	if ( search(board2, movements+1) ) { \
		board.display(movements, &pawn); \
		return true; \
	} \
}

/**
 * @brief SolitaireAlgo::search
 *
 * @param board: board to explore
 * @param movements: number of movements so far.
 *
 * @result true if solution find and must stop, false is max movement reached but must continue searching
 *
 * @detail The function parses the board per brute force: all the position and for all pawn, the for directions.
 * @detail If a pawn movement is possible, the recursive call is done.
 */
bool SolitaireAlgo::search(const Board& board, int movements) const {
	if ( movements == Max_moves ) {
		cout << "Solution n°" << ++solution << endl;
		if ( board.get_position_state(4, 4) == 1) return false; // true: continue, false = stop, solution with pawn in the middle
		cout << "Central solution n°" << ++solution_central << endl;
		board.display(movements);
		return true; // stop
	}
	t_move pawn;
	for ( pawn.start.y = BorderMin; pawn.start.y < BorderMax ; pawn.start.y++ )
		for ( pawn.start.x = BorderMin; pawn.start.x < BorderMax ; pawn.start.x++ )
			if ( board.get_position_state(pawn.start.x, pawn.start.y) == Positions::busy ) {
/*				for ( int dir = Directions::up; dir <= Directions::left; dir++ )
					if ( board.is_move(dir, x, y) ) {
						(pawn.*pawn.set_move[dir])(x, y);
						Board board2(board, pawn);
						if ( search(board2, movements+1) ) {
							board.display(movements, &pawn);
							return true; // stop
						}
					}*/
				TRY_AND_SET(up);
				TRY_AND_SET(right);
				TRY_AND_SET(down);
				TRY_AND_SET(left);
			}
	return false; // continue
}


/*
 * Board.cpp
 *
 *  Created on: 9 oct. 2023
 *      Author: salsettia
 */

#include <iostream>
using namespace std;
#include <string.h>
#include "board.h"


/**
 * @brief Board::Board
 *
 * @detail: Initiate the board with the initial board
 */
Board::Board() {
//	std::copy((int*)board_init, (int*)board_init + BoardMax * BoardMax, (int*)board_status);
	memcpy(board_status, board_init, sizeof(int) * BoardMax * BoardMax );
}


/**
 * @brief Board::Board
 *
 * @param[in] board: board to be copied
 * @param[in] pawn: movement to adapt this board with
 *
 * @detail: Initiate the board with the initial board
 */
Board::Board(const Board& board, const t_move& pawn) {
//	std::copy((int*)board.get_board(), (int*)board.get_board() + BoardMax * BoardMax, (int*)board_status); // slower
	memcpy(board_status, board.get_board(), sizeof(int) * BoardMax * BoardMax );
	board_status[pawn.start.y][pawn.start.x] = Positions::empty;
	board_status[pawn.end.y][pawn.end.x] = Positions::busy;
	board_status[pawn.mid.y][pawn.mid.x] = Positions::empty;
}


Board::~Board() {
	// TODO Auto-generated destructor stub
}


/**
 * @Brief Board::display
 *
 * @param[in] move_num: which movement number (max 31)
 * @param[in] pawn_move: next pawn movement
 *
 * @Detail Display the board in the console and the next movement if any.
 */
void Board::display(int move_num, const t_move* pawn_move) const {
	cout << "movement n°" << move_num;
	if ( pawn_move )
		cout << " | from: (" << pawn_move->start.x << "," << pawn_move->start.y << "), "
			 << "to: (" << pawn_move->end.x << "," << pawn_move->end.y << "), "
			 << "removing: (" << pawn_move->mid.x << "," << pawn_move->mid.y << ")." << endl;
	for ( int y = BorderMin; y < BorderMax; y++ ) {
		for ( int x = BorderMin; x < BorderMax; x++ )
			cout << board_status[y][x];
		cout << endl;
	}
	cout << endl;
}

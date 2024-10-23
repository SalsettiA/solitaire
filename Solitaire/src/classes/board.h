/*
 * Board.h
 *
 *  Created on: 9 oct. 2023
 *      Author: salsettia
 */

#ifndef BOARD_H_
#define BOARD_H_

/**
 * board
 * 0: invalid
 * 1: valid empty
 * 2: valid occupied
 */
const int BoardMax = 9;
const int BorderMax = BoardMax-1;
const int BoardMin = 0;
const int BorderMin = BoardMin+1;
const int Pawns = 3*7 + 2*3*2 - 1;
const int Max_moves = Pawns-1;


typedef int t_board[BoardMax][BoardMax];
enum Positions {invalid = 0, empty, busy};

const t_board board_init = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 2, 2, 2, 0, 0, 0},
		{0, 0, 0, 2, 2, 2, 0, 0, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 2, 2, 2, 1, 2, 2, 2, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 0, 0, 2, 2, 2, 0, 0, 0},
		{0, 0, 0, 2, 2, 2, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0}
};

struct t_point { int x = 0, y = 0; };
/*struct t_move;
 typedef void (t_move::*t_move_dir)(int, int);
 enum Directions {up = 0, right, down, left}; */

struct t_move {
	t_point start, end, mid;

	void    up(int x, int y) { end = {x, y-2}; mid = {x, y-1}; }
	void right(int x, int y) { end = {x+2, y}; mid = {x+1,  y}; }
	void  down(int x, int y) { end = {x, y+2}; mid = {x, y+1}; }
	void  left(int x, int y) { end = {x-2, y}; mid = {x-1, y}; }

//	t_move_dir set_move[4] = {&t_move::up, &t_move::right, &t_move::down, &t_move::left}; // must be the same as Directions

};


/*class Board;
typedef bool (Board::*t_board_dir)(int, int) const;*/

class Board {
public:

	Board();
	Board(const Board& board, const t_move& pawn);
	virtual ~Board();

	void display(int move_num = 0, const t_move* pawn_move = nullptr) const;
	const t_board& get_board() const { return board_status; }
	const int& get_position_state(int x, int y) const { return board_status[y][x]; }
	bool    up(int x, int y) const { return (board_status[y-1][x]   == Positions::busy) && (board_status[y-2][x]   == Positions::empty); }
	bool right(int x, int y) const { return (board_status[y]  [x+1] == Positions::busy) && (board_status[y]  [x+2] == Positions::empty); }
	bool  down(int x, int y) const { return (board_status[y+1][x]   == Positions::busy) && (board_status[y+2][x]   == Positions::empty); }
	bool  left(int x, int y) const { return (board_status[y]  [x-1] == Positions::busy) && (board_status[y]  [x-2] == Positions::empty); }

private:
//	t_board_dir test_direction[4] = {&Board::up, &Board::right, &Board::down, &Board::left}; // must be the same as Directions
public:
//	bool is_move(int d, int x, int y) const { return (this->*test_direction[d])(x, y); }

private:
	t_board board_status;
};


#endif /* BOARD_H_ */

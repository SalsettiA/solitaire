/*
 * SolitaireAlgo.h
 *
 *  Created on: 9 oct. 2023
 *      Author: salsettia
 */

#ifndef CLASSES_SOLITAIREALGO_H_
#define CLASSES_SOLITAIREALGO_H_

#include "board.h"

class SolitaireAlgo {
public:
	SolitaireAlgo();
	virtual ~SolitaireAlgo();
	bool search(const Board& board, int movements = 0) const;
};

#endif /* CLASSES_SOLITAIREALGO_H_ */

#pragma once

#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(Point loc, char type) : Piece(loc, type) {};

	~Bishop() = default;

	virtual int checkPieceMovement(Point& src, Point& dst, Piece* board[][8]) override; //checks if movement is legal - piece specific

	virtual bool checkIfDiagonalNeeded(Point* src, Point* dst) const override;

private:

};
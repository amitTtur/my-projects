#pragma once

#include "Piece.h"

class King : public Piece
{
public:
	King(Point loc, char type) : Piece(loc, type) {};

	~King() = default;

	virtual int checkPieceMovement(Point& src, Point& dst, Piece* board[][8]) override; //checks if movement is legal - piece specific

	virtual bool checkIfVerticalNeeded(Point* src, Point* dst) const override;
	virtual bool checkIfDiagonalNeeded(Point* src, Point* dst) const override;
	virtual bool checkIfHorizontalNeeded(Point* src, Point* dst) const override;

private:

};
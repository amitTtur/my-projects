#pragma once

#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Point loc, char type);

	~Pawn() = default;

	virtual int checkPieceMovement(Point& src, Point& dst, Piece* board[][8]) override; //checks if movement is legal - piece specific

	virtual bool checkIfVerticalNeeded(Point* src, Point* dst) const override;
	virtual bool checkIfDiagonalNeeded(Point* src, Point* dst) const override;

private:
	bool movedDouble;
};
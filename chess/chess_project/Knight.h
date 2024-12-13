#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(Point loc, char type) : Piece(loc, type) {};
	~Knight() = default;

	virtual int checkPieceMovement(Point& src, Point& dst, Piece* board[][8]) override; //checks if movement is legal - piece specific

private:

};
#pragma once
#ifndef PIECE_H
#define PIECE_H

#include "Point.h"
#include "Game.h"

class Game;

class Piece
{
public:
	Piece();
	Piece(Point loc, char type);
	~Piece();

	char getType() const;
	Point* getLoc();

	virtual int checkPieceMovement(Point& src, Point& dst, Piece* board[8][8]); //checks if movement is legal - piece specific

	virtual int checkPathClear(const Game* game, Point* dst) const;

	virtual bool checkIfVerticalNeeded( Point* src, Point* dst) const;
	virtual bool checkIfDiagonalNeeded( Point* src, Point* dst) const;
	virtual bool checkIfHorizontalNeeded( Point* src, Point* dst) const;

	friend std::ostream& operator<<(std::ostream& os, const Piece& v);

	bool checkPieceOwnership();

	void changeLoc(const Point s1);
	
protected:
	Point* _location;
private:
	char _type; 
	/*
	king k
	queen q
	rook r
	knight n
	bishop b
	pawn p
	UPPERCASE = black
	lowecase = white
	*/
};


#endif

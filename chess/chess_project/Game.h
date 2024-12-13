#pragma once
#ifndef GAME_H
#define GAME_H

#define BOARD_LEN 8

#include "Piece.h"

class Piece;

class Game
{
public:
	Game(const bool startingPlayer);
	~Game();

	void gameSet();
	int turn();
	void filpTurn();

	std::string getBoardView() const;
	int convertTextToPoint(std::string input);

	void movePiece();
	int checkWorldMovement() const;
	bool checkClearPathSelfCheck(Point* src, Point* dest);
	bool checkClearPathCheck(Point* src, Point* dest);

	friend std::ostream& operator<<(std::ostream& os, const Game& v);

	static bool checkHorizontal(Point* src, Point* dest); // checks if movement is horizontal
	static bool checkVertical(Point* src, Point* dest); //checks if movement is vertical
	static bool checkDiagnal(Point* src, Point* dest); //checks if movement is diagnal

	//the return value is a reference but dont change it point value
	//piece location can only be changed in the 'move' function!!!!!
	Point* getThisTurnKingLoc() const;

	int checkSelfCheck();
	int checkVerticalClear(Point* src, Point* dst) const;
	int checkDiagonalClear(Point* src, Point* dst) const;
	int checkHorizontalClear(Point* src, Point* dst) const;

	std::string translateBoardToString();

	bool checkCheck();

	Point* getOpponentKingLoc() const;

	bool checkKingEatsKing(Point* src, Point* dst) const;

	bool checkIfPawnChecks(Point* dst) const;

private:
	Point* _dest;
	Point* _src;

	Piece* _board[BOARD_LEN][BOARD_LEN];

	bool _turn; // 0 - white turn, 1- black turn;

	bool _isInCheck;
};

#endif
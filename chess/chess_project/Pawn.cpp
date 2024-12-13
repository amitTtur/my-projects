#include "Pawn.h"

Pawn::Pawn(Point loc, char type) : Piece(loc, type)
{
	movedDouble = false;
}

int Pawn::checkPieceMovement(Point& src, Point& dst, Piece* board[][8])
{

	if (checkPieceOwnership())
	{
		//black - normal movement
		if (checkIfVerticalNeeded(&src, &dst) &&
			src.getY() < dst.getY() &&
			!board[dst.getY()][dst.getX()] &&
			((!movedDouble && abs(int(src.getY() - dst.getY())) <= 2) ||
				(movedDouble && abs(int(src.getY() - dst.getY())) == 1)))
		{
			movedDouble = true;
			return 0;
		}
	}
	else
	{
		//white
		if (checkIfVerticalNeeded(&src, &dst) &&
			src.getY() > dst.getY() &&
			!board[dst.getY()][dst.getX()] &&
			((!movedDouble && abs(int(src.getY() - dst.getY())) <= 2) ||
				(movedDouble && abs(int(src.getY() - dst.getY())) == 1)))
		{
			movedDouble = true;
			return 0;
		}
	}

	//for eating diagnally
	if (checkIfDiagonalNeeded(&src, &dst))
	{
		if (checkPieceOwnership())
		{
			//black
			if (src.getY() - dst.getY() == -1 && board[dst.getY()][dst.getX()] &&
				!board[dst.getY()][dst.getX()]->checkPieceOwnership())
			{
				movedDouble = true;
				return 0;
			}
		}
		else
		{
			//white
			if (src.getY() - dst.getY() == 1 && board[dst.getY()][dst.getX()] &&
				board[dst.getY()][dst.getX()]->checkPieceOwnership())
			{
				movedDouble = true;
				return 0;
			}
		}
	}


    return 6; //TODO
}

bool Pawn::checkIfVerticalNeeded(Point* src, Point* dst) const
{
    return Game::checkVertical(src,dst);
}

bool Pawn::checkIfDiagonalNeeded(Point* src, Point* dst) const
{
	return Game::checkDiagnal(src, dst);
}
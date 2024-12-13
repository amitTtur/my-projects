#include "King.h"

int King::checkPieceMovement(Point& src, Point& dst, Piece* board[][8])
{
	if (src.getX() - dst.getX() == 0)
	{
		if ((src.getY() - dst.getY() == 1) || (src.getY() - dst.getY() == -1))
		{
			return 0;
		}
	}
	if (src.getY() - dst.getY() == 0)
	{
		if ((src.getX() - dst.getX() == 1) || (src.getX() - dst.getX() == -1))
		{
			return 0;
		}
	}
	if (((src.getY() - dst.getY() == 1) || (src.getY() - dst.getY() == -1)) && ((src.getX() - dst.getX() == 1) || (src.getX() - dst.getX() == -1)))
	{
		return 0;
	}
	return 6;
}

bool King::checkIfVerticalNeeded(Point* src, Point* dst) const
{
    return Game::checkVertical(src,dst);
}

bool King::checkIfDiagonalNeeded(Point* src, Point* dst) const
{
    return Game::checkDiagnal(src,dst);
}

bool King::checkIfHorizontalNeeded(Point* src, Point* dst) const
{
    return Game::checkHorizontal(src,dst);
}

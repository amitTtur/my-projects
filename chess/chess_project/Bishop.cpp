#include "Bishop.h"

int Bishop::checkPieceMovement(Point& src, Point& dst, Piece* board[][8])
{
	int sx = src.getX(), sy = src.getY(), dx = dst.getX(), dy = dst.getY();
	if (checkIfDiagonalNeeded(&src, &dst))
	{
		int dxSign = (dx > sx) ? 1 : -1;
		int dySign = (dy > sy) ? 1 : -1;

		int currX = sx + dxSign;
		int currY = sy + dySign;

		for (int i = 0; i < abs(dx - sx) - 1; i++)
		{
			if (board[currY][currX] != nullptr) {
				if (*(board[currY][currX]->getLoc()) == src || *(board[currY][currX]->getLoc()) == dst)
				{
					return 0;
				}
				else {
					return 6; // There is a piece in between src and dst
				}
			}
			currX += dxSign;
			currY += dySign;
		}
		return 0;
	}
	else
	{
		return 6;
	}
	return 0;
}

bool Bishop::checkIfDiagonalNeeded(Point* src, Point* dst) const
{
	return Game::checkDiagnal(src,dst);
}
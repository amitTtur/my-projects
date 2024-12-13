#include "Rook.h"

int Rook::checkPieceMovement(Point& src, Point& dst, Piece* board[][8])
{
	int sx = src.getX(), sy = src.getY(), dx = dst.getX(), dy = dst.getY();
	bool metOne = false;

	if (checkIfHorizontalNeeded(&src, &dst))
	{
		for (int i = 0; i < 8; i++)
		{
			if (board[sy][i] != NULL)
			{
				if (*(board[sy][i]->getLoc()) == src || *(board[sy][i]->getLoc()) == dst)
				{
					if (metOne == true) // means that no pieces are inbetween src and dst
					{
						return 0;
					}
					else
					{
						metOne = true;
					}
				}
				else if (metOne == true)
				{
					return 6; //means thre is a piece inbetween them
				}
			}
			else if ((sy == dst.getY()) && (i == dst.getX()))
			{
				if (metOne == true)
				{
					return 0;
				}
				else
				{
					metOne = true;
				}
			}
		}
		return 0;
	}
	else if (checkIfVerticalNeeded(&src, &dst))
	{
		for (int i = 0; i < 8; i++)
		{
			if (board[i][sx] != NULL)
			{
				if (*(board[i][sx]->getLoc()) == src || *(board[i][sx]->getLoc()) == dst)
				{
					if (metOne == true) // means that no pieces are inbetween src and dst
					{
						return 0;
					}
					else
					{
						metOne = true;
					}
				}
				else if (metOne == true)
				{
					return 6; //means there is a piece inbetween them
				}
			}
			else if ((i == dst.getY()) && (sx == dst.getX()))
			{
				if (metOne == true)
				{
					return 0;
				}
				else
				{
					metOne = true;
				}
			}
		}
	}
	return 6;
}


bool Rook::checkIfVerticalNeeded(Point* src,Point* dst) const
{
    return Game::checkVertical(src, dst);
}

bool Rook::checkIfHorizontalNeeded(Point* src, Point* dst) const
{
    return Game::checkHorizontal(src,dst);
}



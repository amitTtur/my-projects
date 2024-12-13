#include "Game.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include <cmath>

Game::Game(const bool startingPlayer)
{
	this->_turn = startingPlayer;
	this->_isInCheck = false;
	this->_dest = new Point("a1"); // setting default
	this->_src = new Point("a1"); // setting default
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			_board[i][j] = NULL;
		}
	}

	//TODO initate the _board object after finishing Piece class.s
	gameSet();
}

Game::~Game()
{
	delete this->_dest;
	delete this->_src;

	//TODO add _board destractor as well
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (this->_board[i][j] != NULL)
			{
				delete this->_board[i][j];
				_board[i][j] = nullptr;
			}
		}
	}
}

int Game::turn()
{
	int checkFlag = 0;

	checkFlag = checkWorldMovement();
	checkFlag = (checkFlag == 0) ? _board[_src->getY()][_src->getX()]->checkPieceMovement(*_src, *_dest, _board) : checkFlag;
	if (checkFlag == 0) // if move is a valid move
	{
		Piece* dstSaver = this->_board[this->_dest->getY()][this->_dest->getX()]; //saving dest values
		if (dstSaver && (dstSaver->getType() == 'K' || dstSaver->getType() == 'k'))
		{
			return 6;
		}
		this->_board[this->_dest->getY()][this->_dest->getX()] = this->_board[this->_src->getY()][this->_src->getX()]; //dest = src
		this->_board[this->_src->getY()][this->_src->getX()] = NULL; //removing the src piece of its original place
		this->_board[this->_dest->getY()][this->_dest->getX()]->changeLoc(*(this->_dest));

		if (checkSelfCheck() == 4)
		{
			//returning the board to its original form before the move
			this->_board[this->_src->getY()][this->_src->getX()] = this->_board[this->_dest->getY()][this->_dest->getX()]; // src = dest
			this->_board[this->_dest->getY()][this->_dest->getX()] = dstSaver;
			this->_board[this->_src->getY()][this->_src->getX()]->changeLoc(*(this->_src));

			return 4; //means the move made a self check
		}
		this->_isInCheck = false;
		
		if (checkCheck())//add checker here
		{
			this->_isInCheck = true;
		}
		

		if (dstSaver != NULL)
		{
			delete dstSaver;
		}

		filpTurn();
		return _isInCheck;
		
	}
	return checkFlag;
}

void Game::gameSet()
{
	//SETS UP THE BOARD
	// UPPER = white, lower = black
	Point s1 = Point("a1");
	
	//rooks 
	{
		s1.setLocation("a1");
		this->_board[s1.getY()][s1.getX()] = new Rook(s1, 'R');

		s1.setLocation("a8");
		this->_board[s1.getY()][s1.getX()] = new Rook(s1, 'r');

		s1.setLocation("h1");
		this->_board[s1.getY()][s1.getX()] = new Rook(s1, 'R');

		s1.setLocation("h8");
		this->_board[s1.getY()][s1.getX()] = new Rook(s1, 'r');
	}
	//knights 
	{
		s1.setLocation("b1");
		this->_board[s1.getY()][s1.getX()] = new Knight(s1, 'N');

		s1.setLocation("b8");
		this->_board[s1.getY()][s1.getX()] = new Knight(s1, 'n');

		s1.setLocation("g1");
		this->_board[s1.getY()][s1.getX()] = new Knight(s1, 'N');

		s1.setLocation("g8");
		this->_board[s1.getY()][s1.getX()] = new Knight(s1, 'n');
	}
	//bishops
	{
		s1.setLocation("c1");
		this->_board[s1.getY()][s1.getX()] = new Bishop(s1, 'B');

		s1.setLocation("c8");
		this->_board[s1.getY()][s1.getX()] = new Bishop(s1, 'b');

		s1.setLocation("f1");
		this->_board[s1.getY()][s1.getX()] = new Bishop(s1, 'B');

		s1.setLocation("f8");
		this->_board[s1.getY()][s1.getX()] = new Bishop(s1, 'b');
	}
	//queens
	{
		s1.setLocation("d1");
		this->_board[s1.getY()][s1.getX()] = new Queen(s1, 'Q');

		s1.setLocation("d8");
		this->_board[s1.getY()][s1.getX()] = new Queen(s1, 'q');
	}
	//kings
	{
		s1.setLocation("e1");
		this->_board[s1.getY()][s1.getX()] = new King(s1, 'K');

		s1.setLocation("e8");
		this->_board[s1.getY()][s1.getX()] = new King(s1, 'k');
	}
	//white pawns
	int i;
	std::string tmp = "";
	for (i = 0; i < 8; i++)
	{
		tmp = char(i + 97);
		tmp += "2";
		s1.setLocation(tmp);
		this->_board[1][i] = new Pawn(s1, 'p');
	}
	//Black pawns
	for (i = 0; i < 8; i++)
	{
		tmp = char(i + 97);
		tmp += "7";
		s1.setLocation(tmp);
		this->_board[6][i] = new Pawn(s1, 'P');
	}

}

std::string Game::getBoardView() const
{
	std::string returnStr = "";
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (this->_board[i][j] == NULL)
			{
				returnStr += "#|";
			}
			else
			{
				returnStr += this->_board[i][j]->getType();
				returnStr += "|";
			}
		}
		returnStr.pop_back();
		if (i + 1 != 8)
		{
			returnStr += "\n---------------\n";
		}
	}
	return returnStr;
}

void Game::filpTurn()
{
	this->_turn = !this->_turn;
}

int Game::convertTextToPoint(std::string input)
{
	if (input.size() != 4)
	{
		return -1; //GUI is weird
	}

	size_t arr[4] = { 0 };

	arr[0] = int(input[0]) - 97;
	arr[1] = 7 - (int(input[1]) - 49);
	arr[2] = int(input[2]) - 97;
	arr[3] = 7 - (int(input[3]) - 49);

	this->_src->setLocation(arr[0], arr[1]);
	this->_dest->setLocation(arr[2], arr[3]);

	return 0;
}

std::ostream& operator<<(std::ostream& os, const Game& v)
{
	os << "The current board looks like this: \n" << v.getBoardView() << std::endl;
	return os;
}

int Game::checkWorldMovement() const
{
	Piece* srcOnBoard = _board[_src->getY()][_src->getX()];
	Piece* dstOnBoard = _board[_dest->getY()][_dest->getX()];

	//check if src and dest are not the same  - otherwise return 7
	if (_src == _dest)
	{
		return 7;
	}

	//check if there is a piece in src - otherwise return 2
	//check if piece is owned by the player whose turn it is  - otherwise return 2
	if (!srcOnBoard || srcOnBoard->checkPieceOwnership() != _turn)
	{
		return 2;
	}

	//check if movement is not off board  - otherwise return 5
	if (_src->getX() < 0 || _src->getX() > 7 || _src->getY() <  0 || _src->getY() > 7 ||
		_dest->getX() < 0 || _dest->getX() > 7 || _dest->getY() <  0 || _dest->getY() > 7)
	{
		return 5;
	}

	//check if there is no piece of the same color in dest  - otherwise return 3
	if (dstOnBoard != NULL && dstOnBoard->checkPieceOwnership() == _turn)
	{
		return 3;
	}

	return 0;
}

bool Game::checkHorizontal(Point* src, Point* dest) 
{
	return src->getY() == dest->getY();
}

bool Game::checkVertical(Point* src, Point* dest) 
{
	return src->getX() == dest->getX();
}

bool Game::checkDiagnal(Point* src, Point* dest) 
{
	return abs(int(src->getX() - dest->getX())) == abs(int(src->getY() - dest->getY()));
}

Point* Game::getThisTurnKingLoc() const
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((this->_board[i][j] !=NULL) && (this->_board[i][j]->getType() == 'K' || this->_board[i][j]->getType() == 'k')&& this->_board[i][j]->checkPieceOwnership() == this->_turn)
			{
				return this->_board[i][j]->getLoc();
			}
		}
		
	}
}

int Game::checkSelfCheck()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (_board[i][j] && _board[i][j]->checkPieceOwnership() == !_turn)
			{
				if (checkClearPathSelfCheck(_board[i][j]->getLoc(), getThisTurnKingLoc())) // means the path to the king is without any disturbance
				{
					return 4;
				}
			}
		}
	}
	return 0;
}

bool Game::checkClearPathSelfCheck(Point* src, Point* dest)
{
	//check which piece we are talking about and what direction they have to move in
	//check if movement in chosen direction from src to dest works
	Piece* tmp = this->_board[src->getY()][src->getX()];
	if (tmp == NULL)
	{
		return false;
	}
	else if (tmp->getType() == 'K' || tmp->getType() == 'k')
	{
		return !checkKingEatsKing(src, dest);
	}
	else if (tmp->getType() == 'P' || tmp->getType() == 'p')
	{
		return checkIfPawnChecks(src);
	}
	else if (tmp->checkIfDiagonalNeeded(src, dest))
	{
		return !checkDiagonalClear(src, dest);
	}
	else if (tmp->checkIfHorizontalNeeded(src,dest))
	{
		return !checkHorizontalClear(src,dest);
	}
	else if (tmp->checkIfVerticalNeeded(src, dest))
	{
		return !checkVerticalClear(src, dest);
	}
	else if (tmp->getType() == 'N' || tmp->getType() == 'n')
	{
		return !tmp->checkPieceMovement(*src,*dest,_board);
	}
	return false;
}

bool Game::checkClearPathCheck(Point* src, Point* dest)
{
	//check whitch piece we are talking about and what direction they have to move in
	//check if movement in chosen direction from src to dest works
	Piece* tmp = this->_board[src->getY()][src->getX()];
	if (tmp == NULL)
	{
		return false;
	}
	if (tmp->getType() == 'K' || tmp->getType() == 'k')
	{
		return false;
	}
	else if (tmp->getType() == 'P' || tmp->getType() == 'p')
	{
		return checkIfPawnChecks(src);
	}
	else if (tmp->checkIfDiagonalNeeded(src, dest))
	{
		return !checkDiagonalClear(src, dest);
	}
	else if (tmp->checkIfHorizontalNeeded(src, dest))
	{
		return !checkHorizontalClear(src, dest);
	}
	else if (tmp->checkIfVerticalNeeded(src, dest))
	{
		return !checkVerticalClear(src, dest);
	}
	else if (tmp->getType() == 'N' || tmp->getType() == 'n')
	{
		return !tmp->checkPieceMovement(*src, *dest, _board);
	}
	return false;
}

void Game::movePiece()
{
	//removing src piece from spot
	Piece* tmp = this->_board[this->_src->getY()][this->_src->getY()];
	this->_board[this->_src->getY()][this->_src->getY()] = NULL;

	// removing dest piece from board
	size_t x = this->_dest->getX(), y = this->_dest->getY(); // pain in the ass to write getx gety all the time


	if (this->_board[y][x] != NULL) // if there is a piece at the destanation
	{
		delete this->_board[y][x]; //delete it because the piece that is there is dynamicly allocated  
								   //and would not get noticed by the destractor beacase it is not on the board
	}
	
	//putting src piece at dest
	this->_board[y][x] = tmp;
}



int Game::checkVerticalClear(Point* src, Point* dst) const
{
	int sx = src->getX(), sy = src->getY(), dx = dst->getX(), dy = dst->getY();
	bool metOne = false;

	for (int i = 0; i < 8; i++)
	{
		if (this->_board[i][sx] != NULL)
		{
			if (this->_board[i][sx]->getLoc() == src || this->_board[i][sx]->getLoc() == dst)
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
			else if(metOne == true)
			{
				return 6; //means thre is a piece inbetween them
			}
		}
	}
	return 0;
}

int Game::checkHorizontalClear(Point* src, Point* dst) const
{
	int sx = src->getX(), sy = src->getY(), dx = dst->getX(), dy = dst->getY();
	bool metOne = false;
	for (int i = 0; i < 8; i++)
	{
		if (this->_board[sy][i] != NULL)
		{
			if (this->_board[sy][i]->getLoc() == src || this->_board[sy][i]->getLoc() == dst)
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
	}
	return 0;
}

int Game::checkDiagonalClear(Point* src, Point* dst) const
{
	int sx = src->getX(), sy = src->getY(), dx = dst->getX(), dy = dst->getY();
	bool metOne = false;

	int dxSign = (dx > sx) ? 1 : -1;
	int dySign = (dy > sy) ? 1 : -1;

	int currX = sx + dxSign;
	int currY = sy + dySign;

	for (int i = 0; i < abs(dx - sx) - 1; i++) 
	{
		if (this->_board[currY][currX] != nullptr) {
			if (this->_board[currY][currX]->getLoc() == src || this->_board[currY][currX]->getLoc() == dst) 
			{
				return 0;
			}
			else 
			{
				return 6; // There is a piece in between src and dst
			}
		}
		currX += dxSign;
		currY += dySign;
	}
	return 0;
}

std::string Game::translateBoardToString()
{
	std::string result = "";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			result += (_board[i][j]) ? _board[i][j]->getType() : '#';
		}
	}
	result += (_turn) ? '1' : '0';
	return result;
}

bool Game::checkCheck()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (_board[i][j] && _board[i][j]->checkPieceOwnership() == _turn)
			{
				if (checkClearPathCheck(_board[i][j]->getLoc(), getOpponentKingLoc())) // means the path to the king is without any disturbance
				{
					return true;
				}
			}
		}
	}
	return false;
}

Point* Game::getOpponentKingLoc() const
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((this->_board[i][j] != NULL) && (this->_board[i][j]->getType() == 'k' || this->_board[i][j]->getType() == 'K')&& this->_board[i][j]->checkPieceOwnership() != this->_turn)
			{
				return this->_board[i][j]->getLoc();
			}
		}
	}
	return nullptr;
}

bool Game::checkKingEatsKing(Point* src, Point* dst) const
{
	if (src->getX() - dst->getX() == 0)
	{
		if ((src->getY() - dst->getY() == 1) || (src->getY() - dst->getY() == -1))
		{
			return false;
		}
	}
	if (src->getY() - dst->getY() == 0)
	{
		if ((src->getX() - dst->getX() == 1) || (src->getX() - dst->getX() == -1))
		{
			return false;
		}
	}
	if (((src->getY() - dst->getY() == 1) || (src->getY() - dst->getY() == -1)) && ((src->getX() - dst->getX() == 1) || (src->getX() - dst->getX() == -1)))
	{
		return false;
	}
	return true;
}

bool Game::checkIfPawnChecks(Point* dst) const
{
	int dx = dst->getX(), dy = dst->getY();
	if (this->_board[dy][dx]->checkPieceOwnership() == 0) // Pawn is white
	{
		dy -= 1;
		if (dy < 8 && dy >= 0)
		{
			dx += 1;
			if (dx < 8 && dx >=0 )
			{
				if (this->_board[dy][dx] != NULL && this->_board[dy][dx]->getType() == 'k')
				{
					return true;
				}
			}
			dx -= 2;
			if (dx < 8 && dx >= 0)
			{
				if (this->_board[dy][dx] != NULL && this->_board[dy][dx]->getType() == 'k')
				{
					return true; 
				}
			}
		}
	}
	else // pawn is black
	{
		dy += 1;
		if (dy < 8 && dy >= 0)
		{
			dx += 1;
			if (dx < 8 && dx >= 0)
			{
				if (this->_board[dy][dx] != NULL && this->_board[dy][dx]->getType() == 'K')
				{
					return true;
				}
			}
			dx -= 2;
			if (dx < 8 && dx >= 0)
			{
				if (this->_board[dy][dx] != NULL && this->_board[dy][dx]->getType() == 'K')
				{
					return true;
				}
			}
		}
	}
	return false;
}


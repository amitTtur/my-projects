#include "Piece.h"

char Piece::getType() const
{
	return this->_type;
}

int Piece::checkPieceMovement(Point& src, Point& dst, Piece* board[8][8])
{
	return 0; //TODO
}

int Piece::checkPathClear(const Game* game, Point* dst) const
{
	return 0; // TODO
}

bool Piece::checkIfVerticalNeeded( Point* src,  Point* dst) const
{
	return false;
}

bool Piece::checkIfDiagonalNeeded( Point* src,  Point* dst) const
{
	return false;
}

bool Piece::checkIfHorizontalNeeded( Point* src,  Point* dst) const
{
	return false;
}

Point* Piece::getLoc()
{
	return _location;
}

bool Piece::checkPieceOwnership()
{
	return int(_type) >= 97;
}

void Piece::changeLoc(const Point s1)
{
	this->_location->setLocation(s1.getX(), s1.getY());
}

Piece::Piece()
{
	this->_location = new Point("a1"); // set to default if empty
	this->_type = 'k';
}

Piece::Piece(Point loc, char type)
{
	this->_location = new Point("a1");
	this->_location->setLocation(loc.getX(), loc.getY());
	this->_type = type;
}

Piece::~Piece()
{
	delete this->_location;
}

std::ostream& operator<<(std::ostream& os, const Piece& v)
{
	os << "Piece type: " << v.getType() << ", Piece location:  X- " << v._location->getX() << " ,Y- " << v._location->getY() << std::endl;
	return os;
}

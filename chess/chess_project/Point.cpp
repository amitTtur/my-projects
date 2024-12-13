#include "Point.h"

Point::Point(const std::string input)
{
	setLocation(input);
}

void Point::setLocation(const std::string input)
{
	this->_x = int(input[0]) - 97;

	this->_y = 7 - (int(input[1]) - 49);
}

void Point::setLocation(size_t x, size_t y)
{
	this->_x = x;
	this->_y = y;
}

size_t Point::getX() const
{
	return this->_x;
}

size_t Point::getY() const
{
	return this->_y;
}

std::ostream& operator<<(std::ostream& os, const Point& v)
{
	os << "this object x: " << v.getX() << " ,this object y: " << v.getY() << std::endl;
	return os;
}

bool operator==(const Point& me, const Point& other)
{
	return me.getX() == other.getX() && me.getY() == other.getY();
}
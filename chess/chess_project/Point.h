#pragma once
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>

class Point
{
public:
	/// recives a string with the length of 2, the function presumes the input is correct
	/// <param name="input"> has to be a string with the length of 2, right char being a word and left char being a number ect: a5,f2,c4.
	Point(const std::string input);

	~Point() = default;

	//assumes the input is correct, first char a-h, second char 1-8. overall input length is 2.
	void setLocation(const std::string input);

	//assumes the input is correct, between 0 and 7.
	void setLocation(size_t x, size_t y);

	size_t getX() const;

	size_t getY() const;

	friend std::ostream& operator<<(std::ostream& os, const Point& v);
	friend bool operator==(const Point& me, const Point& other);

private:
	size_t _x;  // up down,, the second char of the input
	size_t _y;  // left right,, the first char of the input 
};


#endif

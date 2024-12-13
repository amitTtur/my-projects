#include "Knight.h"

int Knight::checkPieceMovement(Point& src, Point& dst, Piece* board[][8])
{
	Point tmp = Point("a1");
	size_t x = 0, y = 0;
	// octopus lower part
	x = src.getX();
	y = src.getY() + 2;
	x += 1;						//			        octopus <*~*>
	tmp.setLocation(x, y);      //
	if (tmp == dst)             //		        upper left		upper right
	{							//				     ___		___
		return 0;			//						|		|
	}							//						|		|
	x = src.getX() - 1;	       	//	   	  left up       |       |		
	tmp.setLocation(x, y);		//			|			 ______			    | right up
	if (tmp == dst)		        //			|__________ /		| __________|  
	{							//						| ~	 ~	|
		return 0;			//			___________	| ~~~~  | __________
	}							//			|			\______/			|
								//			|			|		|			| right down
	// octopus upper part		//	left down			|		|
	x = src.getX();		        //					 ___|		|___
	y = src.getY() - 2;		    //			lower left			 lower right
	x += 1;						//
	tmp.setLocation(x, y);
	if (tmp == dst)
	{
		return 0;
	}
	x = src.getX() - 1;
	tmp.setLocation(x, y);
	if (tmp == dst)
	{
		return 0;
	}
	// octopus left side
	x = src.getX() - 2;
	y = src.getY();
	y += 1;
	tmp.setLocation(x, y);
	if (tmp == dst)
	{
		return 0;
	}
	y = src.getY() - 1;
	tmp.setLocation(x, y);
	if (tmp == dst)
	{
		return 0;
	}
	// octopus right side
	x = src.getX() + 2;
	y = src.getY();
	y += 1;
	tmp.setLocation(x, y);
	if (tmp == dst)
	{
		return 0;
	}
	y = src.getY() - 1;
	tmp.setLocation(x, y);
	if (tmp == dst)
	{
		return 0;
	}

	return 6;

}

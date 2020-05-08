#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_
#include <curses.h>

class Asteroide
{
	int x;
	int y;
public:
	Asteroide(int x, int y): x(x), y(y){}
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
};

#endif
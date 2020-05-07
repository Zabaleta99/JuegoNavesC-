#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_
#include <curses.h>

class Asteroide
{
	int x;
	int y;
public:
	Asteroide(int x, int y): x(x), y(y){}
	void nuevoAsteroideVertical();
	void nuevoAsteroideHorizontal();
	void pintarAsteroideVertical(WINDOW* ventana);
	void pintarAsteroideHorizontal(WINDOW* ventana);
	int getX();
	void setX(int x);
	int getY();
	void setY();
};

#endif
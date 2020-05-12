#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_
#include <curses.h>

class Asteroide
{
	int x;
	int y;
	int tipo;
public:
	Asteroide(): x(-1), y(-1), tipo(-1){}
	Asteroide(int x, int y, int tipo): x(x), y(y), tipo(tipo){}
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	int getTipo();
	void setTipo(int tipo);
};

#endif
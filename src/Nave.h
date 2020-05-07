#ifndef NAVE_H_
#define NAVE_H_
#include <curses.h>
#include "Asteroide.h"

class Nave
{
	int x;
	int y;
	int vidas;
public:
	Nave(int x, int y, int vidas): x(x), y(y), vidas(vidas){}
	virtual void pintarNaveChoque(WINDOW* ventana);
	virtual void pintarVidas();
	virtual void pintarNave(WINDOW* ventana);
	virtual int choque(WINDOW* ventana, Asteroide* asteroide);
	int getX();
	void setX(int x);
	int getY();
	void setY();
	int getVidas();
	void setVidas();
};

#endif
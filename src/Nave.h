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
	virtual void pintarNaveChoque(WINDOW* ventana) = 0;
	virtual void pintarVidas(int anchuraTerminal) = 0;
	virtual void pintarNave(WINDOW* ventana) = 0;
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	int getVidas();
	void setVidas(int vidas);
};

#endif
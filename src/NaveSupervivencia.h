#ifndef NAVESUPERVIVENCIA_H_
#define NAVESUPERVIVENCIA_H_
#include <curses.h>
#include "Nave.h"

#include "Asteroide.h"

class NaveSupervivencia: public Nave
{
public:
	NaveSupervivencia(int x, int y, int vidas): Nave(x, y, vidas){}
	virtual void pintarNaveChoque(WINDOW* ventana);
	virtual void pintarVidas(int anchuraTerminal);
	virtual void pintarNave(WINDOW* ventana);
	virtual int choque(WINDOW* ventana, Asteroide* asteroide);
};

#endif
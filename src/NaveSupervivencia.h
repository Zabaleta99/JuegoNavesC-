#ifndef NAVESUPERVIVENCIA_H_
#define NAVESUPERVIVENCIA_H_
#include <curses.h>
#include "Nave.h"

class NaveSupervivencia: public Nave
{
public:
	NaveSupervivencia(int x, int y, int vidas): Nave(x, y, vidas){}
}

#endif
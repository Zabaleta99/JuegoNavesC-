#ifndef NAVECLASICO_H_
#define NAVECLASICO_H_
#include <curses.h>
#include "Nave.h"

class NaveClasico: public Nave
{
	int corazones;
public:
	NaveClasico(int x, int y, int vidas, int corazones): Nave(x, y, vidas), corazones(corazones){}
	int getCorazones();
	void setCorazones();
};

}

#endif
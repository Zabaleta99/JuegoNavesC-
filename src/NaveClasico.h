#ifndef NAVECLASICO_H_
#define NAVECLASICO_H_
#include <curses.h>
#include "Nave.h"

class NaveClasico: public Nave
{
	int corazones;
	public:
		NaveClasico(): Nave(-1,-1,-1){}
		NaveClasico(int x, int y, int vidas, int corazones): Nave(x, y, vidas), corazones(corazones){}
		virtual void pintarNaveChoque(WINDOW* ventana);
		virtual void pintarVidas();
		virtual void pintarNave(WINDOW* ventana);
		int getCorazones();
		void setCorazones(int corazones);
};



#endif
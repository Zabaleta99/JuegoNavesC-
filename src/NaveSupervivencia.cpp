#include "NaveSupervivencia.h"

void NaveSupervivencia::pintarNaveChoque(WINDOW* ventana)
{
	wmove(ventana, this->y, this->x); wprintw(ventana, "\"\"\"\"");
	wmove(ventana, this->y-1, this->x+1); wprintw(ventana, "\"\"");
}
void NaveSupervivencia::pintarVidas()
{
	move(2,anchuraTerminal/2+7); printw("%i",this->getVidas());
	refresh();
}
void NaveSupervivencia::pintarNave(WINDOW* ventana)
{
	wmove(ventana, this->y, this->x); wprintw(ventana, "****");
	wmove(ventana, this->y-1, this->x+1); wprintw(ventana, "**");
}
int NaveSupervivencia::choque(WINDOW* ventana, Asteroide* asteroide) //?
{
	
}
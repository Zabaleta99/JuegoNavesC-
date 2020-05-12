#include "NaveClasico.h"

void NaveClasico::pintarNaveChoque(WINDOW* ventana)
{
	wmove(ventana, this->getY(), this->getX()); wprintw(ventana, "\"\"\"\"");
	wmove(ventana, this->getY()-1, this->getX()+1); wprintw(ventana, "\"\"");
}
void NaveClasico::pintarVidas()
{
	move(2,anchuraTerminal/2+7); printw("%i",this->getVidas());
	refresh();
}
void NaveClasico::pintarNave(WINDOW* ventana)
{
	wmove(ventana, this->getY(), this->getX()); wprintw(ventana, "****");
	wmove(ventana, this->getY()-1, this->getX()+1); wprintw(ventana, "**");
}
int NaveClasico::getCorazones()
{
	return corazones;
}
void NaveClasico::setCorazones(int corazones)
{
	this->corazones = corazones;
}
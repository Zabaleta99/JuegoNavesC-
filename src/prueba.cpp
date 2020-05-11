#include "Supervivencia.h"
#include <curses.h>
#include <iostream>
using namespace std;

int main()
{
	Supervivencia* supervivencia = new Supervivencia();
	supervivencia->jugar();
	return 1;
}
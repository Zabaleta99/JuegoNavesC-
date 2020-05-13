#include "MenuMain.h"
#include <iostream>
using namespace std;

int main()
{
	initscr();
	cbreak();
    noecho();
    curs_set(0);
	MenuMain* a = new MenuMain();
	a->menuPrincipal();
	delete a;
	return 1;
}
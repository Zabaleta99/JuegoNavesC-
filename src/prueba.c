#include <stdio.h>
#include <curses.h>

int main()
{
	initscr();

	int x;
	int y;

	getmaxyx(stdscr,y,x);

	WINDOW* win = newwin(10,20,10,10);
	refresh();
	box(win,0,0);
	wrefresh(win);

	printf("%d %d\n",x,y);
	while(getchar());
	endwin();
	return 1;
}
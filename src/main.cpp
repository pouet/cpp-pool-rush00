#include <ncurses.h>
#include "Game.hpp"

int main(void)
{
	Game g;

	initscr();
	curs_set(0);
	timeout(0);
	noecho();

	g.start();

	endwin();

	return 0;
}

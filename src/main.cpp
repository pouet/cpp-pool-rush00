#include <ncurses.h>
#include <iostream>
#include "Game.hpp"

int main(void)
{
	Game g;

	initscr();
	start_color();
	curs_set(0);
	timeout(0);
	noecho();
	keypad(stdscr, TRUE);

	init_pair(C_REDBLACK, COLOR_BLUE, COLOR_BLACK);

	g.start();

	endwin();

	return 0;
}

#include <ncurses.h>
#include <iostream>
#include <ncurses.h>
#include "Game.hpp"

int main(void)
{
	Game g;

	srand(time(NULL));
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

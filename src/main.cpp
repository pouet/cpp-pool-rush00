#include <ncurses.h>
#include <iostream>
#include "Game.hpp"

int main(void)
{
	Game g;

	initscr();
	curs_set(0);
	timeout(0);
	noecho();
	keypad(stdscr, TRUE);
	start_color();

	g.start();

	endwin();

	return 0;
}

#include <iostream>
#include "ncurses.h"
#include "Game.hpp"

Game::Game(void)
	: _gameState(e_playing)
{
}

Game::~Game(void)
{
}

Game & Game::operator = (Game const & rhs)
{
}

void Game::start(void)
{
//	_init(void);

	while (!_isExiting()) {
		_ev.update();

//		player.update(_ev);
//		enemy.update(_ev);
//		gobjects.update(_ev);

		if (_ev.isPressed(K_UP))
			printw("up\n");
		if (_ev.isPressed(K_DOWN))
			printw("down\n");
		if (_ev.isPressed(K_LEFT))
			printw("left\n");
		if (_ev.isPressed(K_RIGHT))
			printw("right\n");
		if (_ev.isPressed(K_SHOOT))
			printw("shoot\n");
		refresh();
	}

//	_quit(void);
}

bool Game::_init(void)
{
}

bool Game::_quit(void)
{
}

bool Game::_isExiting(void) const
{
	return _ev.isPressed(K_ESC);
}

void Game::_mainLoop(void)
{
}

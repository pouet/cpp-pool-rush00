/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:01:52 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 19:10:38 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ncurses.h"
#include "Game.hpp"

Enemy	*Game::_enemies[_nbEnemiesTotal];

Game::Game(void)
	: _gameState(e_playing)
{
	(void)_gameState;
	for (int i = 0; i < _nbEnemiesTotal; i++)
		_enemies[i] = NULL;
}

Game::~Game(void)
{
}

Game & Game::operator = (Game const & rhs)
{
	(void)rhs;
	return *this;
}

void Game::start(void)
{
	_init();

	while (!_isExiting()) {
		_ev.update();

		if (_ev.isPressed(K_UP))
			_player.move(-1, 0);
		if (_ev.isPressed(K_DOWN))
			_player.move(1, 0);
		if (_ev.isPressed(K_LEFT))
			_player.move(0, -1);
		if (_ev.isPressed(K_RIGHT))
			_player.move(0, 1);
		if (_ev.isPressed(K_SHOOT))
			printw("shoot\n");
		_draw();
	}

	_quit();
}

bool Game::_init(void)
{
	_add(Player(20, 10, 5));
	_add(new Enemy(3, 10, 30));
	_add(new Enemy(5, 10, 31));
	_add(new Enemy(10, 30, 40));
	_add(new Enemy(20, 40, 50));
	return true;
}

void	Game::_draw(void)
{
	clear();
	_player.update();
	for (int i = 0; i < _nbEnemiesTotal; i++) {
		if (_enemies[i] != NULL)
			_enemies[i]->update();
	}
	ui.update();
	refresh();
}

bool Game::_quit(void)
{
	return true;
}

void Game::_quit(std::string msg)
{
	std::cout << msg << std::endl;
	exit(0);
}

bool Game::_isExiting(void) const
{
	return 0;//_ev.isPressed(K_ESC);		// Marche pas, si je le met le jeu quitte directement
}

void Game::_mainLoop(void)
{
}

void	Game::_add(Player player)
{
	if (player.getX() < 0 || player.getX() > MAPH ||
		player.getY() < 0 || player.getY() > MAPL)
		_quit("Player out of map");
	_player = player;
	_player.update();
}

void	Game::_add(Enemy * enemy)
{
	for (int i = 0; i < _nbEnemiesTotal; i++) {
		if (_enemies[i] == NULL) {
			_enemies[i] = enemy;
			_enemies[i]->update();
		}
	}
}

void	Game::_remove(Player * player)
{
	delete player;
}

void	Game::_remove(Enemy * enemy)
{
	for (int i = 0; i < _nbEnemiesTotal; i++) {
		if (_enemies[i] == enemy) {
		 	delete _enemies[i];
			_enemies[i] = NULL;
		}
	}
}

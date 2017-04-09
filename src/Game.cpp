/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:01:52 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 12:17:29 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "ncurses.h"
#include "Game.hpp"

Game::Game(void)
	: _gameState(e_playing), _start(std::clock()), _score(0), _time(0)
{
	for (int i = 0; i < _nbEnemiesTotal; i++)
		_enemies[i] = NULL;

	_add(Player(20, 10, 5, 3));
	_add(new Enemy(3, 10, 30));
	_add(new Enemy(5, 10, 31));
	_add(new Enemy(10, 30, 40));
	_add(new Enemy(20, 40, 50));

	_frameInit();
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
//	_init();

	while (!_isExiting()) {
		_ev.update();

		_update();

		_draw();
		_frameWait();
	}

//	_quit();
}

void	Game::_update(void)
{
	clear();

	for (int i = 0; i < _nbEnemiesTotal; i++) {
		if (_enemies[i] != NULL && _enemies[i]->isAlive() == false) {
//			printw("%p\n", _enemies[i]);
//			delete _enemies[i];
			_enemies[i] = NULL;
		}
	}

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

//	for (int i = 0; i < _nbEnemiesTotal; i++)
//		printw("%p\n", _enemies[i]);

	_player.update();
	for (int i = 0; i < _nbEnemiesTotal; i++) {
		if (_enemies[i] != NULL)
			_enemies[i]->update();
	}

	_score++;	// Score random pour test
	_time = ( std::clock() - _start ) / (double) CLOCKS_PER_SEC;

	ui.update(_player.getLifes(), _score, _time);
}

bool Game::_init(void)
{
	return true;
}

void	Game::_draw(void)
{
	refresh();
}

bool Game::_quit(void)
{
	return true;
}

void Game::_quit(std::string msg)
{
//	std::cout << msg << std::endl;
//	exit(0);
}

bool Game::_isExiting(void) const
{
	return _ev.isPressed(K_ESC);
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
//		 	delete _enemies[i];
//			_enemies[i] = NULL;
		}
	}
}

void Game::_frameWait(void)
{
	time_t now;

	while (1) {
		now = std::clock();
		double t = (double)(now - _ticks) / CLOCKS_PER_SEC;
		if (t >= FPS_DFLT)
			break;
		usleep(1);
	};
	_ticks = now;
}

void Game::_frameInit(void)
{
	_ticks = std::clock();
}

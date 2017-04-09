/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:01:52 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 16:31:48 by nchrupal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "ncurses.h"
#include "Game.hpp"

Game::Game(void)
	: _gameState(e_playing), _nbEnemiesTotal(MAX_ENEMIES),
	 _score(0), _time(0)
{
	for (int i = 0; i < _nbEnemiesTotal; i++)
		_enemies[i] = NULL;

	for (int i = 0; i < MAX_MISSILES; i++)
		_missiles[i] = NULL;

	_player = new Player(20, 5, 10, 3);

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
	while (!_isExiting()) {
		_ev.update();
		_update();

		_draw();
		_frameWait();
	}
}

void	Game::_collideAll(void)
{
	for (int i = 0; i < _nbEnemiesTotal; i++) {
		if (_enemies[i] != NULL && _enemies[i]->collide(*_player)) {
			delete _enemies[i];
			_enemies[i] = NULL;

			_player->setPv(0);
		}

		for (int j = 0; j < MAX_MISSILES; j++) {
			if (_enemies[i] != NULL && _missiles[j] != NULL && _enemies[i]->collide(*_missiles[j])) {

				_score++; // TODO: score Enemy

				delete _enemies[i];
				_enemies[i] = NULL;
				delete _missiles[j];
				_missiles[j] = NULL;
			}
		}
	}
}

void	Game::_handleEvents(void)
{
	if (_ev.isPressed(K_UP))
		_player->move(0, -1);
	if (_ev.isPressed(K_DOWN))
		_player->move(0, 1);
	if (_ev.isPressed(K_LEFT))
		_player->move(-1, 0);
	if (_ev.isPressed(K_RIGHT))
		_player->move(1, 0);
	if (_ev.isPressed(K_SHOOT))
	{
		for (int i = 0; i < MAX_MISSILES; i++)
		{
			if (_missiles[i] == NULL)
			{
				_missiles[i] = new Missile(_player->getPosX() + 2, _player->getPosY());
				break;
			}
		}
	}
}

void	Game::_update(void)
{
	clear();

	_handleEvents();
	_collideAll();

	for (int i = 0; i < _nbEnemiesTotal; i++) {
		if (_enemies[i] == NULL) {
			if (rand() % 750 == 0) {
			_enemies[i] = new Enemy(3, MAPL - 1, 1 + (rand() % (MAPH - 1)));
			}
		}
		else {
			_enemies[i]->update();
			if (_enemies[i]->getPosX() < 0) {
				_remove(_enemies[i]);
			}
		}
	}

	for (int i = 0; i < MAX_MISSILES; i++) {
		if (_missiles[i] != NULL) {
			_missiles[i]->update();
			if (_missiles[i]->getPosX() > MAPL) {
				_remove(_missiles[i]);
			}
		}
	}
}

void	Game::_draw(void)
{
	_player->draw();

	for (int i = 0; i < _nbEnemiesTotal; i++)
		if (_enemies[i] != NULL)
			_enemies[i]->draw();

	for (int i = 0; i < MAX_MISSILES; i++)
		if (_missiles[i] != NULL)
			_missiles[i]->draw();

	ui.update(_player->getLifes(), _score, _time / FPS);
	refresh();
}

bool Game::_isExiting(void) const
{
	return _ev.isPressed(K_ESC);
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

void	Game::_remove(Missile * missile)
{
	for (int i = 0; i < MAX_MISSILES; i++) {
		if (_missiles[i] == missile) {
		 	delete _missiles[i];
			_missiles[i] = NULL;
		}
	}
}

void Game::_frameWait(void)
{
	time_t now;

	while (1) {
		now = std::clock();
		double t = ((double)(now - _ticks) / CLOCKS_PER_SEC) * 1000;
		if (t >= FPS_DFLT_MSEC)
			break;
		usleep(1);
	};
	_ticks = std::clock();
	_time++;
}

void Game::_frameInit(void)
{
	_ticks = std::clock();
}

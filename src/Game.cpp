/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:01:52 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 16:10:44 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "ncurses.h"
#include "Game.hpp"

Game::Game(void)
	: _gameState(e_playing), _nbEnemiesTotal(MAX_ENEMIES), _start(std::clock()),
	 _score(0), _time(0)
{
	for (int i = 0; i < _nbEnemiesTotal; i++)
		_enemies[i] = NULL;

	for (int i = 0; i < MAX_MISSILES; i++)
		_missiles[i] = NULL;

	_player = new Player(20, 5, 10, 3);
	// _enemies[0] = new Enemy(3, 30, 10);
	// _enemies[1] = new Enemy(5, 31, 10);
	// _enemies[2] = new Enemy(10, 40, 30);
	// _enemies[3] = new Enemy(20, 50, 39);

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

void	Game::_update(void)
{
	clear();

	for (int i = 0; i < _nbEnemiesTotal; i++) {
		if (_enemies[i] != NULL && _enemies[i]->isAlive() == false) {
//			printw("%p\n", _enemies[i]);
//			delete _enemies[i];
//			_enemies[i] = NULL;
		}
	}

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

	_collideAll();

//	for (int i = 0; i < _nbEnemiesTotal; i++)
//		printw("%p\n", _enemies[i]);

	_player->draw();

	for (int i = 0; i < _nbEnemiesTotal; i++) {
		if (_enemies[i] == NULL) {
			if ((1 + (rand() % 1000)) == 1)
			{
				_enemies[i] = new Enemy(3, MAPL - 1, 1 + (rand() % (MAPH - 1)));
				_enemies[i]->draw();
			}
		}
		else
		{
			_enemies[i]->update();
			if (_enemies[i]->getPosX() < 0)
			{
				delete _enemies[i];
				_enemies[i] = NULL;
			}
			else
				_enemies[i]->draw();
		}
	}

	for (int i = 0; i < MAX_MISSILES; i++) {
		if (_missiles[i] != NULL) {
			_missiles[i]->move(1, 0);
			if (_missiles[i]->getPosX() > MAPL)
			{
				delete _missiles[i];
				_missiles[i] = NULL;
			}
			else
				_missiles[i]->draw();
		}
	}

	//_score++;	// Score random pour tester
	//_time = ( std::clock() - _start ) / (double) CLOCKS_PER_SEC;

	ui.update(_player->getLifes(), _score, _time / FPS);
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
	// TODO: pourquoi ?
	//return false;
	return _ev.isPressed(K_ESC);
}

void Game::_mainLoop(void)
{
}

//void	Game::_add(Player & player)
//{
////	if (player->getPosX() < 0 || player->getPosX() > MAPH ||
////		player->getPosY() < 0 || player->getPosY() > MAPL)
////		_quit("Player out of map");
//	_player = &player;
////	_player->update();
//}
//
//void	Game::_add(Enemy * enemy)
//{
//	for (int i = 0; i < _nbEnemiesTotal; i++) {
//		if (_enemies[i] == NULL) {
//			_enemies[i] = enemy;
//		}
//	}
//}
//
//void	Game::_remove(Player * player)
//{
//	delete player;
//}
//
//void	Game::_remove(Enemy * enemy)
//{
//	for (int i = 0; i < _nbEnemiesTotal; i++) {
//		if (_enemies[i] == enemy) {
////		 	delete _enemies[i];
////			_enemies[i] = NULL;
//		}
//	}
//}

void Game::_frameWait(void)
{
	time_t now;

	while (1) {
		now = std::clock();
		double t = ((double)(now - _ticks) / CLOCKS_PER_SEC) * 1000;
		if (t >= FPS_DFLT_MSEC)
			break;
		//usleep(1);
	};
	_ticks = std::clock();
	_time++;
}

void Game::_frameInit(void)
{
	_ticks = std::clock();
}

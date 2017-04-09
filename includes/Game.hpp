/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:01:46 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 16:31:40 by nchrupal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <ctime>
#include "Event.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Missile.hpp"
#include "UserInterface.hpp"

#define MAPL 150
#define MAPH 25

#define FPS 50
#define FPS_DFLT_SEC (1. / FPS)
#define FPS_DFLT_MSEC (FPS_DFLT_SEC * 1000)

#define MAX_ENEMIES 10
#define MAX_MISSILES 100

enum e_gameState {
	e_playing,
	e_exiting
};

class Game {
	public:
		Game(void);
		virtual ~Game(void);

		Game & operator = (Game const & rhs);

		void start(void);

	private:
		void _update(void);
		void _collideAll(void);

		void _frameInit(void);
		void _frameWait(void);

		bool _isExiting(void) const;

		void _handleEvents(void);

		void	_remove(Enemy *);
		void	_remove(Missile *);

		void	_draw(void);

		enum e_gameState _gameState;

		Event _ev;

		int const _nbEnemiesTotal;


		time_t _ticks;
		int _score;
		int _time;

		Player	* _player;
		Enemy	* _enemies[MAX_ENEMIES];
		Missile	* _missiles[MAX_MISSILES];

		UserInterface ui;

};

#endif

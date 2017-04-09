/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:01:46 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 13:40:35 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <ctime>
#include "Event.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "UserInterface.hpp"

#define MAPL 150
#define MAPH 25

#define FPS_DFLT (10. / 1000)

#define MAX_ENEMIES 10

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
		void	_remove(Enemy *);

	private:
		bool _init(void);
		bool _quit(void);
		void _quit(std::string msg);

		void	_update(void);
		void	_collideAll(void);

		void _frameInit(void);
		void _frameWait(void);

		bool _isExiting(void) const;
		void _mainLoop(void);

//		void	_add(Player &);
//		void	_add(Enemy *);
//		void	_remove(Player *);

		void	_draw(void);

		enum e_gameState _gameState;

		Event _ev;

		int const _nbEnemiesTotal;

		std::clock_t _start;
		int _score;
		int _time;

		Player	* _player;
		Enemy	* _enemies[MAX_ENEMIES];

		time_t _ticks;

		UserInterface ui;
};

#endif

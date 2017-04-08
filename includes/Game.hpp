/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:01:46 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 19:07:19 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include "Event.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "UserInterface.hpp"

#define MAPL 100
#define MAPH 25

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
		static void	_remove(Enemy *);

	private:
		bool _init(void);
		bool _quit(void);
		void _quit(std::string msg);

		bool _isExiting(void) const;
		void _mainLoop(void);

		void	_add(Player);
		void	_add(Enemy *);
		void	_remove(Player *);

		void	_draw(void);

		enum e_gameState _gameState;

		Event _ev;

		static int const _nbEnemiesTotal = 10;

		Player	_player;
		static Enemy	*_enemies[_nbEnemiesTotal];

		UserInterface ui;
};

#endif

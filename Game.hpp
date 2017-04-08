#ifndef GAME_HPP
#define GAME_HPP

#include "Event.hpp"

enum e_gameState {
	e_playing,
	e_exiting
};

class Game {
	public:
		Game(void);
		~Game(void);

		Game & operator = (Game const & rhs);

		void start(void);

	private:
		bool _init(void);
		bool _quit(void);

		bool _isExiting(void) const;
		void _mainLoop(void);

		enum e_gameState _gameState;

		Event _ev;
};

#endif

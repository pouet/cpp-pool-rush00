#ifndef EVENT_HPP
#define EVENT_HPP

enum e_keys {
	K_UP,
	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_SHOOT,
	K_ESC,
	K_NKEYS
};

class Event {
	public:
		Event(void);
		~Event(void);

		Event & operator = (Event const & rhs);

		void update(void);

		bool isPressed(int key) const;

	private:
		bool _keys[K_NKEYS];
};

#endif

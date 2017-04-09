/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Event.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:01:48 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 12:10:57 by nchrupal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "Event.hpp"

Event::Event(void)
{
}

Event::~Event(void)
{
}

Event & Event::operator = (Event const & rhs)
{
	(void)rhs;
	return *this;
}

void Event::update(void)
{
	int key;

	for (int i = 0; i < K_NKEYS; i++)
		_keys[i] = false;

	while (1) {
		key = getch();

		if (key == ERR)
			break;

		switch (key) {
			case 'w':
				_keys[K_UP] = true;
				break;
			case 's':
				_keys[K_DOWN] = true;
				break;
			case 'd':
				_keys[K_RIGHT] = true;
				break;
			case 'a':
				_keys[K_LEFT] = true;
				break;
			case ' ':
				_keys[K_SHOOT] = true;
				break;
			case '\033':
				_keys[K_ESC] = true;
				break;
			default:
				break;
		}
	}
}

bool Event::isPressed(int key) const
{
	if (key < 0 || key >= K_NKEYS)
		return false;
	else
		return _keys[key];
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 19:10:16 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserInterface.hpp"
#include "Game.hpp"

UserInterface::UserInterface(void)
{
}

UserInterface::UserInterface(UserInterface const & src)
{
	*this = src;
	return;
}

UserInterface::~UserInterface(void)
{
}

void	UserInterface::update(void) const
{
	for (int y = 0; y <= MAPL; y++)
	{
		mvprintw(0, y, "#");
		mvprintw(MAPH, y, "#");
	}
	for (int x = 0; x <= MAPH; x++)
	{
		mvprintw(x, 0, "#");
		mvprintw(x, MAPL, "#");
	}
}

UserInterface &	UserInterface::operator=( UserInterface const & rhs )
{
	(void)rhs;
	return *this;
}

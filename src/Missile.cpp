/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 14:24:12 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.hpp"
#include "Game.hpp"

Missile::Missile(void)
	: AHitBox(1, 1, 1, 1)
{
}

Missile::Missile(int x, int y)
	: AHitBox(x, y, 1, 1)
{
}

Missile::Missile(Missile const & src)
{
	*this = src;
	return;
}

Missile::~Missile(void)
{
}

Missile &	Missile::operator=( Missile const & rhs )
{
	return *this;
}
